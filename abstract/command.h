#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "../allStructs/structs.h"

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
string toMinus(string cadena);

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

// FDISK
class fdiskCmd : public command{
    public:
        fdiskCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        void sortPartitions(Partition a[4]);
        
        //PARAMETROS
        int size;
        string unit;
        string path;
        string type;
        string fit;
        string deleted;
        string name;
        int add;
};

// MOUNT
class mountCmd : public command{
    public:
        mountCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
        string name;
};

// UNMOUNT
class unmountCmd : public command{
    public:
        unmountCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string id;
};

// MKFS
class mkfsCmd : public command{
    public:
        mkfsCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string id;
        string type;
        string fs;
};

// EXEC
class execCmd : public command{
    public:
        execCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
};

// EXEC
class repCmd : public command{
    public:
        repCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
        string name;
        string id;
        string ruta;
};

// -------------------------- COMANDOS PARA INODOS --------------------------

// MKFILE
class mkfileCmd : public command{
    public:
        mkfileCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
        string r;
        int size;
        string cont;
};

// MKDIR
class mkdirCmd : public command{
    public:
        mkdirCmd();
        void assignParameters(parameter* directives[100], int size);
        void execute();
        
        //PARAMETROS
        string path;
        string p;
};

#endif