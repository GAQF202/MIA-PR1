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
%token<TEXT> mount;
%token<TEXT> unmount;
%token<TEXT> mkfs;
%token<TEXT> login;
%token<TEXT> logout;
%token<TEXT> exec;
%token<TEXT> pausa;
%token<TEXT> rep;
%token<TEXT> mkfile;
%token<TEXT> mkdir;

// PARAMETERS
%token<TEXT> size;
%token<TEXT> adjustment;
%token<TEXT> unit;
%token<TEXT> path;
%token<TEXT> type;
%token<TEXT> deleteToken;
%token<TEXT> name;
%token<TEXT> add;
%token<TEXT> id;
%token<TEXT> fs;
%token<TEXT> ruta;
%token<TEXT> r;
%token<TEXT> cont;
%token<TEXT> p;
%token<TEXT> password;
%token<TEXT> usuario;

// TYPES
%token<TEXT> number; // "int"
%token<TEXT> CADENA; // STRING
%token<TEXT> caracter; // CHAR
%token<TEXT> identificador; // ID

//SYMBOLS DECLARATIONS
%token<TEXT> equals;
%token<TEXT> slash;

//NON TERMINALS TOKENS DECLARATIONS
//INITIAL SYMBOL
%type<TEXT> START;

//PARAMETERS
%type<parametro> SIZE;
%type<parametro> ADJUSTMENT;
%type<parametro> UNIT;
%type<parametro> PATH;
%type<parametro> TYPE;
%type<parametro> TYPEFORMAT;
%type<parametro> DELETEP;
%type<parametro> NAME;
%type<parametro> ADD;
%type<parametro> ID;
%type<parametro> FS;
%type<parametro> RUTA;
%type<parametro> R;
%type<parametro> CONT;
%type<parametro> P;
%type<parametro> PASSWORD;
%type<parametro> USUARIO;

//COMMANDS
%type<queueT> MKDISKPAR;
%type<queueT> RMDISKPAR;
%type<queueT> FDISKPAR;
%type<queueT> MOUNTPAR;
%type<queueT> UNMOUNTPAR;
%type<queueT> MKFSPAR;
%type<queueT> EXECPAR;
%type<queueT> REPPAR;
%type<queueT> MKFILEPAR;
%type<queueT> MKDIRPAR;
%type<queueT> LOGINPAR;
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
      | START mount MOUNTPAR
      {
        mountCmd *c = new mountCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START unmount UNMOUNTPAR
      {
        unmountCmd *c = new unmountCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START mkfs MKFSPAR
      {
        mkfsCmd *c = new mkfsCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START exec EXECPAR
      {
        execCmd *c = new execCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START rep REPPAR
      {
        repCmd *c = new repCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START mkfile MKFILEPAR
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START mkdir MKDIRPAR
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START pausa
      {
        pauseCmd *c = new pauseCmd();c->execute();
      }
      | START login LOGINPAR
      {
        loginCmd *c = new loginCmd(); c->assignParameters($3->cola,$3->size);c->execute();
      }
      | START logout
      {
        logoutCmd *c = new logoutCmd();c->execute();
      }
      | logout
      {
        logoutCmd *c = new logoutCmd();c->execute();
      }
      | login LOGINPAR
      {
        loginCmd *c = new loginCmd(); c->assignParameters($2->cola,$2->size);c->execute();
      }
      | pausa
      {
        pauseCmd *c = new pauseCmd();c->execute();
      }
      | mkdir MKDIRPAR
      {
        mkdirCmd *c = new mkdirCmd(); c->assignParameters($2->cola,$2->size);c->execute();
      }
      | mkfile MKFILEPAR
      {
        mkfileCmd *c = new mkfileCmd(); c->assignParameters($2->cola,$2->size);c->execute();
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
      | mount MOUNTPAR
      {
        //ASIGNACION DE PARAMETROS
        mountCmd *c = new mountCmd();c->assignParameters($2->cola,$2->size);c->execute();
      }
      | unmount UNMOUNTPAR
      {
        //ASIGNACION DE PARAMETROS
        unmountCmd *c = new unmountCmd();c->assignParameters($2->cola,$2->size);c->execute();
      }
      | mkfs MKFSPAR
      {
        //ASIGNACION DE PARAMETROS
        mkfsCmd *c = new mkfsCmd(); c->assignParameters($2->cola,$2->size);c->execute();
      }
      | exec EXECPAR
      {
        //ASIGNACION DE PARAMETROS
        execCmd *c = new execCmd(); c->assignParameters($2->cola,$2->size);c->execute();
      }
      | rep REPPAR
      {
        //ASIGNACION DE PARAMETROS
        repCmd *c = new repCmd(); c->assignParameters($2->cola,$2->size);c->execute();
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

MOUNTPAR : MOUNTPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MOUNTPAR NAME {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | NAME {queue *res = new queue();res->push($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}

MKFSPAR : MKFSPAR ID {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKFSPAR TYPEFORMAT {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKFSPAR FS {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | FS {queue *res = new queue();res->push($1);$$ = res;}
         | TYPEFORMAT {queue *res = new queue();res->push($1);$$ = res;}
         | ID {queue *res = new queue();res->push($1);$$ = res;}

LOGINPAR : LOGINPAR USUARIO {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | LOGINPAR PASSWORD {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | LOGINPAR ID {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | ID {queue *res = new queue();res->push($1);$$ = res;}
         | PASSWORD {queue *res = new queue();res->push($1);$$ = res;}
         | USUARIO {queue *res = new queue();res->push($1);$$ = res;}

MKFILEPAR: MKFILEPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKFILEPAR R {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKFILEPAR SIZE {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKFILEPAR CONT {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | CONT {queue *res = new queue();res->push($1);$$ = res;}
         | R {queue *res = new queue();res->push($1);$$ = res;}
         | SIZE {queue *res = new queue();res->push($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}
  
MKDIRPAR : MKDIRPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | MKDIRPAR P {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | P {queue *res = new queue();res->push($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}

UNMOUNTPAR : UNMOUNTPAR ID {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
           | ID {queue *res = new queue();res->push($1);$$ = res;}

REPPAR  :  REPPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | REPPAR NAME {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | REPPAR ID {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | REPPAR RUTA {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | RUTA {queue *res = new queue();res->push($1);$$ = res;}
         | NAME {queue *res = new queue();res->push($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}
         | ID {queue *res = new queue();res->push($1);$$ = res;}

EXECPAR  : EXECPAR PATH {queue *res = new queue();$1->push($2);res->append($1);$$ = res;}
         | PATH {queue *res = new queue();res->push($1);$$ = res;}

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

P : p{  $$ = make_parameter($1,$1,0); }

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

RUTA : ruta equals DIRECTORY
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
          | slash
          {
            char res[100];
            strcat(res,$1);
            $$ = res;
            //strcpy( res, "" ); //POSIBLE CAMBIOOO
          }

TYPE : type equals caracter 
     {  
        $$ = make_parameter($1,$3,0); 
     } 

TYPEFORMAT : type equals CADENA 
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

ID : id equals identificador 
     {  
        $$ = make_parameter($1,$3,0); 
     } 

PASSWORD : password equals identificador{$$ = make_parameter($1,$3,0);} 
         | password equals CADENA{$$ = make_parameter($1,$3,0);} 
         | password equals number{$$ = make_parameter($1,$3,0);} 

USUARIO  : usuario equals identificador{$$ = make_parameter($1,$3,0);} 
         | usuario equals CADENA{$$ = make_parameter($1,$3,0);} 

FS : fs equals identificador 
     {  
        $$ = make_parameter($1,$3,0); 
     } 

R : r{  $$ = make_parameter($1,$1,0); } 

CONT : cont equals DIRECTORY
    {   
        $$ = make_parameter($1,$3,0);
        strcpy( $3, "" );
    }

%%


void ver(string a){
    YY_BUFFER_STATE buffer = yy_scan_string(a.c_str());
    yyparse();
}

void parse(FILE *file){
    yyin = file;
    yyparse();
    fclose(yyin);
}