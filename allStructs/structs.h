#include <iostream>
#include <string>
using namespace std;    

#ifndef STRUCTS_H
#define STRUCTS_H

struct Partition
{
    char name[16];
    char status;
    char type;
    int start;
    char fit[2];
    int size;
    int next;
};

struct EBR
{
    char name[16];
    char status;
    int start;
    char fit[4];
    int size;
    int next;
};

// STRUCT PARA CONTROLAR LOS ESPACIOS VACIOS DEL DISCO
struct voidEspace{
    int start;
    int size;
};

// ESTRUCT PARA EL MASTER BOOT RECORD
struct MBR{
    Partition partitions[4];
    char date[18];
    int signature;
    char fit[4];
    int size;
};

// STRUCT PARA SABER QUE DISCOS TIENEN PARTICIONES MONTADAS EN RAM
struct UsingDisk
{
    string name;
    int amount = 0;
    int number = 1;
};


#endif