#include "command.h"
#include <string.h>

parameter* make_parameter(char* name, char* valueS, int valueI){
    parameter* res = new parameter;

    char ver[10000];
    strcpy(ver, valueS);


    res->name = name;
    res->stringValue = string(ver);
    res->intValue = valueI;
    res->o = ver; //NO SIRVE POR AHORA
    //std::cout << res->stringValue << endl;
    return res;
}

string make_absolute(string path){
    return "instructions";
}

//FUNCION PARA CONVERTIR STRINGS A MINUSCULAS
string toMayus(string cadena) {
    string res = cadena;
    for (int i = 0; i < res.length(); i++) res[i] = toupper(res[i]);
    return res;
}

//FUNCION PARA CONVERTIR STRINGS A MINUSCULAS
string toMinus(string cadena) {
    string res = cadena;
    for (int i = 0; i < res.length(); i++) res[i] = tolower(res[i]);
    return res;
}

/*INICIA COMMAND*/
command::command(){}   
void command::execute(){}
/*TERMINA COMMAND*/

