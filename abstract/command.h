#include <iostream>
#include <string>
using namespace std;
#include <vector>

#ifndef COMMAND_H
#define COMMAND_H

//struct parameter;
struct parameter
{
   char* name;
   char* o;
   int intValue;
   string stringValue;
};

parameter* make_parameter(char* name, char* valueS, int valueI);
string toMayus(string cadena);

string make_absolute(string path);

//CLASE MADRE PARA LA ABSTRACCION DE CLASES DE COMANDO
class command{
    public:
        command();
        virtual void execute();
};

// MKDISK
class mkdiskCmd : public command{
    public:
        mkdiskCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        int size;
        string f;
        string u;
        string path;
};

// RMDISK
class rmdiskCmd : public command{
    public:
        rmdiskCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
};

#endif