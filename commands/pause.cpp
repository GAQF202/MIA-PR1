#include "../abstract/command.h"
#include "../allStructs/structs.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

pauseCmd::pauseCmd(){}

void pauseCmd::assignParameters(parameter* directives[100], int size){
    this->path = directives[0]->stringValue;
}

void pauseCmd::execute(){
    string confirmation = "";

    cout << "[Pause] Presiona cualquier tecla para continuar: " << this->path << " * " << endl;;
    cin >> confirmation;

    if(confirmation != ""){
        cout << "Saliendo de pause..." << endl;
    }
}