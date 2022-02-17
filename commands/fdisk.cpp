#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include <cstring> 
using namespace std;

fdiskCmd::fdiskCmd(){
    this->size = -1; //SE INICIALIZA COMO -1 PARA PODER MARCAR SI HAY ERROR
    this->add = 0; //INICIALIZO EL TAMAÑO A QUITAR O PONER EN 0
}

// BUBBLESORT PARA ORDENAR LOS ESPACIOS DISPONIBLES DENTRO DEL DISCO
void bubbleSort(voidEspace a[4], string order){
    int i,j;
    voidEspace temp;
    if(order == "BF"){
        // ORDENA DE MENOR A MAYOR EL ARREGLO
        for(i=1; i<4; i++){
            for(j=3; j>=i; j--){
                if(a[j-1].size > a[j].size){
                    temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                }
            }
        }
    }else if(order == "WF"){
        // ORDENA DE MAYOR A MENOR EL ARREGLO
        for(i=1; i<4; i++){
            for(j=3; j>=i; j--){
                if(a[j-1].size < a[j].size){
                    temp = a[j-1];
                    a[j-1] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

// METODO PARA ORDENER LAS PARTICIONS POR SU POSICION INICIAL
void fdiskCmd::sortPartitions(Partition a[4]){
    int i,j;
    Partition temp;
    for(i=1; i<4; i++){
        for(j=3; j>=i; j--){
            if(a[j-1].start > a[j].start){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void fdiskCmd::assignParameters(parameter* directives[100], int size){

    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-size") == 0){
                this->size = directives[i]->intValue;
            }else if(strcmp(directives[i]->name,(char*)"-fit") == 0){
                this->fit = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-unit") == 0){
                this->unit = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-type") == 0){
                this->type = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-delete") == 0){
                this->deleted = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-name") == 0){
                this->name = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-add") == 0){
                this->add = directives[i]->intValue;
            }
        }
    }
}

void fdiskCmd::execute(){

    if(!((this->fit == "BF") || (this->fit == "FF") || (this->fit == "WF"))){
        cout << "El ajuste indicado para la particion " << this->name << " no es correcto" << endl ;
        return;
    }

    if(this->path.length() != 0){
        if(this->size != -1){
            if(this->name.length() != 0){

                //SE VERIFICA QUE EL DISCO EXISTA
                FILE *file = fopen(this->path.c_str(),"rb+");

                if(file != NULL){
                    voidEspace availableEspaces[4]; // ARRAY PARA GUARDAR LOS ESPACIOS VACIOS EN EL DISCO
                    MBR mbr;
                    int total_partitions=0; // GUARDA LA CANTIDAD DE PARTICIONES
                    int extended_partition=0; // GUARDA SI EXISTE UNA EXTENDIDA
                    // VARIABLE PARA SABER TAMANIO REAL DE LA PARTICION
                    int multiplicator = strcmp(this->unit.c_str(),"K")==0 ? 1 : 1024;

                    voidEspace tempVoidSpace;
                    tempVoidSpace.start = -1;
                    tempVoidSpace.size = -1;

                    for(int i=0; i<4; i++){
                        availableEspaces[i] = tempVoidSpace;
                    }

                    fseek(file, 0, SEEK_SET);
                    fread(&mbr,sizeof(MBR),1,file);

                    // ORDENO LAS PARTICIONES DEL MBR SEGUN SU POSICION EN DISCO
                    this->sortPartitions(mbr.partitions);

                    // SE BUSCAN LAS PARTICIONES ACTIVAS Y  SI HAY EXTENDIDA
                    for(int i=0; i< 4; i++){
                        if(mbr.partitions[i].start != -1){
                            total_partitions += 1;
                        }
                        if(strcpy(mbr.partitions[i].type,"E")==0){
                            extended_partition += 1;
                        }
                        if(mbr.partitions[i].name == this->name){
                            cout << "ya existe la paricion con el nombre"<< this->name <<" en el disco " << endl;
                            return;
                        }
                    }

                    // SI SE QUIERE CREAR UNA EXTENDIDA Y YA HAY UNA ERROR
                    // O SI SE QUIERE CREAR UNA LOGICA Y NO HAY EXTENDIDA ERROR
                    if(this->type=="E" && extended_partition==1){
                        cout << "Error al crear partición " << this->name << " ya existe una partición extendida" << endl;
                        return;
                    }else if(this->type=="L" && extended_partition==0){
                        cout << "Error al crear partición lógica " << this->name << " debido a que no existe una partición extendida en disco" << endl;
                        return;
                    }

                    if(total_partitions!=0){
                        for(int i=0; i < 4; i++){
                            // COMO VIENEN ORDENADAS LAS PARTICIONES AL ESTAR EN LA PRIMERA
                            // QUE APARECE EN EL DISCO, RESTO SU POSICION INICIAL MENOS 
                            // EL TAMANIO DEL MBR
                            if(i==0){
                                availableEspaces[i].size = mbr.partitions[i].start - sizeof(MBR) - 2;
                                availableEspaces[i].start = sizeof(MBR) + 1;
                            }else if(i==4){
                                // RESTO LA POSICION INICIAL DE LA PARTICION ACTUAL MENOS LA POSICION
                                // FINAL DE LA PARTICION ANTERIOR
                                availableEspaces[i].size = mbr.size - (mbr.partitions[i].size + mbr.partitions[i].start) - 1;
                                availableEspaces[i].start = (mbr.partitions[i].size + mbr.partitions[i].start) + 1;
                            }else{
                                availableEspaces[i].size = mbr.partitions[i].start - (mbr.partitions[i-1].size + mbr.partitions[i-1].start) - 2;
                                availableEspaces[i].start = (mbr.partitions[i-1].size + mbr.partitions[i-1].start) + 1;
                            }
                        }
                    }else{
                        // CALCULO TODO EL ESPACIO DISPONIBLE SI NO HAY PARTICIONES
                        availableEspaces[0].size = mbr.size - (sizeof(MBR) + 1);
                        availableEspaces[0].start = sizeof(MBR) + 1;
                    }

                    // SE ORDENAN LOS ESPACIOS DEPENDIENDO DEL FIT
                    bubbleSort(availableEspaces,mbr.fit);

                    /*for(int i=0; i<4; i++){
                        cout << availableEspaces[i].start << endl;
                    }*/
                    
                    // VARIABLE PARA SABER POSICIONAR EL CURSOR EN EL ARCHIVO
                    int selectSpace = -1;
                    // BUSCA EN QUE POSICION SE AJUSTA LA PARTICION SEGUN SU FIT
                    bool positionFound = false;
                    int i = 0;
                    while (!positionFound)
                    {
                        if(availableEspaces[i].size >= this->size*multiplicator*1024){
                            selectSpace = availableEspaces[i].start;
                            positionFound = true;
                        }
                        i++;
                    }
                    
                    // SI NO SE ENCONTRO NINGUN ESPACIO DONDE SE AJUSTE LA PARTICION
                    // QUIERE DECIR QUE NO CABE EN EL DISCO Y SE LANZA UN ERROR
                    if(selectSpace == -1){
                        cout << "La particion " << this->name << " no cabe en el disco indicado" << endl;
                        return;
                    }

                    Partition newPart;
                    strcpy(newPart.name,this->name.c_str());
                    strcpy(newPart.type,this->type.c_str());
                    newPart.start = selectSpace;
                    strcpy(newPart.fit,this->fit.c_str());
                    newPart.size = this->size*multiplicator*1024;

                    // BUSCA EN EL ARRAY DE PARTICIONES DEL MBR Y GUARDA DONDE
                    // ENCUENTRA EL PRIMER ESPACIO VACIO
                    bool partitionFound = false;
                    int courrent = 0;
                    while (!partitionFound)
                    {
                        if(mbr.partitions[courrent].size == -1){
                            mbr.partitions[courrent] = newPart;
                            partitionFound = true;
                        }
                        courrent++;
                    }

                    // SOBRESCRIBE EL MBR
                    fseek(file,0,SEEK_SET);
                    fwrite(&mbr,sizeof(MBR),1,file);
                    //ESCRIBE LA PARTICION EN EL DISCO
                    fseek(file,newPart.start,SEEK_SET);
                    fwrite(&newPart,sizeof(Partition),1,file);

                }else{
                    cout << "El disco " << this->path << " no existe" << endl;
                }

                //cout << "todo bien en fdisk" << endl;
            }else{
                cout << "Error: el parametro -name es obligatorio en el comando fdisk" << endl;
            }
        }else{
            cout << "Error: el parametro -size es obigatorio y debe ser un entero postivo" << endl;
        }
    }else{
        cout << "Error: el parametro -path es obligatorio en el comando fdisk" << endl;
    }



    /*cout << this->size << endl;
    cout << this->path << endl;
    cout << this->unit << endl;
    cout << this->type << endl;
    cout << this->fit << endl;
    cout << this->deleted << endl;
    cout << this->name << endl;
    cout << this->add << endl;*/
}