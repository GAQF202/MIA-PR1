#include "simpleList.h"
#include <cstring> 
#include <string>

using namespace std;

lista::~lista() {
   pnodo aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

bool lista::isMount(string partition_name){
    pnodo anterior;
    bool estaMontada = false;

   // RECORRE TODOS LOS NODOS VERIFICANDO QUE ESTE LA PARTICION MONTADA
   if(!ListaVacia()){
      anterior = primero;
      if(anterior->partition_name == partition_name){
        estaMontada = true;
      }

      while(anterior->siguiente){
        anterior = anterior->siguiente;
        if(anterior->partition_name == partition_name){
            estaMontada = true;
        }
      }
   }

   return estaMontada;
}

void lista::Insertar(string partition_name, string disk_name) {
   pnodo anterior;

   // Si la lista está vacía
   if(ListaVacia()){//|| primero->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual
      primero = new nodo(this->getId(disk_name), partition_name, primero);
      //primero = new nodo(v, primero);
   } else {
      // Buscar el nodo de valor menor a v
      anterior = primero;
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga
      // un valor mayor que v
      while(anterior->siguiente)//&& anterior->siguiente->valor <= v)
        anterior = anterior->siguiente;
      // Creamos un nuevo nodo después del nodo anterior, y cuyo siguiente
      // es el siguiente del anterior
      anterior->siguiente = new nodo(this->getId(disk_name), partition_name, anterior->siguiente);
      //anterior->siguiente = new nodo(v, anterior->siguiente);
   }
}

void lista::Borrar(string v){
   pnodo anterior, nodo;

   nodo = primero;
   anterior = NULL;
   while(nodo && nodo->valor != v) {
      anterior = nodo;
      nodo = nodo->siguiente;
   }
   if(!nodo /*|| nodo->valor != v*/) return;
   else { // Borrar el nodo
      if(!anterior) // Primer elemento
         primero = nodo->siguiente;
      else  // un elemento cualquiera
         anterior->siguiente = nodo->siguiente;
      delete nodo;
   }
}

void lista::Mostrar() {
   nodo *aux;

   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}

string getIdPartition(int number){
    string res;
    for(int i='A'; i<'Z'; i++){
        if((number+64) == i){
            res = i;
        }
    }
    return res;
}

string lista :: getId(string myDisk){
    for(int i=0; i<600; i++){
        if(this->disks[i].name == myDisk){
            disks[i].amount++;
            return "57" + to_string(disks[i].number) + getIdPartition(disks[i].amount);
        }
    }

    // CREARA UN NUEVO REGISTRO DE DISCO MONTADO
    this->disksCount++;
    this->disks[this->disksCount].name = myDisk;
    this->disks[this->disksCount].number = this->disksCount;
    this->disks[this->disksCount].amount++;
    return "57" + to_string(disks[this->disksCount].number) + getIdPartition(disks[this->disksCount].amount);
}

/*
SimpleList :: SimpleList(){
    this->first;
    this->last;
    this->count = 0;
    this->disksCount = 0;
}

string getIdPartition(int number){
    string res;
    for(int i='A'; i<'Z'; i++){
        if((number+64) == i){
            res = i;
        }
    }
    return res;
}

string SimpleList :: getId(string myDisk){
    for(int i=0; i<600; i++){
        if(this->disks[i].name == myDisk){
            disks[i].amount++;
            return "57" + to_string(disks[i].number) + getIdPartition(disks[i].amount);
        }
    }

    // CREARA UN NUEVO REGISTRO DE DISCO MONTADO
    this->disksCount++;
    this->disks[this->disksCount].name = myDisk;
    this->disks[this->disksCount].number = this->disksCount;
    this->disks[this->disksCount].amount++;
    return "57" + to_string(disks[this->disksCount].number) + getIdPartition(disks[this->disksCount].amount);
}

void SimpleList :: Add(string date, string myDisk){

    Node newNode;
    //newNode.partition = date;

    bool flag_disk = false;
    for(int i=0; i<600; i++){
        if(this->disks[i].name == myDisk){
            flag_disk = true;
            disks[i].amount++;
            newNode.id =  "57" + to_string(disks[i].number) + getIdPartition(disks[i].amount);
            break;
        }
    }
    if(!flag_disk){
        // CREARA UN NUEVO REGISTRO DE DISCO MONTADO
        this->disksCount++;
        this->disks[this->disksCount].name = myDisk;
        this->disks[this->disksCount].number = this->disksCount;
        this->disks[this->disksCount].amount++;
        newNode.id = "57" + to_string(disks[this->disksCount].number) + getIdPartition(disks[this->disksCount].amount);
    }

    if(this->count == 0){
        this->first = newNode;
        this->last = this->first;
        this->count++;
    }else{
        this->last.next = &newNode;
        this->last = newNode;
        this->count++;
    }
}
*/