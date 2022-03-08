#include <iostream>
#include <string>
#include <time.h> 
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

//------------ STRUCTS PARA CREACION DE SISTEMAS DE ARCHIVOS ------------

// SUPERBLOQUE
struct SuperBloque
{
    int filesystem_type;
    int inodes_count;
    int blocks_count;
    int free_blocks_count;
    int free_inodes_count;
    char mtime[23];
    char umtime[23];
    int mnt_count;
    int magic;
    int inode_size;
    int block_size;
    int first_inode;
    int first_block;
    int bm_inode_start;
    int bm_block_start;
    int inode_start;
    int block_start;
};

// TABLA DE INODOS
struct InodeTable
{
    int uid;
    int gid;
    int size;
    time_t atime;
    time_t ctime;
    time_t mtime;
    int block[16];
    char type;
    int perm;
};

// CONTENIDO DE CARPETA
struct ContentFile
{
    char name[12];
    int inodo;
};

// BLOQUE DE CARPETA
struct FileBlock
{
    ContentFile content[4];
};

// BLOQUE DE ARCHIVO
struct ArchiveBlock
{
    char content[64];
};

// BITACORA DE COMANDOS
struct Journaling
{
    char operation[10];
    char content[200];
    int permissions;
    char name[200];
    char owner[10];
    char date[17];
    char type;
};


#endif