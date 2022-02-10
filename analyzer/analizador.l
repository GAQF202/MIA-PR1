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

NUMBER {DIGIT}+("."{DIGIT}+)?
CHAR {LETTER}?
CADENA {LETTER}({LETTER}|{DIGIT}|"_"|".")*
/*POSIBLE CAMBIO*/
/*r'\".*?\"'*/
BLANK_SPACE [\t\r\f\n" "]


%%
"mkdisk"    { yylval.TEXT = (char*)"mkdisk"; return mkdisk; }
"rmdisk"    { yylval.TEXT = (char*)"rmdisk"; return rmdisk; }

"-size"     { yylval.TEXT = (char*)"-size"; return size; }
"-f"        { yylval.TEXT = (char*)"-f"; return adjustment; }
"-u"        { yylval.TEXT = (char*)"-u"; return unit; }
"-path"     { yylval.TEXT = (char*)"-path"; return path; }
"-unit"     { yylval.TEXT = (char*)"-unit"; return unit; }

"-type"     { yylval.TEXT = (char*)"-type"; return type; }
"-delete"   { yylval.TEXT = (char*)"-delete"; return deleteToken; }
"-name"     { yylval.TEXT = (char*)"-name"; return name; }
"-add"      { yylval.TEXT = (char*)"-add"; return add; }



{CHAR}      { yylval.TEXT = yytext; return caracter; }
{CADENA}    { yylval.TEXT = yytext; return CADENA; }
{NUMBER}    { yylval.TEXT = yytext; return number; }


"="         { yylval.TEXT = (char*)"="; return equals; }
"/"         { yylval.TEXT = (char*)"/"; return slash; }
"."         { yylval.TEXT = (char*)"."; return dot; }


{BLANK_SPACE} {}
. yyerror("mincra");
%%