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
       /*string content;
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
       cout << path << endl;*/
       string yea = "/media/gerson/PR1/entrada.txt";
       FILE *file = fopen(yea.c_str()/*path.c_str()*/,"r");
       parse(file);  

       //exec -path=/media/gerson/PR1/entrada.txt
       return 0;
}