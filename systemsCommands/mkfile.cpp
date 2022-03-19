#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

mkfileCmd::mkfileCmd(){
    this->size = 0;
}

void mkfileCmd::assignParameters(parameter* directives[100], int size){
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-r") == 0){
                this->r = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-size") == 0){
                this->size = directives[i]->intValue;
            }else if(strcmp(directives[i]->name,(char*)"-cont") == 0){
                this->cont = directives[i]->stringValue;
            }
        }
    }
}

void mkfileCmd::execute(){

    if(global_user.logged == -1){
        cout << "Error: Para utilizar mkfile necesitas estar logueado" << endl;
        return;
    }

    // OBTENGO LA INFORMACION DE LA PARTICION 
    pnodo element = global_list.getElement(global_user.id_partition);

    SuperBloque superbloque;

    FILE *file = fopen(element->path_disk.c_str(),"rb+");

    if(file != NULL){
        if(this->path != ""){
            // GUARDO EL NOMBRE DEL ARCHIVO
            string archive_name = this->path.substr(this->path.find_last_of("/\\")+1,this->path.length());

            // OBTENGO TODAS LAS CARPETAS PADRES ANTES DEL ARCHIVO
            string parent_path = this->path.substr(0,this->path.find_last_of("/\\"));

            string current_date = get_now();// LEO EL SUPERBLOQUE DE LA PARTICION
            //vector<string> real_route = split(this->path,'/');
            //cout << real_route.size()<< endl;
            // OBTENGO TODAS LAS CARPETAS PADRES DEL ARCHIVO
            vector<string> routes = split(parent_path,'/');

            bool saltar_busqueda = false;
            bool exist_route = false;

            // SI EL TAMANIO DE LAS RUTAS SEPARADAS POR / ES 
            // CERO QUIERE DECIR QUE EL ARCHIVO SE DEBE CREAR EN LA RAIZ
            if(routes.size() == 0 && this->path[0]=='/'){
                //saltar_busqueda = true;
                exist_route = true;
            }else{
                int number_routes = routes.size();
                routes.at(0) = "/";
            }

            /*for(int i=0; i<routes.size(); i++){
                cout << routes[i] << endl;
            }*/

            fseek(file,element->start + sizeof(Partition),SEEK_SET);
            fread(&superbloque,sizeof(SuperBloque),1,file);

            // CREACION DE ARRAYS PARA GUARDAR BITMAPS
            char bitinodes[superbloque.inodes_count];
            char bitblocks[superbloque.blocks_count];
            fseek(file,superbloque.bm_inode_start,SEEK_SET);
            fread(&bitinodes,sizeof(bitinodes),1,file);
            fseek(file,superbloque.bm_block_start,SEEK_SET);
            fread(&bitblocks,sizeof(bitblocks),1,file);

            // VERIFICA QUE EXISTAN LAS CARPETAS ANTES DEL ARCHIVO

            InodeTable temp_inode;
            int index_temp_inode;
            // LEO EL PRIMER INODO
            fseek(file,superbloque.inode_start,SEEK_SET);
            fread(&temp_inode,sizeof(InodeTable),1,file);

            //cout << temp_inode.block[0] << superbloque.inode_start << endl;
            
            //bool exist_route = false;
            // VECTOR PARRA GUARDAR LAS RUTAS QUE FALTAN POR CREARSE
            vector<string> remaining_routes = routes;
            //if(saltar_busqueda){
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
                                        index_temp_inode = file_block.content[blockIndex].inodo; // GUARDO EL NUEVO INDICE
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
            //} 
            //cout << "estoooo " << this->path << exist_route << endl;
            //cout << index_temp_inode << endl;
            //index_temp_inode = 3;
            /*for(int i=0; i<sizeof(remaining_routes);i++){
                cout << remaining_routes[i] << endl;
            }*/
            // VERIFICACION DE EXISTENCIAS DE RUTAS
            if(!exist_route){
                // CREA LAS RUTAS FALTANTES
                if(this->r != ""){
                    // CREA LAS RUTAS
                    mkdirCmd *c = new mkdirCmd();
                    c->path = parent_path;
                    c->p = "-p";
                    c->execute();
                    // VUELVE A EJECUTAR EL mkfile
                    mkfileCmd *d = new mkfileCmd();
                    d->anyText = this->anyText;
                    d->cont = this->cont;
                    d->path = this->path;
                    d->r = this->r;
                    d->size = this->size;
                    d->execute();
                    return;
                }else{
                    cout << "Error: la ruta del mkfile no existe intenta utilizando el parametro -r" << endl;
                    return;
                }

            }else{
                // BUSCO EL PUNTERO LIBRE DEL INODO
                //cout << temp_inode.block[0] << "  " << index_temp_inode << endl;
                for(int pointer_index=0; pointer_index<15; pointer_index++){
                    bool has_space = false;
                    int indice_encontrado; //GUARDA EL INDICE DEL BLOQUE QUE ESTE DISPONIBLE
                    FileBlock actual_block;
                    // VERIFICA QUE SEA UN PUNTERO SIN UTILIZAR
                    if(temp_inode.block[pointer_index] != -1){
                        fseek(file,superbloque.block_start + temp_inode.block[pointer_index]*sizeof(FileBlock), SEEK_SET);
                        fread(&actual_block,sizeof(FileBlock),1,file);
                        for(int block_index=0; block_index<4; block_index++){ // RECORRO EL BLOQUE
                            // VALIDO QUE EXISTE UN PUNTERO LIBRE
                            if(actual_block.content[block_index].inodo == -1){
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
                        if(pointer_index == 0){
                            real_block.content[0].inodo = index_temp_inode;
                            strcpy(real_block.content[0].name,".");
                            real_block.content[1].inodo = index_temp_inode;
                            strcpy(real_block.content[1].name,"..");
                            block_pointer = 2;
                        }
                        // APUNTO EL INODO ACTUAL AL BLOQUE 
                        temp_inode.block[pointer_index] = free_block;
                        
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
                        newInode.type = '1';
                        newInode.perm = 664;
                        // MODIFICO LOS BITMAPS Y CONTADORES
                        bitinodes[free_inode] = '1';
                        bitblocks[free_block] = '1';
                        superbloque.free_inodes_count -=1;
                        superbloque.free_blocks_count -=1;
                        // APUNTO EL PRIMER PUNTERO DEL BLOQUE AL INODO CREADO
                        // Y GUARDO EL NOMBRE DEL NUEVO DIRECTORIO CREADO
                        real_block.content[block_pointer].inodo = free_inode;
                        strcpy(real_block.content[block_pointer].name,archive_name.c_str());
                        
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
                        newInode.type = '1';
                        newInode.perm = 664;
                        // MODIFICO LOS BITMAPS
                        bitinodes[free_inode] = '1';
                        // MODIFICO ATRIBUTOS DEL SUPERBLOQUE
                        superbloque.free_inodes_count -=1;
                        // APUNTO EL APUNTADOR DEL BLOQUE DISPONIBLE AL NUEVO INODO
                        // Y GUARDO EL NOMBRE DEL DIRECTORIO ACTUAL
                        actual_block.content[indice_encontrado].inodo = free_inode;
                        strcpy(actual_block.content[indice_encontrado].name,archive_name.c_str());

                        // ESCRIBO EL INODO
                        fseek(file,superbloque.inode_start + free_inode * sizeof(InodeTable),SEEK_SET);
                        fwrite(&newInode,sizeof(InodeTable),1,file);
                        // ESCRIBO EL BLOQUE
                        //fseek(file,superbloque.block_start + pointer * sizeof(FileBlock),SEEK_SET);
                        fseek(file,superbloque.block_start + temp_inode.block[pointer_index] * sizeof(FileBlock),SEEK_SET);
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

            int content_size=0; // VARIABLE PARA SABER EL TAMANIO DEL CONTENIDO
            string content = ""; // VARIABLE PARA GUARDAR EL CONTENIDO
            // SI HAY CONTENIDO CALCULO SU TAMANIO
            if(this->cont != ""){
                string nombreArchivo = this->cont;
                ifstream archivo(nombreArchivo.c_str());
                string linea;
                // Obtener línea de archivo, y almacenar contenido en "linea"
                while (getline(archivo, linea)) {
                    content += linea;
                }
                content_size = content.length();
            }

            // SI LE PASO TEXTO POR APARTE HACE EL CALCULO
            if(this->anyText != ""){
                content = this->anyText;
                content_size = this->anyText.length();
            }

            if (this->size < 0) {
                cout << "Error: el parametro size en mkfile no puede ser negativo" << endl;
                return;
            }
            //cout << index_temp_inode << endl;
            // ESCRIBO EN EL ARCHIVO SEGUN EL TAMANIO INDICADO
            if(this->size >= 0 || content_size >= 0){
                temp_inode.size = this->size >= content_size ? this->size : content_size;

                int number_blocks = temp_inode.size > 64 ? temp_inode.size / 64 : 1; 

                if(temp_inode.size == 0){ number_blocks = 0;}

                if(temp_inode.size % 64 != 0 && temp_inode.size > 64){
                    number_blocks += 1;
                }

                //cout << number_blocks << endl;
                //cout << number_blocks << this->path  << endl;
                for(int block_index=0; block_index<number_blocks; block_index++){
                    int free_block_index;
                    // BUSCO EL BLOQUE LIBRE EN EL BITMAPS DE BLOQUES
                    for(int bit=0; bit<sizeof(bitblocks); bit++){
                        if(bitblocks[bit] == '0'){
                            free_block_index = bit;
                            break;
                        }
                    }

                    // ESCRIBO EN EL BLOQUE DE ARCHIVO LOS CARACTERES DEL 1 AL 9 
                    // Y EL CONTENIDO SI ES QUE TIENE EN CONT O ANYTEXT
                    ArchiveBlock bloqueArchivo;
                    temp_inode.block[block_index] = free_block_index; // APUNTO EL INODO AL BLOQUE
                    int number=0;
                    for(int caracter_index=0; caracter_index<64; caracter_index++){
                        bloqueArchivo.content[caracter_index] = number + '0';
                        // SI ES IGUAL A 10 VUELVE A 0 Y SI NO AUMENTA
                        number = number == 9 ? 0 : number + 1;

                        if(content.length() != 0){
                            bloqueArchivo.content[caracter_index] = content[0];
                            content.erase(0,1);
                        }

                    }

                    superbloque.free_blocks_count -= 1;
                    bitblocks[free_block_index] = '1';

                    // REESCRIBO EL SUPERBLOQUE EN LA PARTICION
                    fseek(file,element->start + sizeof(Partition),SEEK_SET);
                    fwrite(&superbloque,sizeof(SuperBloque),1,file);
                    
                    // REESCRIBO EL INODO TEMPORAL QUE ES EL DE ARCHIVO
                    fseek(file,superbloque.inode_start + (index_temp_inode*sizeof(InodeTable)),SEEK_SET);
                    fwrite(&temp_inode,sizeof(InodeTable),1,file);

                    // ESCRIBO EL BLOQUE DE ARCHIVO EN EL DISCO
                    fseek(file,(superbloque.block_start + (free_block_index*sizeof(ArchiveBlock))),SEEK_SET);
                    fwrite(&bloqueArchivo,sizeof(ArchiveBlock),1,file);

                    // REESCRIBO EL BITMAP DE BLOQUES
                    fseek(file,superbloque.bm_block_start,SEEK_SET);
                    fwrite(&bitblocks,sizeof(bitblocks),1,file);
                }

            }

            
        InodeTable ver;
        /*for (int i=0; i<sizeof(bitinodes);i++){
            if(bitinodes[i] != '0'){
                fseek(file,superbloque.inode_start + i*sizeof(InodeTable), SEEK_SET);
                fread(&ver,sizeof(InodeTable),1,file);
                cout << ver.atime << endl;
            }
        }*/

        fclose(file);

        }else{
            cout << "Error: el parametro path es obligatorio en el comando mkfile" << endl;
        }
    }else{
        cout << "Error: el disco no existe" << endl;
    }
}
