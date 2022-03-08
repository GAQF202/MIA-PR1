#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"
#include "../estructures/simpleList.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

mkfsCmd::mkfsCmd(){}

void mkfsCmd::assignParameters(parameter* directives[100], int size){
    for(int i = 0; i<size; i++){
        if(strcmp(directives[i]->name,(char*)"-id") == 0){
            this->id = toMayus(directives[i]->stringValue);
        }else if(strcmp(directives[i]->name,(char*)"-type") == 0){
            this->type = toMayus(directives[i]->stringValue);
        }else if(strcmp(directives[i]->name,(char*)"-fs") == 0){
            this->fs = toMayus(directives[i]->stringValue);
        }
    }
}

void mkfsCmd::execute(){
    if(this->id != ""){
        pnodo partition_found;

        partition_found = global_list.getElement(this->id);
        if(partition_found){
            Partition real_partition;

            FILE *file = fopen(partition_found->path_disk.c_str(),"rb+");
            // VERIFICA QUE EL DISCO SI EXISTA EN LA RUTA ESPECIFICADA
            if(!file){
                cout << "Error el disco indicado no existe en la ruta:" << partition_found->path_disk << endl;
                fclose(file);
                return;
            }
        
            fseek(file,partition_found->start,SEEK_SET);
            fread(&real_partition,sizeof(Partition),1,file);

            // SI ES FAST BORRO TODO EL ESPACIO DE LA PARTICION CON '\0'
            if(this->type == "FAST"){
                char blank_space = '\0';
                // LLENO CON CEROS TODAS LAS POSICIONES QUE OCUPA EN EL ARCHIVO LA PARTICION
                for(int i=(real_partition.start+sizeof(Partition)); i<(real_partition.start+real_partition.size);i++){
                    fseek(file,i,SEEK_SET);
                    fwrite(&blank_space,sizeof(blank_space),1,file);
                }
            }
            int n = ((real_partition.size -sizeof(SuperBloque)) / 
                    (4 + sizeof(Journaling) + sizeof(InodeTable) + 3 * sizeof(FileBlock)));
            SuperBloque super_bloque; // STRUCT PARA EL SUPERBLOQUE
            int file_system_type = (int)(this->fs.at(0) - '0');

            // CREACION DEL SUPERBLQUE
            super_bloque.mnt_count = 1;
            super_bloque.magic = 0xEF53;
            super_bloque.first_inode = 0;
            super_bloque.first_block = 0;
            super_bloque.inodes_count = n;
            super_bloque.blocks_count = 3 * n;
            super_bloque.free_inodes_count = n - 2;
            super_bloque.free_blocks_count = (3 * n) - 2;
            super_bloque.inode_size = sizeof(InodeTable);
            super_bloque.block_size = sizeof(FileBlock);
            super_bloque.bm_inode_start = real_partition.start + real_partition.size +sizeof(super_bloque) + 
            (file_system_type == 3 ? 100 * sizeof(Journaling) : 0);
            super_bloque.filesystem_type = file_system_type;
            super_bloque.bm_block_start = super_bloque.bm_inode_start + n;
            super_bloque.inode_start = super_bloque.bm_block_start + 3 * n;
            super_bloque.block_start = super_bloque.inode_start + n * sizeof(InodeTable);
            
            // GUARDO LA FECHA 
            string current_date = get_now();
            strcpy(super_bloque.umtime,current_date.c_str());


        }else{
            cout << "Error: la particion con id " << this->id << " no está montada en RAM" << endl;
        }
    }else{
        cout << "Error: el parametro de id es obligatorio en el comando mkfs" << endl;
    }
}