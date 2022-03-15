#include "../estructures/simpleList.h"
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

#ifndef GLOBALS_H
#define GLOBALS_H

struct global_courrent_user
{
    int logged;
    string uid;
    string user_name;
    string pwd;
    string grp;
    string id_partition;
    string gid;   
};

extern lista global_list; /* variable global */
extern global_courrent_user global_user; // USUARIO ACTUAL LOGEADO

string get_now();
string format_day_prop(int field);

vector<string> split(const string &s, char del);

#endif