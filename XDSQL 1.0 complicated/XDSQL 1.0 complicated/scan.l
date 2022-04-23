%option noyywrap
%option caseless	

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gram.tab.h"
#include "values.h"

extern void yyerror(const char*);

int yylex(void);
%}

digit [0-9]
digits {digit}+
id [a-zA-Z][a-zA-Z0-9_]*
string '[^']*'




%%
create		{return CREATE;}
database	{return DATABASE;}
databases	{return DATABASES;}
show		{return SHOW;}
use			{return USE;}
drop		{return DROP;}
table		{return TABLE;}
int			{return INT;}
char		{return CHAR;}
tables		{return TABLES;}
insert		{return INSERT;}
into		{return INTO;}
values		{return VALUES;}
delete		{return DELETE;}
from		{return FROM;}
where		{return WHERE;}
and			{return AND;}
or			{return OR;}
not			{return NOT;}
update		{return UPDATE;}
set			{return SET;}
select		{return SELECT;}
exit		{return EXIT;}




";" |
"(" |
")" |
"," |
"+" |
"-" |
"*" |
"/" |
"." |
"=" |
"<" |
">" |
"!" {return yytext[0];}

\n	{return NEWLINE;}

[ \t]	{}


{id}		{
	int type=1;
	char* array=yytext;
	yylval.value=new values(type,array);
	return ID;}

{digits}	{
	int type=3;
	char* array=yytext;
	yylval.value=new values(type,array);
	return NUMBER;
}


{string}	{
	int type=2;
	char* array=new char[strlen(yytext)-1];
	memcpy(array,yytext+1,strlen(yytext)-2);
	array[strlen(yytext)-2]='\0';
	yylval.value=new values(type,array);
	delete[] array;

	return STRING;
}


.	{yyerror("Lexical error");}

%%





