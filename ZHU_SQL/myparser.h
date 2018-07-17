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
* myparser.h
* C header file generated from myparser.y.
* 
* Date: 06/20/18
* Time: 21:45:36
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yypars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 155 ".\\myparser.y"

	char ch;
	char *yych;				
	struct Createfieldsdef *cfdef_var;	
	struct Values *val;
	struct Conditions *con;
	struct Selectedfields *sel_fie;
	struct Selectedtables *sel_tab;
	struct Changestruct *chan;

#line 46 "myparser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

extern YYSTYPE YYNEAR yylval;

#define EXIT 257
#define CREATE 258
#define DATABASE 259
#define SHOW 260
#define DATABASES 261
#define DROP 262
#define USE 263
#define TABLE 264
#define TABLES 265
#define INSERT 266
#define INTO 267
#define SELECT 268
#define FROM 269
#define OR 270
#define WHERE 271
#define UPDATE 272
#define SET 273
#define DELET 274
#define AND 275
#define ID 276
#define NUMBER 277
#define CHAR 278
#define INT 279
#define STRING 280
#endif
