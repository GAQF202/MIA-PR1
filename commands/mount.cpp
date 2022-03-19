#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"
#include "../estructures/simpleList.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
lista global_list;
global_courrent_user global_user;

mountCmd::mountCmd(){}

void mountCmd::assignParameters(parameter* directives[100], int size){
    
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-name") == 0){
                this->name = toMayus(directives[i]->stringValue);
            }
        }
    }
}

void mountCmd::execute(){

    FILE *file = fopen(this->path.c_str(),"rb+");
    // VERIFICA QUE EL DISCO SI EXISTA EN LA RUTA ESPECIFICADA
    if(!file){
        cout << "Error el disco indicado no existe en la ruta:" << this->path << endl;
        fclose(file);
        return;
    }

    MBR mbr;
    Partition extended_partition;
    fseek(file,0,SEEK_SET);
    fread(&mbr,sizeof(MBR),1,file);

    for(int i=0; i<4 ; i++){
        if(mbr.partitions[i].type == 'E'){
            extended_partition = mbr.partitions[i];
        }
    }

    Partition temp; // GUARDA EL TEMPORAL PARA RECORRER LA LISTA
    Partition previous; // GUARDA LA PARTICION ANTERIOR

    // LEO LA PRIMERA PARTICION LOGICA A DONDE APUNTA LA EXTENDIDA Y ASIGNO A TEMP
    fseek(file,extended_partition.next,SEEK_SET);
    fread(&temp,sizeof(Partition),1,file);

    bool flag_partition = false;
    while(temp.next != -1){
        if(temp.name == this->name){
            // AL ENCONTRAR LA PARTICION INDICA QUE ES LOGICA
            flag_partition = true;
            break;
        }
        previous = temp; // GUARDO EL TEMPORAL PARA "REGRESAR" EN LA LISTA
        fseek(file,temp.next,SEEK_SET);
        fread(&temp,sizeof(Partition),1,file);
    }

    // VERIFICA QUE LA PARTICION INDICADA SEA DE TIPO LOGICA
    if(flag_partition){
        //string disk_name = this->path.substr(this->path.find_last_of("/\\")+1,this->path.length());
        // MONTO LA PARTICION EN RAM EN LA LISTA GLOBAL
        if(!global_list.isMount(temp.name)){
            global_list.Insertar(temp.name,this->path,temp.start);
            temp.status = '1';
            fseek(file,temp.start,SEEK_SET);
            fwrite(&temp,sizeof(Partition),1,file);
            /*cout << endl;
            for(int i=0; i<23; i++){
                cout << global_list.letras[i];
            }*/
            //global_list.Mostrar();
        }else{
            cout << "Aviso: la partición "<< temp.name <<" ya está montada en RAM" << endl;
        }
        //global_list.Mostrar();
    }else{
        cout << "Error: la partición a montar debe ser de tipo lógica" << endl;
    }

    fclose(file);

}