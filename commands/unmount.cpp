#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

unmountCmd::unmountCmd(){}

void unmountCmd::assignParameters(parameter* directives[100], int size){
    this->id = directives[0]->stringValue;
}

void unmountCmd::execute(){
    // BORRO LA PARTICION INDICADA DE LA LISTA GLOBAL DE PARTICIONES MONTADAS
    global_list.Borrar(this->id);
}