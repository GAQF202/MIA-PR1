#include "analyzer/parser.h"
#include "analyzer/scanner.h"
#include "abstract/command.h"
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

void parse(FILE *file);
void ver(string path);

int main()
{ 
       string content;
       string command = "";
       std::getline(std::cin,content);
       
       bool isPath = false;

       for(int i=0; i < content.size(); i++){
              if(command == "exec"){
                     command = "";
              }else if(command == "-path="){
                     command = "";
                     isPath = true;
              }else if(command == " "){
                     continue;
              }else{
                     if(!isPath){
                            command += tolower(content[i]);
                     }else{
                            command += content[i];
                     }
              }
       }
       string path;
       if(command[0] != '/'){
              path = "/" + command;
       }else{
              path = command;
       }

       //string path = "./analyzer/entrada.txt";
       /*FILE *file = fopen(command.c_str(),"r");
       parse(file);*/

       ifstream ifs("./analyzer/entrada.txt");
       string new_entry((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
       YY_BUFFER_STATE buffer = yy_scan_string(new_entry.c_str());
       yyparse();

       //exec -path=/media/gerson/PR1/entrada.txt
       return 0;
}