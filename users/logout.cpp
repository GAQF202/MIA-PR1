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

logoutCmd::logoutCmd(){}

void logoutCmd::assignParameters(parameter* directives[100], int size){
}

void logoutCmd::execute(){
    cout << "Entraaa" << endl;
    if(global_user.logged != -1){
            //LOGOUT
            global_user.logged = -1;
            global_user.uid = "";
            global_user.user_name = "";
            global_user.pwd = "";
            global_user.grp = "";
            global_user.id_partition = "";
            global_user.gid = "";
    }else{
        cout << "Error: no hay ningun usuario logueado actualmente" << endl;
    }
}