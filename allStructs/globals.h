#include "../estructures/simpleList.h"
#include <ctime>

#ifndef GLOBALS_H
#define GLOBALS_H

struct global__courrent_user
{
    int logged;
    char uid[3];
    char user_name[16];
    char pwd[16];
    char grp[16];
    char id[4];
    char gid[3];   
};

extern lista global_list; /* variable global */
extern global__courrent_user global_user; // USUARIO ACTUAL LOGEADO

string get_now();
string format_day_prop(int field);

#endif