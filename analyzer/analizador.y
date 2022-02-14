%output "parser.cpp"
%defines "parser.h"
//AYUDA A LA VISUALIZACION DE ERRORES
%define parse.error verbose
%locations

/*SECCION DE CODIGO EXTERNO*/
%{   
    #include "scanner.h"
    #include "../abstract/command.h" //CLASES Y STRUCTS A UTILIZAR
    #include "../estructures/queue.h"
    #include <iostream>
    #include <string.h>
    #include <string>
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    using namespace std;
    //FILE *yyin;
    int yyerror(const char* ver){
        std::cout<<"errorsin"<<std::endl;
        return 0;
    }
%}

/*%code{
    void parse(FILE *file){
        yyin = file;
        yyparse();
        fclose(yyin);
    }
}*/
%union{
    struct parameter *parametro;
    class command *command;
    class queue *queueT;

    char *TEXT;
    float flotante;
    int entero;
}

//TERMINAL TOKENS DECLARATIONS
%token<TEXT> mkdisk;
%token<TEXT> rmdisk;
%token<TEXT> fdisk;

// PARAMETERS
%token<TEXT> size;
%token<TEXT> adjustment;
%token<TEXT> unit;
%token<TEXT> path;
%token<TEXT> type;
%token<TEXT> deleteToken;
%token<TEXT> name;
%token<TEXT> add;

// TYPES
%token<TEXT> number; // "int"
%token<TEXT> CADENA; // STRING
%token<TEXT> caracter; // CHAR

//SYMBOLS DECLARATIONS
%token<TEXT> equals;
%token<TEXT> slash;
%token<TEXT> dot;

//NON TERMINALS TOKENS DECLARATIONS
//INITIAL SYMBOL
%type<TEXT> START;

//PARAMETERS
%type<parametro> SIZE;
%type<parametro> ADJUSTMENT;
%type<parametro> UNIT;
%type<parametro> PATH;
%type<parametro> TYPE;
%type<parametro> DELETEP;
%type<parametro> NAME;
%type<parametro> ADD;

//COMMANDS
%type<queueT> MKDISKPAR;
%type<queueT> RMDISKPAR;
%type<queueT> FDISKPAR;
%type<TEXT> DIRECTORY;

%start START

%%

START : START mkdisk MKDISKPAR
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters($3->cola,$3->size);
        c->execute();
      }
      | START rmdisk RMDISKPAR        
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters($3->cola,$3->size);
        c->execute();
      }
      | START fdisk FDISKPAR
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters($3->cola,$3->size);
        c->execute();
      }
      | fdisk FDISKPAR
      {
        fdiskCmd *c = new fdiskCmd();
        c->assignParameters($2->cola,$2->size);
        c->execute();
      }
      | rmdisk RMDISKPAR
      {
        rmdiskCmd *c = new rmdiskCmd();
        c->assignParameters($2->cola,$2->size);
        c->execute();
      }
      | mkdisk MKDISKPAR
      {
        mkdiskCmd *c = new mkdiskCmd(); 
        //ASIGNACION DE PARAMETROS
        c->assignParameters($2->cola,$2->size);
        c->execute();
      }

FDISKPAR : FDISKPAR SIZE {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR UNIT {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR TYPE {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR ADJUSTMENT{queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR DELETEP {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR NAME {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FDISKPAR ADD {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | ADD {queue *res = new queue();res->push($1);$$ = res;}
         | NAME {queue *res = new queue();res->push($1);$$ = res;}
         | DELETEP {queue *res = new queue();res->push($1);$$ = res;}
         | ADJUSTMENT {queue *res = new queue();res->push($1);$$ = res;}
         | TYPE {queue *res = new queue();res->push($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}
         | UNIT {queue *res = new queue();res->push($1);$$ = res;}
         | SIZE {queue *res = new queue();res->push($1);$$ = res;}

RMDISKPAR : PATH
          {
            queue *res = new queue();
            res->push($1);
            $$ = res;
          }

MKDISKPAR : MKDISKPAR PATH 
          { 
            queue *res = new queue();
            $1->push($2);
            res->append($1);
            $$ = res;
          }
          | MKDISKPAR SIZE 
          {
            queue *res = new queue();
            $1->push($2);
            res->append($1);
            $$ = res;
          }
          | MKDISKPAR UNIT 
          {
            queue *res = new queue();
            $1->push($2);
            res->append($1);
            $$ = res;
          }
          | MKDISKPAR ADJUSTMENT 
          {
            queue *res = new queue();
            $1->push($2);
            res->append($1);
            $$ = res;
          }
          | ADJUSTMENT 
          {
            queue *res = new queue();
            res->push($1);
            $$ = res;
          }
          | UNIT
          {
            queue *res = new queue();
            res->push($1);
            $$ = res;
          }
          | SIZE
          {
            queue *res = new queue();
            res->push($1);
            $$ = res;
          }
          | PATH
          { 
            queue *res = new queue();
            res->push($1);
            $$ = res;
          }

ADJUSTMENT : adjustment equals CADENA 
           {
            $$ = make_parameter($1,$3,0);
           }

UNIT : unit equals caracter 
     {  
        $$ = make_parameter($1,$3,0); 
     }

SIZE : size equals number 
     {
        float res=std::stof($3);
        $$ = make_parameter($1,(char*)"",res);
     }

PATH : path equals DIRECTORY
    {   
        $$ = make_parameter($1,$3,0);
        strcpy( $3, "" );
    }

DIRECTORY : DIRECTORY slash CADENA
          {
            char res[100];
            strcat(res,$2);
            strcat(res,$3);
            $1 = res; 
            $$ = $1;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }
          | slash CADENA
          {
            char res[100];
            strcat(res,$1);
            strcat(res,$2);
            $$ = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }

TYPE : type equals caracter 
     {  
        $$ = make_parameter($1,$3,0); 
     } 

DELETEP : deleteToken equals CADENA 
       {  
        $$ = make_parameter($1,$3,0); 
       } 

NAME : name equals CADENA 
     {  
        $$ = make_parameter($1,$3,0); 
     } 

ADD : add equals number 
    {   
        float res=std::stof($3);
        $$ = make_parameter($1,(char*)"",res);
    } 

%%


void ver(const char* a){
    yy_switch_to_buffer(yy_scan_string(a));
    yyparse();
}

void parse(FILE *file){
    yyin = file;
    yyparse();
    fclose(yyin);
}