#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include <cstring> 

mkdiskCmd::mkdiskCmd(){
    this->size = -1; //SE INICIALIZA COMO -1 PARA PODER MARCAR SI HAY ERROR
}

void mkdiskCmd::assignParameters(parameter* directives[100], int size){
    
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-size") == 0){
                this->size = directives[i]->intValue;
            }else if(strcmp(directives[i]->name,(char*)"-f") == 0){
                this->f = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-u") == 0){
                this->u = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }

        }
    }
}

void mkdiskCmd::execute(){

    char buffer[1024];

    if (this->size != -1){
        if(this->path != ""){

            MBR mbr_disk;
            mbr_disk.fit = this->f;
            int multiplicator = strcmp(this->u.c_str(),"K")==0 ? 1 : 1024;

            FILE *disk_file = fopen(this->path.c_str(),"wb");

            for(int i=0; i<1024; i++){
                buffer[i] = '\0';
            }

            for(int i=0; i<this->size*multiplicator; i++){
                fwrite(&buffer,1024,1,disk_file);
            }
            fclose(disk_file);

        }
    }else{
        cout << "Error debe existir parametro -size" << endl;
    }
    /*cout << "inicia" << endl;
    cout << this->f << endl;
    cout << this->u << endl;
    cout << this->size << endl;
    cout << this->path << endl;
    cout << "termina" << endl;*/

}