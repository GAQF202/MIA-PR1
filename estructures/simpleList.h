#include "../allStructs/structs.h"

#include <string>
#include <cstring>

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(string id, string disk_name, int initial, string path, nodo *sig = NULL)
    {
       valor = id; // ID DE LA PARTICION MONTADA
       siguiente = sig;
       partition_name = disk_name;
       start = initial;
       path_disk = path;
    }

   //private:
    string valor;
    string partition_name;
    string path_disk;
    nodo *siguiente;
    int start;

   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = actual = NULL; 
      // INICIALIZO MIS LETRAS EN -1
      for(int i=0; i<23; i++){
         this->letras[i] = -1;
      }
   }
    ~lista();

    void Insertar(string v, string name, int start);
    void Borrar(string v);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void Siguiente() { if(actual) actual = actual->siguiente; }
    void Primero() { actual = primero; }
    void Ultimo() { Primero(); if(!ListaVacia()) while(actual->siguiente) Siguiente(); }
    bool Actual() { return actual != NULL; }
    bool isMount(string partition_name);
    pnodo getElement(string v);
    string ValorActual() { return actual->valor; }
    string getId(string myDisk);
    string getLetter();
    void eliminarLetra(char letra);
        
    int count; //  CONTADOR PARA SABER CUANTOS ELEMENTOS HAY EN LA LISTA
    int disksCount; // CONTADOR PARA SABER QUE CANTIDAD DE DISCOS HAY MONTADOS
    UsingDisk disks[600];

    int letras[23];

   private:
    pnodo primero;
    pnodo actual;
};

#endif