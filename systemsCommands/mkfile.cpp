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

mkfileCmd::mkfileCmd(){}

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
        // LEO EL SUPERBLOQUE
        fseek(file,element->start + sizeof(Partition),SEEK_SET);
        fread(&superbloque,sizeof(SuperBloque),1,file);

        // CREACION DE ARRAYS PARA GUARDAR BITMAPS
        char bitinodes[superbloque.inodes_count];
        char bitblocks[superbloque.blocks_count];
        fseek(file,superbloque.inode_start,SEEK_SET);
        fread(&bitinodes,sizeof(bitinodes),1,file);
        fseek(file,superbloque.block_start,SEEK_SET);
        fread(&bitblocks,sizeof(bitblocks),1,file);

        // OBTENGO EL PRIMERO INODO
        InodeTable current_inode;
        fseek(file,superbloque.inode_start,SEEK_SET);
        fread(&current_inode,sizeof(InodeTable),1,file);
        //cout << current_inode.block[0] << endl;
        /*for(int path_i=0; path_i<number_routes; path_i++){
            for(int block_i=0; block_i<16; block_i++){
                if(current_inode.block[block_i] != -1){

                }
            }
        }*/


    }else{
        cout << "Error: el disco no existe" << endl;
    }
}
