#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"
#include <cstring> 
#include <ctime>

mkdiskCmd::mkdiskCmd(){
    this->size = -1; //SE INICIALIZA COMO -1 PARA PODER MARCAR SI HAY ERROR
}

void mkdiskCmd::assignParameters(parameter* directives[100], int size){
    
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-size") == 0){
                this->size = directives[i]->intValue;
            }else if(strcmp(directives[i]->name,(char*)"-fit") == 0){
                this->f = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-unit") == 0){
                this->u = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }
        }
    }
}

void mkdiskCmd::execute(){

    // VERIFICA QUE EL AJUSTE SELECCIONADO SEA UNO DE LOS CORRECTOS
    if(!((this->f == "BF") || (this->f == "FF") || (this->f == "WF"))){
        cout << "El ajuste indicado en el disco " << this->path << " no es correcto" << endl ;
        return;
    }

    // VERIFICA QUE EL DISCO AUN NO EXISTA EN LA RUTA ESPECIFICADA
    if(FILE *file = fopen(this->path.c_str(),"r")){
        cout << "Error el disco que desea crear ya existe en la ruta:" << this->path << endl;
        return;
    }

    char buffer[1024];

    if (this->size != -1){
        if(this->path != ""){

            // CREACION DE CARPETAS DESPUES DE LA PADRE
            string parent_path = "mkdir -p ";
            parent_path += this->path.substr(0,this->path.find_last_of("/\\"));
            system(parent_path.c_str());

            // CREACION DEL MBR
            MBR mbr_disk;

            // LLENADO DEL DISCO CON 0
            int multiplicator = strcmp(this->u.c_str(),"K")==0 ? 1 : 1024;
            FILE *disk_file = fopen(this->path.c_str(),"wb");

            // LLENO EL BUFER CON 0
            for(int i=0; i<1024; i++){
                buffer[i] = '\0';
            }
            fseek(disk_file, 0, SEEK_SET);
            for (int i = 0; i < this->size * multiplicator; i++)
            {
                fwrite(&buffer,1024,1,disk_file);
            }

            // INICIALIZO LAS PARTICIONES PRIMARIAS PARA INGRESARLAS AL MBR
            Partition initial_partition;
            strcpy(initial_partition.name,"");
            initial_partition.status = '0';
            initial_partition.type = 'P';
            initial_partition.start = -1;
            initial_partition.size = -1;
            strcpy( initial_partition.fit,this->f.c_str());
            initial_partition.next = -1;

            // INGRESO LAS CUATRO PARTICIONES VACIAS AL MBR
            for (int i=0; i<4; i++){
                mbr_disk.partitions[i] = initial_partition;
            }

            //ASIGNACION DE ATRIBUTOS DEL MBR
            strcpy(mbr_disk.fit,this->f.c_str());
            mbr_disk.size = this->size*multiplicator*1024;
            mbr_disk.signature = rand() % 10;
            string current_date = get_now();
            strcpy(mbr_disk.date, current_date.c_str());


            fseek(disk_file,0,SEEK_SET);
            fwrite(&mbr_disk, sizeof(MBR), 1, disk_file);

            // CIERRO EL ARCHIVO
            fclose(disk_file);

        }else{
            cout << "Error debe existir parametro -path" << endl;
        }
    }else{
        cout << "Error debe existir parametro -size y debe ser un entero positivo" << endl;
    }

}