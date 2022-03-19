#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"
#include "../estructures/simpleList.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;
//lista global_list;
//global_courrent_user global_user;

loginCmd::loginCmd(){}

void loginCmd::assignParameters(parameter* directives[100], int size){
    for(int i = 0; i<size; i++){
        if(strcmp(directives[i]->name,(char*)"-usuario") == 0){
            this->usuario = toMayus(directives[i]->stringValue);
        }else if(strcmp(directives[i]->name,(char*)"-password") == 0){
            this->password = toMayus(directives[i]->stringValue);
        }else if(strcmp(directives[i]->name,(char*)"-id") == 0){
            this->id = toMayus(directives[i]->stringValue);
        }
    }
}

void loginCmd::execute(){
    if(this->password != ""){
        if(this->id != ""){
            if(this->usuario != ""){

                if(global_user.logged == -1){
                    pnodo partition_found;
                    SuperBloque super_bloque;

                    partition_found = global_list.getElement(this->id);
                    if(partition_found){
                        Partition real_partition;
                        FILE *file = fopen(partition_found->path_disk.c_str(),"rb+");
                        // VERIFICA QUE EL DISCO SI EXISTA EN LA RUTA ESPECIFICADA
                        if(!file){
                            cout << "Error el disco indicado no existe en la ruta:" << partition_found->path_disk << endl;
                            fclose(file);
                            return;
                        }
                        // LEO LA PARTICION MONTADA EN EL DISCO
                        fseek(file,partition_found->start,SEEK_SET);
                        fread(&real_partition,sizeof(Partition),1,file);

                        // LEO EL SUPERBLOQUE
                        fseek(file,real_partition.start + sizeof(Partition),SEEK_SET);
                        fread(&super_bloque,sizeof(SuperBloque),1,file);

                        InodeTable users_inode;
                        // LEO EL INODO QUE CONTIENE EL ARCHIVO DE USUARIOS
                        fseek(file,super_bloque.inode_start + 1 * sizeof(InodeTable),SEEK_SET);
                        fread(&users_inode,sizeof(InodeTable),1,file);

                        ArchiveBlock archive_block;

                        string users_archive_content = "";

                        for(int block_i=0; block_i<15; block_i++){
                            if(users_inode.block[block_i] != -1){
                                fseek(file,super_bloque.block_start + users_inode.block[block_i] * sizeof(ArchiveBlock),SEEK_SET);
                                fread(&archive_block,sizeof(ArchiveBlock),1,file);
                                users_archive_content += archive_block.content;
                            }
                        }

                        //cout << users_archive_content << endl;
                        // OBTENGO TODAS LAS CARPETAS PADRES DEL ARCHIVO
                        vector<string> routes = split(users_archive_content,'\n');
                        // OBTENGO EL TAMANIO DE LINEAS DE USUARIOS
                        int number_routes = routes.size();
                        bool exist_user = false;
                        for(int i=0; i<number_routes; i++){
                            // OBTENGO TODOS LOS USUARIOS Y GRUPOS
                            vector<string> users = split(routes[i],',');
                            if(users.size() == 5 ){
                                // VERIFICO QUE SE HAYA ENCONTRADO EL USUARIO
                                if(toMayus(users[3]) == this->usuario){
                                    // LOGIN
                                    exist_user = true;
                                    global_user.uid = users[0];
                                    global_user.logged = 1;
                                    global_user.grp = users[2];
                                    global_user.gid = users[2];
                                    global_user.user_name = users[3];
                                    global_user.pwd = users[4];
                                    global_user.id_partition = partition_found->valor;
                                }
                            }
                        }

                        if(!exist_user){
                            cout << "Error: El usuario con el que intentaste iniciar sesión no existe" << endl;
                        }

                    }else{
                        cout << "Error: la particion con id " << this->id << " no está montada en RAM" << endl;
                    }
                    
                }else{
                    cout << "Error: no se puede loguear debido a que ya hay un usuario logueado" << endl;
                }

            }else{
                cout << "Error: el parametro usuario es requerido para realizar login" << endl;
            }        }else{
            cout << "Error: el parametro id es requerido para realizar login" << endl;
        }
    }else{
        cout << "Error: el parametro password es requerido para realizar login" << endl;
    }
}