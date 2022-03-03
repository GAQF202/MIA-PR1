#include "analyzer/parser.h"
#include "analyzer/scanner.h"
#include <iostream>
using namespace std;

void parse(FILE *file);
void ver(const char* path);

int main()
{ 
       string path = "./analyzer/entrada.txt";
       FILE *file = fopen(path.c_str(),"r");
       parse(file);
       //const char* path = "hola";
       //ver(path);List<int> list_1;      
       return 0;
}