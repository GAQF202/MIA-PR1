%option case-insensitive
%option yylineno
%option noyywrap
%option nounput

%{

//ARCHIVOS EXTERNOS
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "parser.h"

using namespace std;

void yyerror(const char *s);
int yylex();

%}

DIGIT [0-9]
LETTER [a-zA-AñÑ]

NUMBER -*{DIGIT}+("."{DIGIT}+)?
CHAR {LETTER}?
IDENTIFICADOR {NUMBER}({LETTER}|{DIGIT}|"_"|".")
CADENA {LETTER}({LETTER}|{DIGIT}|"_"|".")*
/*POSIBLE CAMBIO*/
/*r'\".*?\"'*/
COMMENT #.*
BLANK_SPACE [\t\r\f\n" "\"]


%%
"mkdisk"    { yylval.TEXT = (char*)"mkdisk"; return mkdisk; }
"rmdisk"    { yylval.TEXT = (char*)"rmdisk"; return rmdisk; }
"fdisk"     { yylval.TEXT = (char*)"fdisk"; return fdisk; }
"mount"     { yylval.TEXT = (char*)"mount"; return mount; }
"unmount"   { yylval.TEXT = (char*)"unmount"; return unmount; }

"-size"     { yylval.TEXT = (char*)"-size"; return size; }
"-fit"      { yylval.TEXT = (char*)"-fit"; return adjustment; }
"-unit"     { yylval.TEXT = (char*)"-unit"; return unit; }
"-path"     { yylval.TEXT = (char*)"-path"; return path; }
"-type"     { yylval.TEXT = (char*)"-type"; return type; }
"-delete"   { yylval.TEXT = (char*)"-delete"; return deleteToken; }
"-name"     { yylval.TEXT = (char*)"-name"; return name; }
"-add"      { yylval.TEXT = (char*)"-add"; return add; }
"-id"       { yylval.TEXT = (char*)"-id"; return id; }



{CHAR}      { yylval.TEXT = yytext; return caracter; }
{CADENA}    { yylval.TEXT = yytext; return CADENA; }
{NUMBER}    { yylval.TEXT = yytext; return number; }
{IDENTIFICADOR} { yylval.TEXT = yytext; return identificador; }


"="         { yylval.TEXT = (char*)"="; return equals; }
"/"         { yylval.TEXT = (char*)"/"; return slash; }


{BLANK_SPACE} {}
{COMMENT} {}
. yyerror("mincra");
%%
