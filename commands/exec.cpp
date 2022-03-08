#include "../analyzer/parser.h"
#include "../analyzer/scanner.h"
#include "../abstract/command.h"
#include "../allStructs/structs.h"

#include<iostream>
#include<fstream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

void parse(FILE *file);

execCmd::execCmd(){}

void execCmd::assignParameters(parameter* directives[100], int size){
    this->path = directives[0]->stringValue;
}

void execCmd::execute(){

    ifstream ifs(this->path);
    string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

    YY_BUFFER_STATE buffer = yy_scan_string(content.c_str());
    yyparse();
}