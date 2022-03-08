#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"
#include "../estructures/simpleList.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

unmountCmd::unmountCmd(){}

void unmountCmd::assignParameters(parameter* directives[100], int size){
    this->id = toMayus(directives[0]->stringValue);
}

void unmountCmd::execute(){
    pnodo found_partition_mounted;
    found_partition_mounted = global_list.getElement(this->id);

    if(found_partition_mounted){
        Partition real_partition;
        FILE *file = fopen(found_partition_mounted->path_disk.c_str(),"rb+");
        // VERIFICA QUE EL DISCO SI EXISTA EN LA RUTA ESPECIFICADA
        if(!file){
            cout << "Error el disco indicado no existe en la ruta:" << found_partition_mounted->path_disk << endl;
            fclose(file);
            return;
        }
        // LEO Y ACTUALIZO LA PARTICION DEL DISCO
        fseek(file,found_partition_mounted->start,SEEK_SET);
        fread(&real_partition,sizeof(Partition),1,file);
        real_partition.status = '0';
        fseek(file,found_partition_mounted->start,SEEK_SET);
        fwrite(&real_partition,sizeof(Partition),1,file);

        // BORRO LA PARTICION INDICADA DE LA LISTA GLOBAL DE PARTICIONES MONTADAS
        global_list.Borrar(this->id);   
        fclose(file);
    }else{
        cout << "No se encontró la partición " << this->id << " a desmontar" << endl;
    }
}