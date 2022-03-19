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
    /*cin >> confirmation;

    if(confirmation != ""){
        cout << "Saliendo de pause..." << endl;
    }*/

    int c;
    /* configuramos el terminal para que las pulsaciones se envien
        directamente a stdin */
    system ("/bin/stty raw");
    while((c=getchar()) != 'a' && (c=getchar()) != ' ' && (c=getchar()) != 'b' && (c=getchar()) != 'c' && (c=getchar()) != 'd'&& (c=getchar()) != 'e'&& (c=getchar()) != 'f'&& (c=getchar()) != 'g') {
        /* Tienes que encontrar un mecanismo de escape alternativo a CTRL-D,
        ya que éste no funciona en el modo 'raw' */
        putchar(c);
    }
    /* Se restaura el modo normal de trabajo de la terminal */
    system ("/bin/stty cooked");
}