#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

//global_courrent_user global_user;

mkdirCmd::mkdirCmd(){}

void mkdirCmd::assignParameters(parameter* directives[100], int size){
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-p") == 0){
                this->p = directives[i]->stringValue;
            }
        }
    }
}

void mkdirCmd::execute(){
    // OBTENGO LA INFORMACION DE LA PARTICION 
    pnodo element = global_list.getElement(global_user.id_partition);

    SuperBloque superbloque;

    FILE *file = fopen(element->path_disk.c_str(),"rb+");

    if(file != NULL){
        string current_date = get_now();// LEO EL SUPERBLOQUE DE LA PARTICION

        // OBTENGO TODAS LAS CARPETAS PADRES DEL ARCHIVO
        vector<string> routes = split(this->path,'/');
        int number_routes = routes.size();
        routes.at(0) = "/";
        // NOMBRE DEL ARCHIVO
        string file_name = routes.at(routes.size() - 1).c_str();

        fseek(file,element->start + sizeof(Partition),SEEK_SET);
        fread(&superbloque,sizeof(SuperBloque),1,file);

        // CREACION DE ARRAYS PARA GUARDAR BITMAPS
        char bitinodes[superbloque.inodes_count];
        char bitblocks[superbloque.blocks_count];
        fseek(file,superbloque.bm_inode_start,SEEK_SET);
        fread(&bitinodes,sizeof(bitinodes),1,file);
        fseek(file,superbloque.bm_block_start,SEEK_SET);
        fread(&bitblocks,sizeof(bitblocks),1,file);

        //CREA LA RAIZ
        if(number_routes == 1){
            InodeTable root_inode;

            root_inode.uid = (int)stoi(global_user.uid);
            root_inode.gid = (int)stoi(global_user.gid);
            root_inode.size = 0;
            strcpy(root_inode.atime,current_date.c_str());
            strcpy(root_inode.ctime,current_date.c_str());
            strcpy(root_inode.mtime,current_date.c_str());

            // INICIALIZO LOS APUNTADORES 
            for(int i=0; i<16; i++){ 
                root_inode.block[i] = -1;
            }

            root_inode.type = '0';
            root_inode.perm = 664;
            
            // APUNTO AL PRIMER BLOQUE CARPETA
            root_inode.block[0] = 0;

            // CREO EL PRIMER BLOQUE DE CARPETA
            FileBlock block;
            for(int s=0; s<4;s++){
                block.content[s].inodo = -1;
                strcpy(block.content[s].name,"");
            }
            strcpy(block.content[0].name,".");
            strcpy(block.content[1].name,"..");
            block.content[0].inodo = 0;
            block.content[1].inodo = 0;

            // MODIFICO LOS BITMAPS
            bitinodes[0] = '1';
            bitblocks[0] = '1';
            
            // MODIFICO ATRIBUTOS DEL SUPERBLOQUE
            superbloque.first_inode = 1;
            superbloque.first_block = 1;
            superbloque.free_inodes_count -=1;
            superbloque.free_blocks_count -=1;

            // ESCRIBO BLOQUES
            fseek(file,superbloque.block_start,SEEK_SET);
            fwrite(&block,sizeof(FileBlock),1,file);
            // ESCRIBO INODOS
            fseek(file,superbloque.inode_start,SEEK_SET);
            fwrite(&root_inode,sizeof(InodeTable),1,file);

            // REESCRIBO SUPERBLOQUE
            fseek(file,element->start + sizeof(Partition),SEEK_SET);
            fwrite(&superbloque,sizeof(SuperBloque),1,file);

            // REESCRIBO BITMAPS
            fseek(file,superbloque.bm_inode_start,SEEK_SET);
            fwrite(&bitinodes,sizeof(bitinodes),1,file);
            fseek(file,superbloque.bm_block_start,SEEK_SET);
            fwrite(&bitblocks,sizeof(bitblocks),1,file);
            fclose(file);
        }else{
            InodeTable temp_inode;
            int index_temp_inode;
            // LEO EL PRIMER INODO
            fseek(file,superbloque.inode_start,SEEK_SET);
            fread(&temp_inode,sizeof(InodeTable),1,file);
            
            bool exist_route = false;
            // VECTOR PARRA GUARDAR LAS RUTAS QUE FALTAN POR CREARSE
            vector<string> remaining_routes = routes;

            // RECORRE RUTA
            for(int path_index=0; path_index<routes.size();path_index++){
                bool exist_path = false;
                // RECORRE PUNTEROS DEl INODO
                for(int pointerIndex = 0 ; pointerIndex < 16 ; pointerIndex++){
                    //cout << temp_inode.block[pointerIndex] << " " << temp_inode.type << endl;
                    // RECORRO SOLO LOS BLOQUES DE LOS INODOS DE TIPO CARPETA
                    if(temp_inode.block[pointerIndex] != -1 && temp_inode.type == '0'){
                        FileBlock file_block;
                        index_temp_inode = temp_inode.block[pointerIndex]; // GUARDO EL INDICE DEL INDICE TEMP
                        fseek(file,superbloque.block_start + (temp_inode.block[pointerIndex]*sizeof(FileBlock)),SEEK_SET);
                        fread(&file_block,sizeof(FileBlock),1,file);
                        // RECORRE LOS PUNTEROS DE LOS BLOQUES
                        for(int blockIndex=0; blockIndex < 4; blockIndex++){
                            if(file_block.content[blockIndex].inodo != -1){
                                if(file_block.content[blockIndex].name == routes[path_index]){
                                    // ELIMINO LAS RUTAS QUE YA ESTAN CREADAS PARA QUE QUEDEN SOLO LAS RESTANTES
                                    auto elem_to_remove = remaining_routes.begin();
                                    if(remaining_routes.size() == routes.size()){
                                        remaining_routes.erase(elem_to_remove);
                                        remaining_routes.erase(elem_to_remove);
                                    }else{
                                        remaining_routes.erase(elem_to_remove);
                                    }
                                    // RECORRO EL ARBOL
                                    fseek(file,superbloque.inode_start + (file_block.content[blockIndex].inodo*sizeof(InodeTable)),SEEK_SET);
                                    fread(&temp_inode,sizeof(InodeTable),1,file);
                                    exist_route = true;
                                    exist_path = true; // POSIBLE CAMBIO
                                }
                            }
                        }
                    }
                }
                if(!exist_path){
                    exist_route = false;
                }
            }
            //cout << exist_route << " " << this->path << endl;
            if(!exist_route){
                /*cout << "----------------" << endl;
                for(int i=0; i<remaining_routes.size(); i++){
                    cout << remaining_routes[i] << endl;
                }*/
                if(this->p != ""){
                    // SI SOLAMENTE ESTA CREADA LA RAIZ LA ELIMINO DE LAS RUTAS RESTANTES
                    if(remaining_routes.size() == routes.size()){
                        auto elem_to_remove = remaining_routes.begin();
                        remaining_routes.erase(elem_to_remove);
                    }
                    // CREO LAS RUTAS RESTANTES
                    // RECORRO LAS RUTAS RESTANTES
                    for(int route_index=0; route_index<remaining_routes.size();route_index++){
                        for(int pointer=0; pointer<16; pointer++){ // RECORRO LOS PUNTERS DEL INODO ACTUAL
                            bool has_space = false;
                            int indice_encontrado; //GUARDA EL INDICE DEL BLOQUE QUE ESTE DISPONIBLE
                            FileBlock actual_block;
                            // VERIFICA QUE SEA UN PUNTERO SIN UTILIZAR
                            if(temp_inode.block[pointer] != -1){
                                //cout << temp_inode.block[pointer] << " " << remaining_routes[route_index] << " " << pointer << endl;
                                fseek(file,superbloque.block_start + temp_inode.block[pointer]*sizeof(FileBlock), SEEK_SET);
                                fread(&actual_block,sizeof(FileBlock),1,file);
                                for(int block_index=0; block_index<4; block_index++){ // RECORRO EL BLOQUE
                                    // VALIDO QUE EXISTE UN PUNTERO LIBRE
                                    if(actual_block.content[block_index].inodo == -1){
                                        //cout << temp_inode.block[pointer] << remaining_routes[route_index] << block_index << endl;
                                        indice_encontrado = block_index; // OBTENGO EL INDICE DISPONIBLE DEL BLOQUE
                                        has_space = true;
                                        break;
                                    }
                                    has_space = false;
                                }
                            }else{
                                // SI ES -1 ENTONCES LLEGO AL PRIMER PUNTERO DISPONIBLE
                                // ENTONCES SE CREA UN NUEVO BLOQUE Y SE APUNTA AL PUNTERO 
                                // ACTUAL EL CUAL APUNTA A UN NUEVO INODO
                                int free_block;
                                int free_inode;
                                FileBlock real_block;
                                // LEO BITMPAP DE BLOQUES
                                fseek(file,superbloque.bm_block_start,SEEK_SET);
                                fread(&bitblocks,sizeof(bitblocks),1,file);
                                // LEO BITMAP DE INODOS
                                fseek(file,superbloque.bm_inode_start,SEEK_SET);
                                fread(&bitinodes,sizeof(bitinodes),1,file);
                                //CALCULO LA POSICION DEL BLOQUE 
                                for(int bit_index=0; bit_index<sizeof(bitblocks); bit_index++){
                                    if(bitblocks[bit_index] == '0'){
                                        free_block = bit_index; // GUARDO EL NUMERO DE BLOQUE LIBRE
                                        break;
                                    }
                                }
                                // INICIALIZO LOS PUNTEROS Y NOMBRES DEL BLOQUE
                                for(int i_block=0; i_block<4; i_block++){
                                    real_block.content[i_block].inodo = -1;
                                    strcpy(real_block.content[i_block].name,"");
                                }
                                int block_pointer = 0;
                                // SI ES EL PRIMER APUNTADOR DEL INODO LOS PRIMEROS DOS REGISTROS APUNTAN AL PADREA
                                if(pointer == 0){
                                    real_block.content[0].inodo = index_temp_inode;
                                    strcpy(real_block.content[0].name,".");
                                    real_block.content[1].inodo = index_temp_inode;
                                    strcpy(real_block.content[1].name,"..");
                                    block_pointer = 2;
                                }
                                // APUNTO EL INODO ACTUAL AL BLOQUE 
                                temp_inode.block[pointer] = free_block;
                                
                                //CALCULO LA POSICION DEL INODO LIBRE
                                for(int bit_index=0; bit_index<sizeof(bitinodes); bit_index++){
                                    if(bitinodes[bit_index] == '0'){
                                        free_inode = bit_index; // GUARDO EL NUMERO DE BLOQUE LIBRE
                                        break;
                                    }
                                }
                                // CREO EL INODO
                                InodeTable newInode;
                                newInode.uid = (int)stoi(global_user.uid);
                                newInode.gid = (int)stoi(global_user.gid);
                                newInode.size = 0;
                                strcpy(newInode.atime,current_date.c_str());
                                strcpy(newInode.ctime,current_date.c_str());
                                strcpy(newInode.mtime,current_date.c_str());
                                // INICIALIZO LOS APUNTADORES 
                                for(int i=0; i<16; i++){
                                    newInode.block[i] = -1;
                                }
                                newInode.type = '0';
                                newInode.perm = 664;
                                // MODIFICO LOS BITMAPS Y CONTADORES
                                bitinodes[free_inode] = '1';
                                bitblocks[free_block] = '1';
                                superbloque.free_inodes_count -=1;
                                superbloque.free_blocks_count -=1;
                                // APUNTO EL PRIMER PUNTERO DEL BLOQUE AL INODO CREADO
                                // Y GUARDO EL NOMBRE DEL NUEVO DIRECTORIO CREADO
                                real_block.content[block_pointer].inodo = free_inode;
                                strcpy(real_block.content[block_pointer].name,remaining_routes[route_index].c_str());

                                
                                // ESCRIBO EL INODO NUEVO
                                fseek(file,superbloque.inode_start + free_inode * sizeof(InodeTable),SEEK_SET);
                                fwrite(&newInode,sizeof(InodeTable),1,file);
                                fseek(file,superbloque.inode_start + index_temp_inode * sizeof(InodeTable),SEEK_SET);
                                fwrite(&temp_inode,sizeof(InodeTable),1,file);
                                // ESCRIBO EL BLOQUE
                                fseek(file,superbloque.block_start + free_block * sizeof(FileBlock),SEEK_SET);
                                fwrite(&real_block,sizeof(FileBlock),1,file);

                                // REESCRIBO SUPERBLOQUE
                                fseek(file,element->start + sizeof(Partition),SEEK_SET);
                                fwrite(&superbloque,sizeof(SuperBloque),1,file);

                                // REESCRIBO BITMAPS
                                fseek(file,superbloque.bm_inode_start,SEEK_SET);
                                fwrite(&bitinodes,sizeof(bitinodes),1,file);
                                fseek(file,superbloque.bm_block_start,SEEK_SET);
                                fwrite(&bitblocks,sizeof(bitblocks),1,file);
                                // RECORRO EL ARBOL
                                temp_inode = newInode;
                                index_temp_inode = free_inode; // GUARDO EL INDICE DEL INDICE TEMP
                                break;
                            }
                            // VERIFICA QUE HAYA ESPACIO Y DETIENE LA BUSQUEDA DE BLOQUES
                            if(has_space){
                                int free_inode;
                                // BUSCA EL INODO LIBRE EN EL BITMAP DE INODOS
                                fseek(file,superbloque.bm_inode_start,SEEK_SET);
                                fread(&bitinodes,sizeof(bitinodes),1,file);
                                for(int inode_i=0; inode_i<sizeof(bitinodes); inode_i++){
                                    if(bitinodes[inode_i] == '0'){
                                        free_inode = inode_i;
                                        break;
                                    }
                                }
                                // CREO EL INODO
                                InodeTable newInode;
                                newInode.uid = (int)stoi(global_user.uid);
                                newInode.gid = (int)stoi(global_user.gid);
                                newInode.size = 0;
                                strcpy(newInode.atime,current_date.c_str());
                                strcpy(newInode.ctime,current_date.c_str());
                                strcpy(newInode.mtime,current_date.c_str());
                                // INICIALIZO LOS APUNTADORES 
                                for(int i=0; i<16; i++){ 
                                    newInode.block[i] = -1;
                                }
                                newInode.type = '0';
                                newInode.perm = 664;
                                // MODIFICO LOS BITMAPS
                                bitinodes[free_inode] = '1';
                                // MODIFICO ATRIBUTOS DEL SUPERBLOQUE
                                superbloque.free_inodes_count -=1;
                                // APUNTO EL APUNTADOR DEL BLOQUE DISPONIBLE AL NUEVO INODO
                                // Y GUARDO EL NOMBRE DEL DIRECTORIO ACTUAL
                                actual_block.content[indice_encontrado].inodo = free_inode;
                                strcpy(actual_block.content[indice_encontrado].name,remaining_routes[route_index].c_str());

                                // ESCRIBO EL INODO
                                fseek(file,superbloque.inode_start + free_inode * sizeof(InodeTable),SEEK_SET);
                                fwrite(&newInode,sizeof(InodeTable),1,file);
                                // ESCRIBO EL BLOQUE
                                //fseek(file,superbloque.block_start + pointer * sizeof(FileBlock),SEEK_SET);
                                fseek(file,superbloque.block_start + temp_inode.block[pointer] * sizeof(FileBlock),SEEK_SET);
                                fwrite(&actual_block,sizeof(FileBlock),1,file);

                                // REESCRIBO SUPERBLOQUE
                                fseek(file,element->start + sizeof(Partition),SEEK_SET);
                                fwrite(&superbloque,sizeof(SuperBloque),1,file);

                                // REESCRIBO BITMAPS
                                fseek(file,superbloque.bm_inode_start,SEEK_SET);
                                fwrite(&bitinodes,sizeof(bitinodes),1,file);
                                fseek(file,superbloque.bm_block_start,SEEK_SET);
                                fwrite(&bitblocks,sizeof(bitblocks),1,file);
                                // RECORRO EL ARBOL
                                temp_inode = newInode;
                                index_temp_inode = free_inode; // GUARDO EL INDICE DEL INDICE TEMP
                                break;
                            }else{
                                continue;
                            }
                        }
                    }
                    fseek(file,superbloque.bm_inode_start,SEEK_SET);
                    fread(&bitinodes,sizeof(bitinodes),1,file);
                    fseek(file,superbloque.bm_block_start,SEEK_SET);
                    fread(&bitblocks,sizeof(bitblocks),1,file);

                    /*for(int i=0; i<sizeof(bitinodes); i++){
                        InodeTable each_inode;
                        fseek(file,superbloque.inode_start + i*sizeof(InodeTable),SEEK_SET);
                        fread(&each_inode,sizeof(InodeTable),1,file);
                        if(bitinodes[i] != '0'){
                            for(int j=0; j<15; j++){
                                if(each_inode.block[j]!=-1){
                                    FileBlock temp_block;
                                    fseek(file,superbloque.block_start + each_inode.block[j]*sizeof(InodeTable),SEEK_SET);
                                    fread(&temp_block,sizeof(InodeTable),1,file);
                                    for(int k=0; k<4; k++){
                                        cout << temp_block.content[k].inodo << endl;
                                    }
                                }
                            }
                        }
                    }*/

                   /*for(int i=0; i<sizeof(bitblocks); i++){
                        
                        FileBlock temp_block;
                        fseek(file,superbloque.block_start + i*sizeof(FileBlock),SEEK_SET);
                        fread(&temp_block,sizeof(FileBlock),1,file);
                        //cout << bitblocks[i] << endl;
                        if(bitblocks[i]!='0'){
                            for(int j=0; j<4; j++){
                                cout << temp_block.content[j].name << " " << temp_block.content[j].inodo << " ruta:" << this->path << " " << i << endl;
                            }
                        }
                    }*/

                    fclose(file);
                }else{
                    cout << "Error: la ruta no existe, para crearla usa el parámetro -p" << endl;
                    return;
                }
            }

        }

    }

}
