#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include <cstring> 

fdiskCmd::fdiskCmd(){
    this->size = -1; //SE INICIALIZA COMO -1 PARA PODER MARCAR SI HAY ERROR
    this->add = 0; //INICIALIZO EL TAMAÑO A QUITAR O PONER EN 0
}

void fdiskCmd::assignParameters(parameter* directives[100], int size){

    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-size") == 0){
                this->size = directives[i]->intValue;
            }else if(strcmp(directives[i]->name,(char*)"-fit") == 0){
                this->fit = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-unit") == 0){
                this->unit = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-type") == 0){
                this->type = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-delete") == 0){
                this->deleted = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-name") == 0){
                this->name = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-add") == 0){
                this->add = directives[i]->intValue;
            }
        }
    }
}

void fdiskCmd::execute(){
    if(this->path.length() != 0){
        if(this->size != -1){
            if(this->name.length() != 0){
                cout << "todo bien en fdisk" << endl;
            }else{
                cout << "Error: el parametro -name es obligatorio en el comando fdisk" << endl;
            }
        }else{
            cout << "Error: el parametro -size es obigatorio y debe ser un entero postivo" << endl;
        }
    }else{
        cout << "Error: el parametro -path es obligatorio en el comando fdisk" << endl;
    }



    /*cout << this->size << endl;
    cout << this->path << endl;
    cout << this->unit << endl;
    cout << this->type << endl;
    cout << this->fit << endl;
    cout << this->deleted << endl;
    cout << this->name << endl;
    cout << this->add << endl;*/
}