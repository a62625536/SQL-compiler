%{
	#include "myparser.h"
	#include <stdlib.h>
	#include <string.h>
%}


%%

[ ]+ ;
";"					{return ';';}
"("					{return '(';}
")"					{return ')';}
","					{return ',';}
">"					{return '>';}
"<"					{return '<';}
"="					{return '=';}
"!="				{return '!';}
"."					{return '.';}
"*"					{return '*';}
"\n"				{return 0;}
create|CREATE		{return CREATE;}
drop|DROP			{return DROP;}
database|DATABASE	{return DATABASE;}
databases|DATABASES	{return DATABASES;}
show|SHOW			{return SHOW;}
use|USE				{return USE;}
table|TABLE			{return TABLE;}
tables|TABLES		{return TABLES;}
insert|INSERT		{return INSERT;}
into|INTO			{return INTO;}
select|SELECT		{return SELECT;}
from|FROM			{return FROM;}
and|AND 			{return AND;}
or|OR				{return OR;}
where|WHERE 		{return WHERE;}
update|UPDATE 		{return UPDATE;}
set|SET 			{return SET;}
delete|DELETE		{return DELET;}
exit|EXIT			{return EXIT;}

char|CHAR	
{
	yylval.yych = (char *)malloc(4*sizeof(char)+1);
	strcpy(yylval.yych,"char");
	return CHAR;
}
int|INT 
{
	yylval.yych = (char *)malloc(3*sizeof(char)+1);
	strcpy(yylval.yych,"int");
	return INT;
}
[A-Za-z][A-Za-z0-9_]*	
{	
	yylval.yych = (char *)malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return ID;
}
[0-9]+	
{
	yylval.yych = (char *)malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return NUMBER; 
}
"'"[A-Za-z0-9]+"'"	
{
	yylval.yych = (char *)malloc(strlen(yytext)-1);
	strncpy(yylval.yych,yytext+1,strlen(yytext)-2);
	yylval.yych[strlen(yytext)-2] = 0;
	return STRING;
}

%%
