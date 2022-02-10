#include "../abstract/command.h"
#include "../allStructs/structs.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

rmdiskCmd::rmdiskCmd(){}

void rmdiskCmd::assignParameters(parameter* directives[100], int size){
    this->path = directives[0]->stringValue;
}

void rmdiskCmd::execute(){
    string confirmation = "";

    cout << "Desea eliminar el archivo: " << this->path << " ?[s/n]";
    cin >> confirmation;

    if(confirmation == "s" || confirmation == "S"){
        if(remove(this->path.c_str()) != 0){
            cout << "Error al borrar archivo en ruta: " << this->path << endl;;
        }
    }
}