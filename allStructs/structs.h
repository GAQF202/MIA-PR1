#include <iostream>
#include <string>
using namespace std;

#ifndef STRUCTS_H
#define STRUCTS_H

struct EBR
{
    char name[16];
    char status;
    int start;
    string fit;
    int size;
    int next;
};


//ESTRUCT PARA EL MASTER BOOT RECORD
struct MBR{
    //Partition partitions[4];
    char date[18];
    int signature;
    string fit;
    int size;
};

#endif