/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 10 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 06/20/18
* Time: 21:45:36
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

	#include "myparser.h"
	#include <stdlib.h>
	#include <string.h>

#line 46 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 10 ".\\mylexer.l"
;
#line 167 "mylexer.c"
		}
		break;
	case 2:
		{
#line 11 ".\\mylexer.l"
return ';';
#line 174 "mylexer.c"
		}
		break;
	case 3:
		{
#line 12 ".\\mylexer.l"
return '(';
#line 181 "mylexer.c"
		}
		break;
	case 4:
		{
#line 13 ".\\mylexer.l"
return ')';
#line 188 "mylexer.c"
		}
		break;
	case 5:
		{
#line 14 ".\\mylexer.l"
return ',';
#line 195 "mylexer.c"
		}
		break;
	case 6:
		{
#line 15 ".\\mylexer.l"
return '>';
#line 202 "mylexer.c"
		}
		break;
	case 7:
		{
#line 16 ".\\mylexer.l"
return '<';
#line 209 "mylexer.c"
		}
		break;
	case 8:
		{
#line 17 ".\\mylexer.l"
return '=';
#line 216 "mylexer.c"
		}
		break;
	case 9:
		{
#line 18 ".\\mylexer.l"
return '!';
#line 223 "mylexer.c"
		}
		break;
	case 10:
		{
#line 19 ".\\mylexer.l"
return '.';
#line 230 "mylexer.c"
		}
		break;
	case 11:
		{
#line 20 ".\\mylexer.l"
return '*';
#line 237 "mylexer.c"
		}
		break;
	case 12:
		{
#line 21 ".\\mylexer.l"
return 0;
#line 244 "mylexer.c"
		}
		break;
	case 13:
		{
#line 22 ".\\mylexer.l"
return CREATE;
#line 251 "mylexer.c"
		}
		break;
	case 14:
		{
#line 23 ".\\mylexer.l"
return DROP;
#line 258 "mylexer.c"
		}
		break;
	case 15:
		{
#line 24 ".\\mylexer.l"
return DATABASE;
#line 265 "mylexer.c"
		}
		break;
	case 16:
		{
#line 25 ".\\mylexer.l"
return DATABASES;
#line 272 "mylexer.c"
		}
		break;
	case 17:
		{
#line 26 ".\\mylexer.l"
return SHOW;
#line 279 "mylexer.c"
		}
		break;
	case 18:
		{
#line 27 ".\\mylexer.l"
return USE;
#line 286 "mylexer.c"
		}
		break;
	case 19:
		{
#line 28 ".\\mylexer.l"
return TABLE;
#line 293 "mylexer.c"
		}
		break;
	case 20:
		{
#line 29 ".\\mylexer.l"
return TABLES;
#line 300 "mylexer.c"
		}
		break;
	case 21:
		{
#line 30 ".\\mylexer.l"
return INSERT;
#line 307 "mylexer.c"
		}
		break;
	case 22:
		{
#line 31 ".\\mylexer.l"
return INTO;
#line 314 "mylexer.c"
		}
		break;
	case 23:
		{
#line 32 ".\\mylexer.l"
return SELECT;
#line 321 "mylexer.c"
		}
		break;
	case 24:
		{
#line 33 ".\\mylexer.l"
return FROM;
#line 328 "mylexer.c"
		}
		break;
	case 25:
		{
#line 34 ".\\mylexer.l"
return AND;
#line 335 "mylexer.c"
		}
		break;
	case 26:
		{
#line 35 ".\\mylexer.l"
return OR;
#line 342 "mylexer.c"
		}
		break;
	case 27:
		{
#line 36 ".\\mylexer.l"
return WHERE;
#line 349 "mylexer.c"
		}
		break;
	case 28:
		{
#line 37 ".\\mylexer.l"
return UPDATE;
#line 356 "mylexer.c"
		}
		break;
	case 29:
		{
#line 38 ".\\mylexer.l"
return SET;
#line 363 "mylexer.c"
		}
		break;
	case 30:
		{
#line 39 ".\\mylexer.l"
return DELET;
#line 370 "mylexer.c"
		}
		break;
	case 31:
		{
#line 40 ".\\mylexer.l"
return EXIT;
#line 377 "mylexer.c"
		}
		break;
	case 32:
		{
#line 43 ".\\mylexer.l"

	yylval.yych = (char *)malloc(4*sizeof(char)+1);
	strcpy(yylval.yych,"char");
	return CHAR;

#line 388 "mylexer.c"
		}
		break;
	case 33:
		{
#line 49 ".\\mylexer.l"

	yylval.yych = (char *)malloc(3*sizeof(char)+1);
	strcpy(yylval.yych,"int");
	return INT;

#line 399 "mylexer.c"
		}
		break;
	case 34:
		{
#line 55 ".\\mylexer.l"
	
	yylval.yych = (char *)malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return ID;

#line 410 "mylexer.c"
		}
		break;
	case 35:
		{
#line 61 ".\\mylexer.l"

	yylval.yych = (char *)malloc(strlen(yytext)+1);
	strcpy(yylval.yych,yytext);
	return NUMBER; 

#line 421 "mylexer.c"
		}
		break;
	case 36:
		{
#line 67 ".\\mylexer.l"

	yylval.yych = (char *)malloc(strlen(yytext)-1);
	strncpy(yylval.yych,yytext+1,strlen(yytext)-2);
	yylval.yych[strlen(yytext)-2] = 0;
	return STRING;

#line 433 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 316;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 45, 20 },
	{ 61, 31 },
	{ 59, 30 },
	{ 43, 19 },
	{ 46, 20 },
	{ 62, 31 },
	{ 100, 67 },
	{ 84, 52 },
	{ 52, 25 },
	{ 82, 50 },
	{ 83, 50 },
	{ 53, 25 },
	{ 60, 30 },
	{ 44, 19 },
	{ 85, 67 },
	{ 85, 52 },
	{ 55, 27 },
	{ 47, 20 },
	{ 63, 31 },
	{ 56, 27 },
	{ 67, 36 },
	{ 4, 1 },
	{ 5, 1 },
	{ 68, 36 },
	{ 70, 38 },
	{ 98, 66 },
	{ 99, 66 },
	{ 71, 38 },
	{ 6, 1 },
	{ 7, 1 },
	{ 8, 1 },
	{ 9, 1 },
	{ 58, 29 },
	{ 10, 1 },
	{ 40, 5 },
	{ 11, 1 },
	{ 0, 6 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 12, 1 },
	{ 64, 32 },
	{ 13, 1 },
	{ 14, 1 },
	{ 15, 1 },
	{ 16, 1 },
	{ 65, 33 },
	{ 66, 34 },
	{ 17, 1 },
	{ 51, 35 },
	{ 19, 1 },
	{ 20, 1 },
	{ 21, 1 },
	{ 22, 1 },
	{ 48, 21 },
	{ 69, 37 },
	{ 23, 1 },
	{ 49, 22 },
	{ 72, 39 },
	{ 50, 23 },
	{ 75, 43 },
	{ 74, 42 },
	{ 24, 1 },
	{ 76, 44 },
	{ 77, 45 },
	{ 78, 46 },
	{ 25, 1 },
	{ 26, 1 },
	{ 27, 1 },
	{ 79, 47 },
	{ 28, 1 },
	{ 80, 48 },
	{ 81, 49 },
	{ 51, 24 },
	{ 4, 4 },
	{ 86, 53 },
	{ 87, 54 },
	{ 88, 55 },
	{ 0, 1 },
	{ 89, 56 },
	{ 29, 1 },
	{ 90, 57 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 33, 1 },
	{ 74, 58 },
	{ 91, 59 },
	{ 34, 1 },
	{ 92, 60 },
	{ 93, 61 },
	{ 94, 62 },
	{ 95, 63 },
	{ 96, 64 },
	{ 35, 1 },
	{ 73, 41 },
	{ 97, 65 },
	{ 54, 26 },
	{ 36, 1 },
	{ 37, 1 },
	{ 38, 1 },
	{ 42, 17 },
	{ 39, 1 },
	{ 102, 69 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 101, 68 },
	{ 103, 70 },
	{ 89, 71 },
	{ 104, 72 },
	{ 105, 75 },
	{ 106, 76 },
	{ 107, 77 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 108, 78 },
	{ 109, 79 },
	{ 110, 80 },
	{ 111, 81 },
	{ 112, 82 },
	{ 113, 83 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 41, 41 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 114, 84 },
	{ 115, 86 },
	{ 116, 87 },
	{ 117, 88 },
	{ 118, 90 },
	{ 105, 91 },
	{ 119, 92 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 120, 93 },
	{ 121, 94 },
	{ 109, 95 },
	{ 110, 96 },
	{ 18, 154 },
	{ 111, 97 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 18, 154 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 12, 12 },
	{ 122, 98 },
	{ 113, 99 },
	{ 123, 100 },
	{ 115, 101 },
	{ 124, 102 },
	{ 125, 103 },
	{ 126, 104 },
	{ 127, 106 },
	{ 128, 107 },
	{ 129, 108 },
	{ 130, 112 },
	{ 131, 114 },
	{ 132, 116 },
	{ 133, 117 },
	{ 134, 118 },
	{ 135, 119 },
	{ 136, 120 },
	{ 137, 121 },
	{ 138, 122 },
	{ 139, 123 },
	{ 140, 124 },
	{ 141, 125 },
	{ 134, 126 },
	{ 142, 127 },
	{ 143, 128 },
	{ 144, 129 },
	{ 145, 130 },
	{ 146, 131 },
	{ 147, 132 },
	{ 148, 133 },
	{ 142, 135 },
	{ 149, 136 },
	{ 144, 137 },
	{ 145, 138 },
	{ 146, 139 },
	{ 147, 140 },
	{ 148, 141 },
	{ 150, 143 },
	{ 151, 149 },
	{ 152, 150 },
	{ 153, 151 },
	{ 154, 152 },
	{ 154, 153 },
	{ 57, 28 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 154, -9, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 12 },
	{ 0, 50, 1 },
	{ 0, -25, 0 },
	{ 41, -1, 0 },
	{ 0, 0, 3 },
	{ 0, 0, 4 },
	{ 0, 0, 11 },
	{ 0, 0, 5 },
	{ 0, 0, 10 },
	{ 0, 214, 35 },
	{ 0, 0, 2 },
	{ 0, 0, 7 },
	{ 0, 0, 8 },
	{ 0, 0, 6 },
	{ 154, 31, 34 },
	{ 154, 0, 34 },
	{ 154, -67, 34 },
	{ 154, -63, 34 },
	{ 154, -26, 34 },
	{ 154, -17, 34 },
	{ 154, -11, 34 },
	{ 154, -1, 34 },
	{ 154, -59, 34 },
	{ 154, 40, 34 },
	{ 154, -62, 34 },
	{ 154, 243, 34 },
	{ 154, -76, 34 },
	{ 154, -100, 34 },
	{ 154, -94, 34 },
	{ 154, -71, 34 },
	{ 154, -60, 34 },
	{ 154, -55, 34 },
	{ 154, -57, 34 },
	{ 154, -79, 34 },
	{ 154, -34, 34 },
	{ 154, -86, 34 },
	{ 154, -38, 34 },
	{ 0, 0, 9 },
	{ 0, 64, 0 },
	{ 154, 1, 34 },
	{ 154, 3, 34 },
	{ 154, 2, 34 },
	{ 154, -12, 34 },
	{ 154, -3, 34 },
	{ 154, -2, 34 },
	{ 154, 6, 34 },
	{ 154, 1, 34 },
	{ 154, -72, 34 },
	{ 154, 0, 26 },
	{ 154, -67, 34 },
	{ 154, 4, 34 },
	{ 154, 18, 34 },
	{ 154, 17, 34 },
	{ 154, 18, 34 },
	{ 154, 20, 34 },
	{ 154, -6, 34 },
	{ 154, -2, 34 },
	{ 154, -4, 34 },
	{ 154, -18, 34 },
	{ 154, -9, 34 },
	{ 154, -11, 34 },
	{ 154, -4, 34 },
	{ 154, -7, 34 },
	{ 154, -88, 34 },
	{ 154, -100, 34 },
	{ 154, 11, 34 },
	{ 154, 13, 34 },
	{ 154, 23, 34 },
	{ 154, 23, 34 },
	{ 154, 24, 34 },
	{ 0, 0, 36 },
	{ 154, 0, 25 },
	{ 154, 44, 34 },
	{ 154, 62, 34 },
	{ 154, 63, 34 },
	{ 154, 86, 34 },
	{ 154, 76, 34 },
	{ 154, 73, 34 },
	{ 154, 81, 34 },
	{ 154, 90, 34 },
	{ 154, 81, 33 },
	{ 154, 128, 34 },
	{ 154, 0, 29 },
	{ 154, 111, 34 },
	{ 154, 123, 34 },
	{ 154, 135, 34 },
	{ 154, 0, 18 },
	{ 154, 119, 34 },
	{ 154, 88, 34 },
	{ 154, 106, 34 },
	{ 154, 133, 34 },
	{ 154, 130, 34 },
	{ 154, 120, 34 },
	{ 154, 117, 34 },
	{ 154, 126, 34 },
	{ 154, 171, 34 },
	{ 154, 162, 33 },
	{ 154, 173, 34 },
	{ 154, 156, 34 },
	{ 154, 168, 34 },
	{ 154, 180, 34 },
	{ 154, 164, 34 },
	{ 154, 0, 32 },
	{ 154, 195, 34 },
	{ 154, 214, 34 },
	{ 154, 197, 34 },
	{ 154, 0, 14 },
	{ 154, 0, 31 },
	{ 154, 0, 24 },
	{ 154, 200, 34 },
	{ 154, 0, 22 },
	{ 154, 216, 34 },
	{ 154, 0, 17 },
	{ 154, 215, 34 },
	{ 154, 201, 34 },
	{ 154, 217, 34 },
	{ 154, 171, 34 },
	{ 154, 190, 34 },
	{ 154, 173, 34 },
	{ 154, 176, 34 },
	{ 154, 192, 34 },
	{ 154, 191, 34 },
	{ 154, 177, 34 },
	{ 154, 193, 34 },
	{ 154, 226, 34 },
	{ 154, 231, 34 },
	{ 154, 228, 34 },
	{ 154, 214, 34 },
	{ 154, 215, 34 },
	{ 154, 217, 19 },
	{ 154, 232, 34 },
	{ 154, 0, 27 },
	{ 154, 201, 34 },
	{ 154, 206, 34 },
	{ 154, 203, 34 },
	{ 154, 189, 34 },
	{ 154, 190, 34 },
	{ 154, 192, 19 },
	{ 154, 207, 34 },
	{ 154, 0, 13 },
	{ 154, 226, 34 },
	{ 154, 0, 30 },
	{ 154, 0, 21 },
	{ 154, 0, 23 },
	{ 154, 0, 20 },
	{ 154, 0, 28 },
	{ 154, 195, 34 },
	{ 154, 242, 34 },
	{ 154, 211, 34 },
	{ 154, 230, 15 },
	{ 154, 199, 15 },
	{ 0, 139, 16 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 74 ".\\mylexer.l"


