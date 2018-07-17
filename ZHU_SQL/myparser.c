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
* myparser.c
* C source file generated from myparser.y.
* 
* Date: 06/20/18
* Time: 21:45:36
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\myparser.y"

#include "mylexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>

struct Createdbstruct				//1.createdb语法树根节点
{
	char *database;
};
									//2.showdb
struct Dropdbstruct					//3.dropdb语法树根节点
{
	char *database;
};	
struct Usedbstruct					//4.usedb语法树根节点
{
	char *database;
};
struct Createfieldsdef	//create语句中的字段
{
	char *field;		//列名
	int type;			//1：字符串，2：整数
	int length;			//若type为1，字符长
	struct Createfieldsdef *next_fdef;
};
struct Createstruct					//5.createtb语法树根节点
{
	char *table;
	struct Createfieldsdef *fdef;
};
									//6.showtb
struct Droptbstruct					//7.droptb语法树根节点
{
	char *table;
};
struct Values 			//元组的字段
{
	char *table;
	int type;
	char *string;
	struct Values *next_v;
};
struct Insertsturct					//8.insert语法树根节点
{
	char *table;
	struct Values *v;
};
struct Conditions 		//条件
{
	struct Conditions *left;
	struct Conditions *right;
	char op;			//'a'：and，'o'：or，'!'：!= 
	int type;			//0：字段，1：字符串，2：整数
	char *value;
	char *table;
};
struct Selectedfields	//选择的字段
{
	char *table;			
	char *field;			
	struct Selectedfields *next_sf;
};
struct Selectedtables	//选择的表
{
	char *table;
	struct Selectedtables *next_st;
};
struct Selectstruct 				//9.select语法树根节点	
{		
	struct Selectedfields *sf;
	struct Selectedtables *st;
	struct Conditions *cons;
};
struct Changestruct		//修改的内容		
{
	char *string;
	int type;
	char *value;
	struct Changestruct *next_ch;
};
struct Updatastruct					//10.update语法树根节点
{
	char *table;
	struct Changestruct *ch;
	struct Conditions *cons;
};
struct Values2			//保存表中内容
{
	char *table;
	char *string;
	char *value;
	int type;
	struct Values2 *next_v;
};
struct Deletestruct					//11.delete语法树根节点
{
	char *tables;
	struct Conditions *cons;
};
									//12.exit语法树根节点
struct Statements					//13.总根节点
{
	int type;
	void * sql;
	struct statements *next_s;
};

void createDatabase(char *s);	//创建数据库
void showDatabases();	//显示所有数据库
void dropDatabase(char *s);	//删除数据库
void useDatabase(char *s);	//使用数据库
void createTable(char *s,struct Createfieldsdef *var);	//用表名和累计字段生成表
void addField(struct Createfieldsdef **f1,struct Createfieldsdef *f2);	//单个字段生成累计字段
void addFields(struct Createfieldsdef **f1,struct Createfieldsdef *f2,struct Createfieldsdef *f3);	//累计字段和单个字段生成累计字段
void createField(struct Createfieldsdef **f1,char *s1,char *s2);	//生成字段
void getType1(char **s,char *s1,char *s2);	//读入类型
void getType2(char **s,char *s1);	//读入类型
void showTables();	//显示当前数据库中所有表名
void dropTable(char *s);	//删除表
void insertValues(char *s,struct Values *val);	//将元组插入到表中
void addValue(struct Values **v1,struct Values *v2);	//单个元素生成元组
void addValues(struct Values **v1,struct Values *v2,struct Values *v3);	//单个元素和元组生成元组
void getValue(struct Values **v,char *s,int type);	//获得元素
int isConOk1(struct Values *v,struct Conditions *c);	//判断判断条件是否符合规则（变量存在且唯一、类型匹配）
int isSfOk(struct Selectedfields *f,struct Values *v);	//判断累计选择列是否符合规则（变量存在且唯一）
int isConTrue(struct Values2 *v,struct Conditions *c);	//判断叉乘结果的一行是否符合累计判断条件
void corssValues(struct Values2 *begin,struct Values2 *now,struct Values *v,struct Selectedfields *f,struct Selectedtables *t,struct Conditions *c);	//累计选择表的叉乘递归，最后一层打印所有符合条件的结果
void selectValues(struct Selectedfields *f,struct Selectedtables *t,struct Conditions *c);	//select主函数
void createFs(struct Selectedfields **tf1,struct Selectedfields *tf2);	//赋值累计选择列
void addTbf(struct Selectedfields **tf1,struct Selectedfields *tf2);	//单个选择列生成累计选择列
void addTbfs(struct Selectedfields **tf1,struct Selectedfields *tf2,struct Selectedfields *tf3);	//选择列和累计选择列生成累计选择列
void createTbf1(struct Selectedfields **tf,char *s);	//列名生成选择列结构
void createTbf2(struct Selectedfields **tf,char *s1,char *s2);	//表名列名生成选择列结构
void addTab1(struct Selectedtables **t1,struct Selectedtables *t2,char *s);	//单个表和累计选择表生成累计选择表
void addTab2(struct Selectedtables **t1,char *s);	//单个表生成累计选择表
void addCon1(struct Conditions **c1,struct Conditions *c2);	//赋值判断条件
void addCon2(struct Conditions **c1,struct Conditions *c2,struct Conditions *c3,char c);	//合并两个判断条件构建判断条件
void createCon1(struct Conditions **c,struct Selectedfields *t1,char cc,struct Selectedfields *t2);	//两个变量构建判断条件
void createCon2(struct Conditions **c,struct Selectedfields *t,char cc,char *s,int type);	//左变量和右值构建判断条件
int isConOk2(char *s,struct Values *v,struct Conditions *c);	//判断累计判断条件是否符合规则（表名一致、变量存在、类型匹配）
int isChOk(char *s,struct Values *v,struct Changestruct *ch);	//判断累计更新列是否符合规则（变量存在、类型匹配）
void changeCon(char *s,struct Conditions *c);	//填充累计判断条件中的表名
void updateChan(char *s,struct Changestruct *ch,struct Conditions *c);	//update主函数
void addChan(struct Changestruct **ch1,struct Changestruct *ch2);	//更新列构造累计更新列
void addChans(struct Changestruct **ch1,struct Changestruct *ch2,struct Changestruct *ch3);	//更新列和累计更新列构造累计更新列
void createChan(struct Changestruct **ch,char *s1,char *s2,int type);	//构造更新列
void deleteValues(char *s,struct Conditions *c);	//delete主函数

#line 193 "myparser.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\myparser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 183 ".\\myparser.y"
exit(0);
#line 319 "myparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 184 ".\\myparser.y"
createDatabase(yyattribute(3 - 4).yych);
#line 332 "myparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 185 ".\\myparser.y"
showDatabases();
#line 345 "myparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 186 ".\\myparser.y"
dropDatabase(yyattribute(3 - 4).yych);
#line 358 "myparser.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 187 ".\\myparser.y"
useDatabase(yyattribute(3 - 4).yych);
#line 371 "myparser.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 188 ".\\myparser.y"
createTable(yyattribute(3 - 7).yych,yyattribute(5 - 7).cfdef_var);
#line 384 "myparser.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 189 ".\\myparser.y"
addField(&yyval.cfdef_var,yyattribute(1 - 1).cfdef_var);
#line 397 "myparser.c"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 189 ".\\myparser.y"
addFields(&yyval.cfdef_var,yyattribute(1 - 3).cfdef_var,yyattribute(3 - 3).cfdef_var);
#line 410 "myparser.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 190 ".\\myparser.y"
createField(&yyval.cfdef_var,yyattribute(1 - 2).yych,yyattribute(2 - 2).yych);
#line 423 "myparser.c"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 191 ".\\myparser.y"
getType1(&yyval.yych,yyattribute(1 - 4).yych,yyattribute(3 - 4).yych);
#line 436 "myparser.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 191 ".\\myparser.y"
getType2(&yyval.yych,yyattribute(1 - 1).yych);
#line 449 "myparser.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 192 ".\\myparser.y"
showTables();
#line 462 "myparser.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 193 ".\\myparser.y"
dropTable(yyattribute(3 - 4).yych);
#line 475 "myparser.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 194 ".\\myparser.y"
insertValues(yyattribute(3 - 7).yych,yyattribute(5 - 7).val);
#line 488 "myparser.c"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 195 ".\\myparser.y"
addValue(&yyval.val,yyattribute(1 - 1).val);
#line 501 "myparser.c"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 195 ".\\myparser.y"
addValues(&yyval.val,yyattribute(1 - 3).val,yyattribute(3 - 3).val);
#line 514 "myparser.c"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 196 ".\\myparser.y"
getValue(&yyval.val,yyattribute(1 - 1).yych,1);
#line 527 "myparser.c"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 196 ".\\myparser.y"
getValue(&yyval.val,yyattribute(1 - 1).yych,2);
#line 540 "myparser.c"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 197 ".\\myparser.y"
selectValues(yyattribute(2 - 5).sel_fie,yyattribute(4 - 5).sel_tab,NULL);
#line 553 "myparser.c"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 197 ".\\myparser.y"
selectValues(yyattribute(2 - 7).sel_fie,yyattribute(4 - 7).sel_tab,yyattribute(6 - 7).con);
#line 566 "myparser.c"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 198 ".\\myparser.y"
createFs(&yyval.sel_fie,yyattribute(1 - 1).sel_fie);
#line 579 "myparser.c"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 198 ".\\myparser.y"
createFs(&yyval.sel_fie,NULL);
#line 592 "myparser.c"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 199 ".\\myparser.y"
addTbf(&yyval.sel_fie,yyattribute(1 - 1).sel_fie);
#line 605 "myparser.c"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 199 ".\\myparser.y"
addTbfs(&yyval.sel_fie,yyattribute(1 - 3).sel_fie,yyattribute(3 - 3).sel_fie);
#line 618 "myparser.c"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 200 ".\\myparser.y"
createTbf1(&yyval.sel_fie,yyattribute(1 - 1).yych);
#line 631 "myparser.c"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 200 ".\\myparser.y"
createTbf2(&yyval.sel_fie,yyattribute(1 - 3).yych,yyattribute(3 - 3).yych);
#line 644 "myparser.c"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 201 ".\\myparser.y"
addTab1(&yyval.sel_tab,yyattribute(1 - 3).sel_tab,yyattribute(3 - 3).yych);
#line 657 "myparser.c"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 201 ".\\myparser.y"
addTab2(&yyval.sel_tab,yyattribute(1 - 1).yych);
#line 670 "myparser.c"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 202 ".\\myparser.y"
addCon1(&yyval.con,yyattribute(1 - 1).con);
#line 683 "myparser.c"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 202 ".\\myparser.y"
addCon1(&yyval.con,yyattribute(2 - 3).con);
#line 696 "myparser.c"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 202 ".\\myparser.y"
addCon2(&yyval.con,yyattribute(1 - 3).con,yyattribute(3 - 3).con,'a');
#line 709 "myparser.c"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 202 ".\\myparser.y"
addCon2(&yyval.con,yyattribute(1 - 3).con,yyattribute(3 - 3).con,'o');
#line 722 "myparser.c"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
createCon1(&yyval.con,yyattribute(1 - 3).sel_fie,yyattribute(2 - 3).ch,yyattribute(3 - 3).sel_fie);
#line 735 "myparser.c"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
createCon2(&yyval.con,yyattribute(1 - 3).sel_fie,yyattribute(2 - 3).ch,yyattribute(3 - 3).yych,1);
#line 748 "myparser.c"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
createCon2(&yyval.con,yyattribute(1 - 3).sel_fie,yyattribute(2 - 3).ch,yyattribute(3 - 3).yych,2);
#line 761 "myparser.c"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 204 ".\\myparser.y"
yyval.ch = '=';
#line 774 "myparser.c"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 204 ".\\myparser.y"
yyval.ch = '<';
#line 787 "myparser.c"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 204 ".\\myparser.y"
yyval.ch = '>';
#line 800 "myparser.c"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 204 ".\\myparser.y"
yyval.ch = '!';
#line 813 "myparser.c"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 205 ".\\myparser.y"
updateChan(yyattribute(2 - 7).yych,yyattribute(4 - 7).chan,yyattribute(6 - 7).con);
#line 826 "myparser.c"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 206 ".\\myparser.y"
addChan(&yyval.chan,yyattribute(1 - 1).chan);
#line 839 "myparser.c"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 206 ".\\myparser.y"
addChans(&yyval.chan,yyattribute(1 - 3).chan,yyattribute(3 - 3).chan);
#line 852 "myparser.c"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 207 ".\\myparser.y"
createChan(&yyval.chan,yyattribute(1 - 3).yych,yyattribute(3 - 3).yych,1);
#line 865 "myparser.c"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 207 ".\\myparser.y"
createChan(&yyval.chan,yyattribute(1 - 3).yych,yyattribute(3 - 3).yych,2);
#line 878 "myparser.c"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[7];
			yyinitdebug(yya, 7);
#endif
			{
#line 208 ".\\myparser.y"
deleteValues(yyattribute(3 - 6).yych,yyattribute(5 - 6).con);
#line 891 "myparser.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\'!\'", 33 },
	{ "\'(\'", 40 },
	{ "\')\'", 41 },
	{ "\'*\'", 42 },
	{ "\',\'", 44 },
	{ "\'.\'", 46 },
	{ "\';\'", 59 },
	{ "\'<\'", 60 },
	{ "\'=\'", 61 },
	{ "\'>\'", 62 },
	{ "error", 256 },
	{ "EXIT", 257 },
	{ "CREATE", 258 },
	{ "DATABASE", 259 },
	{ "SHOW", 260 },
	{ "DATABASES", 261 },
	{ "DROP", 262 },
	{ "USE", 263 },
	{ "TABLE", 264 },
	{ "TABLES", 265 },
	{ "INSERT", 266 },
	{ "INTO", 267 },
	{ "SELECT", 268 },
	{ "FROM", 269 },
	{ "OR", 270 },
	{ "WHERE", 271 },
	{ "UPDATE", 272 },
	{ "SET", 273 },
	{ "DELET", 274 },
	{ "AND", 275 },
	{ "ID", 276 },
	{ "NUMBER", 277 },
	{ "CHAR", 278 },
	{ "INT", 279 },
	{ "STRING", 280 },
	{ "\'/n\'", 281 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: statements",
	"statements: statements statement",
	"statements: statement",
	"statements: error \'/n\'",
	"statement: createdb",
	"statement: dropdb",
	"statement: showdb",
	"statement: exit",
	"statement: usedb",
	"statement: createsql",
	"statement: showtb",
	"statement: droptb",
	"statement: insertsql",
	"statement: selectsql",
	"statement: updatesql",
	"statement: deletesql",
	"exit: EXIT \';\'",
	"createdb: CREATE DATABASE ID \';\'",
	"showdb: SHOW DATABASES \';\'",
	"dropdb: DROP DATABASE ID \';\'",
	"usedb: USE DATABASE ID \';\'",
	"createsql: CREATE TABLE ID \'(\' field_types \')\' \';\'",
	"field_types: field_type",
	"field_types: field_types \',\' field_type",
	"field_type: ID type",
	"type: CHAR \'(\' NUMBER \')\'",
	"type: INT",
	"showtb: SHOW TABLES \';\'",
	"droptb: DROP TABLE ID \';\'",
	"insertsql: INSERT INTO ID \'(\' values \')\' \';\'",
	"values: value",
	"values: values \',\' value",
	"value: STRING",
	"value: NUMBER",
	"selectsql: SELECT fields_star FROM tables \';\'",
	"selectsql: SELECT fields_star FROM tables WHERE conditions \';\'",
	"fields_star: table_fields",
	"fields_star: \'*\'",
	"table_fields: table_field",
	"table_fields: table_fields \',\' table_field",
	"table_field: ID",
	"table_field: ID \'.\' ID",
	"tables: tables \',\' ID",
	"tables: ID",
	"conditions: condition",
	"conditions: \'(\' conditions \')\'",
	"conditions: conditions AND conditions",
	"conditions: conditions OR conditions",
	"condition: table_field op table_field",
	"condition: table_field op STRING",
	"condition: table_field op NUMBER",
	"op: \'=\'",
	"op: \'<\'",
	"op: \'>\'",
	"op: \'!\'",
	"updatesql: UPDATE ID SET changes WHERE conditions \';\'",
	"changes: change",
	"changes: changes \',\' change",
	"change: ID \'=\' STRING",
	"change: ID \'=\' NUMBER",
	"deletesql: DELET FROM ID WHERE conditions \';\'"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 2, -1 },
	{ 1, 1, -1 },
	{ 1, 2, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 3, 2, 0 },
	{ 4, 4, 1 },
	{ 5, 3, 2 },
	{ 6, 4, 3 },
	{ 7, 4, 4 },
	{ 8, 7, 5 },
	{ 9, 1, 6 },
	{ 9, 3, 7 },
	{ 10, 2, 8 },
	{ 11, 4, 9 },
	{ 11, 1, 10 },
	{ 12, 3, 11 },
	{ 13, 4, 12 },
	{ 14, 7, 13 },
	{ 15, 1, 14 },
	{ 15, 3, 15 },
	{ 16, 1, 16 },
	{ 16, 1, 17 },
	{ 17, 5, 18 },
	{ 17, 7, 19 },
	{ 18, 1, 20 },
	{ 18, 1, 21 },
	{ 19, 1, 22 },
	{ 19, 3, 23 },
	{ 20, 1, 24 },
	{ 20, 3, 25 },
	{ 21, 3, 26 },
	{ 21, 1, 27 },
	{ 22, 1, 28 },
	{ 22, 3, 29 },
	{ 22, 3, 30 },
	{ 22, 3, 31 },
	{ 23, 3, 32 },
	{ 23, 3, 33 },
	{ 23, 3, 34 },
	{ 24, 1, 35 },
	{ 24, 1, 36 },
	{ 24, 1, 37 },
	{ 24, 1, 38 },
	{ 25, 7, 39 },
	{ 26, 1, 40 },
	{ 26, 3, 41 },
	{ 27, 3, 42 },
	{ 27, 3, 43 },
	{ 28, 6, 44 }
};

int YYNEAR YYDCDECL yytokenaction_size = 275;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 14, YYAT_ACCEPT, 0 },
	{ 100, YYAT_SHIFT, 116 },
	{ 64, YYAT_SHIFT, 77 },
	{ 0, YYAT_ERROR, 0 },
	{ 68, YYAT_SHIFT, 81 },
	{ 85, YYAT_SHIFT, 104 },
	{ 99, YYAT_ERROR, 0 },
	{ 5, YYAT_SHIFT, 31 },
	{ 3, YYAT_SHIFT, 27 },
	{ 122, YYAT_SHIFT, 123 },
	{ 4, YYAT_SHIFT, 29 },
	{ 117, YYAT_SHIFT, 103 },
	{ 5, YYAT_SHIFT, 32 },
	{ 3, YYAT_SHIFT, 28 },
	{ 4, YYAT_SHIFT, 30 },
	{ 108, YYAT_SHIFT, 119 },
	{ 93, YYAT_SHIFT, 73 },
	{ 64, YYAT_SHIFT, 78 },
	{ 108, YYAT_SHIFT, 120 },
	{ 93, YYAT_SHIFT, 74 },
	{ 80, YYAT_SHIFT, 96 },
	{ 109, YYAT_SHIFT, 122 },
	{ 75, YYAT_SHIFT, 92 },
	{ 80, YYAT_SHIFT, 97 },
	{ 99, YYAT_SHIFT, 115 },
	{ 75, YYAT_SHIFT, 93 },
	{ 72, YYAT_SHIFT, 90 },
	{ 70, YYAT_SHIFT, 87 },
	{ 70, YYAT_SHIFT, 88 },
	{ 72, YYAT_SHIFT, 91 },
	{ 103, YYAT_SHIFT, 83 },
	{ 95, YYAT_SHIFT, 114 },
	{ 85, YYAT_SHIFT, 105 },
	{ 85, YYAT_SHIFT, 106 },
	{ 85, YYAT_SHIFT, 107 },
	{ 92, YYAT_SHIFT, 112 },
	{ 91, YYAT_SHIFT, 70 },
	{ 90, YYAT_SHIFT, 110 },
	{ 87, YYAT_SHIFT, 109 },
	{ 84, YYAT_SHIFT, 101 },
	{ 81, YYAT_SHIFT, 66 },
	{ 77, YYAT_SHIFT, 94 },
	{ 66, YYAT_SHIFT, 80 },
	{ 55, YYAT_SHIFT, 69 },
	{ 53, YYAT_SHIFT, 36 },
	{ 52, YYAT_SHIFT, 63 },
	{ 51, YYAT_SHIFT, 62 },
	{ 50, YYAT_SHIFT, 61 },
	{ 49, YYAT_SHIFT, 60 },
	{ 48, YYAT_SHIFT, 59 },
	{ 47, YYAT_SHIFT, 58 },
	{ 44, YYAT_SHIFT, 57 },
	{ 43, YYAT_SHIFT, 56 },
	{ 41, YYAT_SHIFT, 55 },
	{ 40, YYAT_SHIFT, 54 },
	{ 39, YYAT_SHIFT, 53 },
	{ 38, YYAT_SHIFT, 52 },
	{ 36, YYAT_SHIFT, 51 },
	{ 34, YYAT_SHIFT, 50 },
	{ 33, YYAT_SHIFT, 49 },
	{ 32, YYAT_SHIFT, 48 },
	{ 31, YYAT_SHIFT, 47 },
	{ 30, YYAT_SHIFT, 46 },
	{ 29, YYAT_SHIFT, 45 },
	{ 28, YYAT_SHIFT, 44 },
	{ 27, YYAT_SHIFT, 43 },
	{ 10, YYAT_SHIFT, 41 },
	{ 9, YYAT_SHIFT, 40 },
	{ 8, YYAT_SHIFT, 35 },
	{ 7, YYAT_SHIFT, 34 },
	{ 6, YYAT_SHIFT, 33 },
	{ 2, YYAT_SHIFT, 26 },
	{ 1, YYAT_SHIFT, 25 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 64, YYAT_SHIFT, 79 },
	{ 100, YYAT_SHIFT, 102 },
	{ 68, YYAT_SHIFT, 82 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 100, YYAT_SHIFT, 103 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 2 },
	{ 14, YYAT_SHIFT, 3 },
	{ 0, YYAT_SHIFT, 1 },
	{ 14, YYAT_SHIFT, 4 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 5 },
	{ 14, YYAT_SHIFT, 6 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 7 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 8 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 9 },
	{ -1, YYAT_ERROR, 0 },
	{ 14, YYAT_SHIFT, 10 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ 3, 1, YYAT_DEFAULT, 14 },
	{ -209, 1, YYAT_ERROR, 0 },
	{ 12, 1, YYAT_ERROR, 0 },
	{ -251, 1, YYAT_ERROR, 0 },
	{ -251, 1, YYAT_ERROR, 0 },
	{ -252, 1, YYAT_ERROR, 0 },
	{ -189, 1, YYAT_ERROR, 0 },
	{ -198, 1, YYAT_ERROR, 0 },
	{ 26, 1, YYAT_DEFAULT, 53 },
	{ -209, 1, YYAT_ERROR, 0 },
	{ -203, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 4 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 0, 0, YYAT_REDUCE, 16 },
	{ -211, 1, YYAT_ERROR, 0 },
	{ -212, 1, YYAT_ERROR, 0 },
	{ 4, 1, YYAT_ERROR, 0 },
	{ 3, 1, YYAT_ERROR, 0 },
	{ -215, 1, YYAT_ERROR, 0 },
	{ -216, 1, YYAT_ERROR, 0 },
	{ -217, 1, YYAT_ERROR, 0 },
	{ -218, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 37 },
	{ 11, 1, YYAT_REDUCE, 40 },
	{ 0, 0, YYAT_REDUCE, 38 },
	{ -213, 1, YYAT_ERROR, 0 },
	{ 11, 1, YYAT_REDUCE, 36 },
	{ -219, 1, YYAT_ERROR, 0 },
	{ -223, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ -7, 1, YYAT_ERROR, 0 },
	{ 11, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ -9, 1, YYAT_ERROR, 0 },
	{ -10, 1, YYAT_ERROR, 0 },
	{ -11, 1, YYAT_ERROR, 0 },
	{ 7, 1, YYAT_ERROR, 0 },
	{ -230, 1, YYAT_ERROR, 0 },
	{ -231, 1, YYAT_ERROR, 0 },
	{ -232, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 81 },
	{ -228, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_DEFAULT, 91 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 28 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ 0, 0, YYAT_DEFAULT, 93 },
	{ 0, 0, YYAT_REDUCE, 41 },
	{ 0, 0, YYAT_REDUCE, 43 },
	{ -42, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 39 },
	{ -19, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 56 },
	{ -40, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 103 },
	{ -251, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 22 },
	{ -15, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 33 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ -19, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ -235, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 34 },
	{ 0, 0, YYAT_DEFAULT, 103 },
	{ -257, 1, YYAT_ERROR, 0 },
	{ -236, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 103 },
	{ 0, 0, YYAT_DEFAULT, 103 },
	{ -20, 1, YYAT_DEFAULT, 99 },
	{ -28, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 44 },
	{ -2, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ 0, 0, YYAT_REDUCE, 24 },
	{ -22, 1, YYAT_ERROR, 0 },
	{ -240, 1, YYAT_ERROR, 0 },
	{ -24, 1, YYAT_ERROR, 0 },
	{ -261, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 42 },
	{ -28, 1, YYAT_DEFAULT, 99 },
	{ 0, 0, YYAT_REDUCE, 59 },
	{ 0, 0, YYAT_REDUCE, 58 },
	{ 0, 0, YYAT_REDUCE, 57 },
	{ -35, 1, YYAT_DEFAULT, 100 },
	{ -40, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 60 },
	{ 0, 0, YYAT_DEFAULT, 103 },
	{ -10, 1, YYAT_DEFAULT, 53 },
	{ 0, 0, YYAT_REDUCE, 54 },
	{ 0, 0, YYAT_REDUCE, 52 },
	{ 0, 0, YYAT_REDUCE, 51 },
	{ 0, 0, YYAT_REDUCE, 53 },
	{ -262, 1, YYAT_DEFAULT, 53 },
	{ -256, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ 0, 0, YYAT_REDUCE, 29 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ 0, 0, YYAT_REDUCE, 35 },
	{ 0, 0, YYAT_REDUCE, 55 },
	{ 0, 0, YYAT_REDUCE, 45 },
	{ -264, 1, YYAT_REDUCE, 47 },
	{ 0, 0, YYAT_REDUCE, 46 },
	{ 0, 0, YYAT_REDUCE, 50 },
	{ 0, 0, YYAT_REDUCE, 49 },
	{ 0, 0, YYAT_REDUCE, 48 },
	{ -32, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 25 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 40;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 14, 42 },
	{ 14, 12 },
	{ 14, 15 },
	{ 14, 16 },
	{ 14, 11 },
	{ 14, 17 },
	{ 14, 18 },
	{ 8, 38 },
	{ 8, 39 },
	{ 8, 37 },
	{ 14, 19 },
	{ 14, 13 },
	{ 14, 20 },
	{ 108, 121 },
	{ 103, 85 },
	{ 14, 21 },
	{ 103, 118 },
	{ 103, 86 },
	{ 61, 75 },
	{ 61, 76 },
	{ 57, 72 },
	{ 57, 71 },
	{ 102, 117 },
	{ 14, 22 },
	{ 54, 68 },
	{ 54, 67 },
	{ 14, 24 },
	{ 0, 14 },
	{ 0, 23 },
	{ 93, 113 },
	{ 91, 111 },
	{ 85, 108 },
	{ 83, 100 },
	{ 82, 99 },
	{ 81, 98 },
	{ 79, 95 },
	{ 70, 89 },
	{ 69, 84 },
	{ 53, 65 },
	{ 52, 64 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 26, 14 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -11, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -2, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 18, -1 },
	{ 18, -1 },
	{ -2, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 11, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 15, 103 },
	{ 25, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 13, 103 },
	{ 0, -1 },
	{ 7, -1 },
	{ 11, 103 },
	{ 10, 103 },
	{ 0, -1 },
	{ 7, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 20, -1 },
	{ 0, -1 },
	{ 13, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, 103 },
	{ -6, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -7, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 210 ".\\myparser.y"


char nowpath[1024] = "";

void createDatabase(char *s)
{
	if(access(s,0) == 0)	printf("database already exist.\n");
	else
	{
		if(CreateDirectory(s,0))	
		{
			FILE *fp = fopen("sys.dat","a+");
			fprintf(fp,"%s\n",s);
			fclose(fp);
			printf("create database successed.\n");
		}
		else	printf("create database failed\n");
	}
}

void showDatabases()
{
	char s[1024];
	FILE *fp = fopen("sys.dat","r");
	while(~fscanf(fp,"%s",s))	printf("%s\n",s);
	fclose(fp);
}

void dropDatabase(char *s)
{
	FILE *fp1 = fopen("sys.dat","r");
	FILE *fp2 = fopen("t.dat","w");
	if(access(s,0) == -1)	printf("database not exist.\n");
	else
	{
		WIN32_FIND_DATA FindData;
		HANDLE hError;
		char ss[1024] = "";
		strcpy(ss,s);
		strcat(ss,"\\*.dat");
		if((hError = FindFirstFile(ss,&FindData)) != INVALID_HANDLE_VALUE)
		{
			char sss[1024] = "";
			strcpy(sss,s);
			strcat(sss,"\\");
			strcat(sss,FindData.cFileName);
			remove(sss);
			FindClose(hError);
		}
		memset(ss,0,sizeof(ss));
		strcpy(ss,s);
		strcat(ss,"\\*txt");
		while((hError = FindFirstFile(ss,&FindData)) != INVALID_HANDLE_VALUE)
		{
			char sss[1024] = "";
			strcpy(sss,s);
			strcat(sss,"\\");
			strcat(sss,FindData.cFileName);
			remove(sss);
			FindClose(hError);
		}
		while(~fscanf(fp1,"%s",ss))	
		{
			if(strcmp(ss,s) == 0)	continue;
			fprintf(fp2,"%s\n",ss);
		}
		fclose(fp1);
		fclose(fp2);
		remove("sys.dat");
		rename("t.dat","sys.dat");
		if(RemoveDirectory(s))	printf("drop database successed.\n");
		else	printf("drop database failed.\n");
	}
}


void useDatabase(char *s)
{
	if(access(s,0) != 0)	printf("database not exist.\n");
	else 
	{
		memset(nowpath,0,sizeof(nowpath));
		strcpy(nowpath,s);
		strcat(nowpath,"\\");
		printf("now in database %s.\n",s);
	}
}

void createTable(char *s,struct Createfieldsdef *var)
{
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		char ss[1024] = "";
		strcpy(ss,nowpath);
		strcat(ss,s);
		strcat(ss,".txt");
		if(access(ss,0) == 0)	printf("table already exist.\n");
		else
		{
			struct Createfieldsdef *now = var;
			int cnt = 0;
			char sss[1024] = "";
			FILE *fp;
			while(now)
			{
				struct Createfieldsdef *now2 = now->next_fdef;
				while(now2)
				{
					if(strcmp(now->field,now2->field) == 0)	
					{
						printf("create table error.\n");
						return;
					}
					now2 = now2->next_fdef;
				}
				now = now->next_fdef;
			}
			now = var;
			fp = fopen(ss,"a+");
			fclose(fp);
			strcpy(sss,nowpath);
			strcat(sss,"sys.dat");
			fp = fopen(sss,"a+");
			while(now)
			{
				if(now->type == 1)	fprintf(fp,"%s %d %s char %d\n",s,++cnt,now->field,now->length);
				else	fprintf(fp,"%s %d %s int\n",s,++cnt,now->field);
				now = now->next_fdef;
			}
			fclose(fp);
			printf("create table successed.\n");
		}	
	}
}

void addField(struct Createfieldsdef **f1,struct Createfieldsdef *f2)
{
	*f1 = f2;
}

void addFields(struct Createfieldsdef **f1,struct Createfieldsdef *f2,struct Createfieldsdef *f3)
{
    *f1 = f2;
    while(f2->next_fdef)	f2 = f2->next_fdef;
    f2->next_fdef = f3;
}

void createField(struct Createfieldsdef **f,char *s1,char *s2)
{
	*f = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
	(*f)->field = (char *)malloc(strlen(s1)+1);
	strcpy((*f)->field,s1);
	if(s2[0] == 'c')	
	{
		(*f)->type = 1;
		sscanf(s2,"char(%d)",&(*f)->length);
	}
	else	(*f)->type = 2;
	(*f)->next_fdef = NULL;
}

void getType1(char **s,char *s1,char *s2)
{
	*s = (char *)malloc(strlen(s1)+strlen(s2)+3);
	strcpy(*s,s1);
	strcat(*s,"(");
	strcat(*s,s2);
	strcat(*s,")");
}

void getType2(char **s,char *s1)
{
	*s = (char *)malloc(strlen(s1)+1);
	strcpy(*s,s1);
}

void showTables()
{
	char s[1024] = "";
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		FILE *fp;
		char last[1024] = "",ss[1024] = "",sss[1024] = "";
		strcpy(s,nowpath);
		strcat(s,"sys.dat");
		fp = fopen(s,"r");
		while(fgets(ss,1024,fp))
		{
			sscanf(ss,"%s",sss);
			if(strcmp(last,sss))
			{
				printf("%s\n",sss);
				strcpy(last,sss);
			}
		}
		fclose(fp);
	}
}

void dropTable(char *s)
{
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		char ss[1024] = "",sss[1024] = "",s1[1024] = "",s2[1024] = "";
		FILE *fp1,*fp2;
		strcpy(ss,nowpath);
		strcat(ss,s);
		strcat(ss,".txt");
		if(access(ss,0) == -1)	
		{
			printf("table not exist.\n");
			return;
		}
		remove(ss);
		memset(ss,0,sizeof(ss));
		strcpy(ss,nowpath);
		strcat(ss,"sys.dat");
		strcpy(sss,nowpath);
		strcat(sss,"t.dat");
		fp1 = fopen(ss,"r");
		fp2 = fopen(sss,"w");
		while(fgets(s1,1024,fp1))
		{
			sscanf(s1,"%s",s2);
			if(strcmp(s2,s))	fprintf(fp2,"%s",s1);
		}
		fclose(fp1);
		fclose(fp2);
		remove(ss);
		rename(sss,ss);
		printf("drop table successed.\n");
	}
}

void insertValues(char *s,struct Values *val)
{
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		char ss[1024] = "";
		strcpy(ss,nowpath);
		strcat(ss,s);
		strcat(ss,".txt");
		if(access(ss,0) == -1)	printf("table not exist.\n");
		else
		{
			FILE *fp;
			char table[1024],field[1024],type[1024],sss[1024] = "";
			int num,len;
			struct Values *now1;
			struct Createstruct *root2 = (struct Createstruct *)malloc(sizeof(struct Createstruct));
			struct Createfieldsdef *now2,*last;
			root2->fdef = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
			now2 = root2->fdef;
			memset(ss,0,sizeof(ss));
			strcpy(ss,nowpath);
			strcat(ss,"sys.dat");
			fp = fopen(ss,"r");
			while(~fscanf(fp,"%s%d%s%s",table,&num,field,type))
			{
				if(strcmp(type,"char") == 0)	fscanf(fp,"%d",&len);
				if(strcmp(s,table) == 0)
				{
					now2->field = (char *)malloc(strlen(field)+1);
					strcpy(now2->field,field);
					if(strcmp(type,"char") == 0)
					{
						now2->type = 1;
						now2->length = len;
					}	
					else	now2->type = 2;
					now2->next_fdef = (struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
					last = now2;
					now2 = now2->next_fdef;
				}
			}
			last->next_fdef = NULL;
			fclose(fp);
			now1 = val;
			now2 = root2->fdef;
			while(now1 && now2)
			{
				if(now1->type != now2->type)
				{
					printf("insert error.\n");
					return;
				}
				if(now1->type == 1)	strncat(sss,now1->string,now2->length);
				else	strcat(sss,now1->string);
				strcat(sss," ");
				now1 = now1->next_v;
				now2 = now2->next_fdef;
			}
			if(now1 || now2)
			{
				printf("insert error.\n");
				return;
			}
			memset(ss,0,sizeof(ss));
			strcpy(ss,nowpath);
			strcat(ss,s);
			strcat(ss,".txt");
			fp = fopen(ss,"a+");
			fprintf(fp,"%s\n",sss);
			fclose(fp);
			printf("insert successed.\n");
		}	
	}
}

void addValue(struct Values **v1,struct Values *v2)
{
	*v1 = v2;
}

void addValues(struct Values **v1,struct Values *v2,struct Values *v3)
{
	*v1 = v2;
    while(v2->next_v)	v2 = v2->next_v;
    v2->next_v = v3;
}

void getValue(struct Values **v,char *s,int type)
{
	*v = (struct Values *)malloc(sizeof(struct Values));
	(*v)->type = type;
	(*v)->string = (char *)malloc(strlen(s)+1);
	strcpy((*v)->string,s);
	(*v)->next_v = NULL;
}

int isConOk1(struct Values *v,struct Conditions *c)
{
	if(c == NULL)	return 1;
	if(c->op == 'o' || c->op == 'a')	return isConOk1(v,c->left) && isConOk1(v,c->right);
	else
	{
		struct Values *now = v;
		if(c->left->table == NULL)
		{
			while(now && strcmp(now->string,c->left->value))	now = now->next_v;
			if(now == NULL)	return 0;
			c->left->type = now->type;
			c->left->table = (char *)malloc(strlen(now->string)+1);
			strcpy(c->left->table,now->table);
			now = now->next_v;
			while(now && strcmp(now->string,c->left->value))	now = now->next_v;
			if(now != NULL)	return 0;
		}
		else
		{
			while(now && (strcmp(now->string,c->left->value) || strcmp(now->table,c->left->table)))	now = now->next_v;
			if(now == NULL)	return 0;
			c->left->type = now->type;
		}
		if(c->right->type == 0)
		{
			now = v;
			if(c->right->table == NULL)
			{
				while(now && strcmp(now->string,c->right->value))	now = now->next_v;	
				if(now == NULL)	return 0;
				if(c->left->type != now->type)	return 0;
				c->right->table = (char *)malloc(strlen(now->string)+1);
				strcpy(c->right->table,now->table);
				now = now->next_v;
				while(now && strcmp(now->string,c->right->value))	now = now->next_v;
				if(now != NULL)	return 0;
			}
			else
			{
				while(now && (strcmp(now->string,c->right->value) || strcmp(now->table,c->right->table)))	now = now->next_v;
				if(now == NULL)	return 0;
				if(c->left->type != now->type)	return 0;
			}
		}
		else if(c->left->type != c->right->type)	return 0;
		return 1;
	}
}

int isSfOk(struct Selectedfields *f,struct Values *v)
{
	while(f)
	{
		struct Values *now = v;
		if(f->table == NULL)
		{
			while(now && strcmp(now->string,f->field))	now = now->next_v;	
			if(now == NULL)	return 0;
			f->table = (char *)malloc(strlen(now->string)+1);
			strcpy(f->table,now->table);
			now = now->next_v;
			while(now && strcmp(now->string,f->field))	now = now->next_v;
			if(now != NULL)	return 0;	
			
		}
		else
		{
			while(now && (strcmp(now->string,f->field) || strcmp(now->table,f->table)))	now = now->next_v;	
			if(now == NULL)	return 0;
		}
		f = f->next_sf;
	}
	return 1;
}

int isConTrue(struct Values2 *v,struct Conditions *c)
{
	char *v1,*v2;
	int type;
	struct Values2 *now = v;
	if(c == NULL)	return 1;
	if(c->op == 'a')	return isConTrue(v,c->left) && isConTrue(v,c->right);
	if(c->op == 'o')	return isConTrue(v,c->left) || isConTrue(v,c->right);
	while(now && (strcmp(now->table,c->left->table) || strcmp(now->string,c->left->value)))	now = now->next_v;
	type = now->type;
	v1 = (char *)malloc(strlen(now->value)+1);
	strcpy(v1,now->value);
	if(c->right->type == 0)
	{
		now = v;
		while(now && (strcmp(now->table,c->right->table) || strcmp(now->string,c->right->value)))	now = now->next_v;
		v2 = (char *)malloc(strlen(now->value)+1);
		strcpy(v2,now->value);
	}
	else
	{
		v2 = (char *)malloc(strlen(c->right->value));
		strcpy(v2,c->right->value);
	}
	if(type == 1)
	{
		if(c->op == '<')	return strcmp(v1,v2) < 0;
		if(c->op == '=')	return strcmp(v1,v2) == 0;
		if(c->op == '>')	return strcmp(v1,v2) > 0;
		if(c->op == '!')	return strcmp(v1,v2) != 0;
	}
	else 
	{
		int x1 = atoi(v1),x2 = atoi(v2);
		if(c->op == '<')	return x1 < x2;
		if(c->op == '=')	return x1 == x2;
		if(c->op == '>')	return x1 > x2;
		if(c->op == '!')	return x1 != x2;
	}
	return 1;
}

void corssValues(struct Values2 *begin,struct Values2 *now,struct Values *v,struct Selectedfields *f,struct Selectedtables *t,struct Conditions *c)
{
	if(t)
	{
		FILE *fp;
		char s[1024] = "",ss[1024] = "";
		struct Values2 *nowt = now;
		struct Values *vt = v;
		strcpy(s,nowpath);
		strcat(s,t->table);
		strcat(s,".txt");
		fp = fopen(s,"r");
		while(~fscanf(fp,"%s",ss))
		{
			now = nowt;
			v = vt;
			now->table = (char *)malloc(strlen(t->table)+1);
			strcpy(now->table,t->table);
			now->string = (char *)malloc(strlen(v->string)+1);
			strcpy(now->string,v->string);
			now->value = (char *)malloc(strlen(ss)+1);
			strcpy(now->value,ss);
			now->type = v->type;
			now->next_v = (struct Values2 *)malloc(sizeof(struct Values2));
			now = now->next_v;
			now->next_v = NULL;
			while(v->next_v && strcmp(v->next_v->table,t->table) == 0)
			{
				v = v->next_v;
				fscanf(fp,"%s",ss);
				now->table = (char *)malloc(strlen(t->table)+1);
				strcpy(now->table,t->table);
				now->string = (char *)malloc(strlen(v->string)+1);
				strcpy(now->string,v->string);
				now->value = (char *)malloc(strlen(ss)+1);
				strcpy(now->value,ss);
				now->type = v->type;
				now->next_v = (struct Values2 *)malloc(sizeof(struct Values2));
				now = now->next_v;
				now->next_v = NULL;
			}
			corssValues(begin,now,v->next_v,f,t->next_st,c);
		}
		fclose(fp);
	}
	else
	{
		struct Values2 *now = begin,*last;
		while(now->next_v)	
		{
			last = now;
			now = now->next_v;
		}
		last->next_v = NULL;
		if(isConTrue(begin,c))
		{
			printf("(");
			if(f)
			{
				while(f)
				{
					now = begin;
					while(now && (strcmp(now->table,f->table) || strcmp(now->string,f->field)))	now = now->next_v;
					printf("%s",now->value);
					if(f->next_sf)	printf(",");
					f = f->next_sf;
				}
			}
			else
			{
				while(begin)
				{
					printf("%s",begin->value);
					if(begin->next_v)	printf(",");
					begin = begin->next_v;
				}
			}
			printf(")\n");
		}
	}
}

void selectValues(struct Selectedfields *f,struct Selectedtables *t,struct Conditions *c)
{
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		FILE *fp;
		char s[1024] = "",ss[1024] = "",s1[1024] = "",s2[1024] = "",s3[1024] = "",s4[1024] = "";
		struct Values *begin,*last,*v = (struct Values *)malloc(sizeof(struct Values));
		struct Selectedtables *begint = t;
		begin = v;
		while(t)
		{
			memset(ss,0,sizeof(ss));
			strcpy(ss,nowpath);
			strcat(ss,t->table);
			strcat(ss,".txt");
			if(access(ss,0) == -1)
			{
				printf("select error.\n");
				return;
			}
			memset(ss,0,sizeof(ss));
			strcpy(ss,nowpath);
			strcat(ss,"sys.dat");
			fp = fopen(ss,"r");
			while(fgets(ss,1024,fp))
			{
				sscanf(ss,"%s%s%s%s",s1,s2,s3,s4);
				if(strcmp(s1,t->table) == 0)
				{
					if(strcmp(s4,"char") == 0)	v->type = 1;
					else	v->type = 2;
					v->string = (char *)malloc(strlen(s3)+1);
					strcpy(v->string,s3);
					v->table = (char *)malloc(strlen(t->table)+1);
					strcpy(v->table,t->table);
					last = v;
					v->next_v = (struct Values *)malloc(sizeof(struct Values));
					v = v->next_v;
				}
			}
			fclose(fp);
			t = t->next_st;
		}
		last->next_v = NULL;
		if(!isConOk1(begin,c) || !isSfOk(f,begin))	printf("sleect error.\n");
		else
		{
			struct Values2 *v2 = (struct Values2 *)malloc(sizeof(struct Values2));
			v2->next_v = NULL;
			printf("(");
			if(f)
			{
				struct Selectedfields *f2 = f;
				while(f2)
				{
					printf("%s.%s",f2->table,f2->field);
					if(f2->next_sf)	printf(",");
					f2 = f2->next_sf;
				}
			}
			else
			{
				v = begin;
				while(v)
				{
					printf("%s.%s",v->table,v->string);
					if(v->next_v)	printf(",");
					v = v->next_v;
				}
			}
			printf(")\n");
			corssValues(v2,v2,begin,f,begint,c);
		}
	}
}

void createFs(struct Selectedfields **tf1,struct Selectedfields *tf2)
{
	*tf1 = tf2;
}

void addTbf(struct Selectedfields **tf1,struct Selectedfields *tf2)
{
	*tf1 = tf2;
}

void addTbfs(struct Selectedfields **tf1,struct Selectedfields *tf2,struct Selectedfields *tf3)
{
	*tf1 = tf2;
    while(tf2->next_sf)	tf2 = tf2->next_sf;
    tf2->next_sf = tf3;
}

void createTbf1(struct Selectedfields **tf,char *s)
{
	*tf = (struct Selectedfields *)malloc(sizeof(struct Selectedfields));
	(*tf)->table = NULL;
	(*tf)->field = (char *)malloc(strlen(s)+1);
	strcpy((*tf)->field,s);
	(*tf)->next_sf = NULL;
}

void createTbf2(struct Selectedfields **tf,char *s1,char *s2)
{
	*tf = (struct Selectedfields *)malloc(sizeof(struct Selectedfields));
	(*tf)->table = (char *)malloc(strlen(s1)+1);
	strcpy((*tf)->table,s1);
	(*tf)->field = (char *)malloc(strlen(s2)+1);
	strcpy((*tf)->field,s2);
	(*tf)->next_sf = NULL;
}

void addTab1(struct Selectedtables **t1,struct Selectedtables *t2,char *s)
{
	*t1 = t2;
	while(t2->next_st)	t2 = t2->next_st;
	t2->next_st = (struct Selectedtables *)malloc(sizeof(struct Selectedtables));
	t2 = t2->next_st;
	t2->table = (char *)malloc(strlen(s)+1);
	strcpy(t2->table,s);
	t2->next_st = NULL;
}

void addTab2(struct Selectedtables **t1,char *s)
{
	(*t1) = (struct Selectedtables *)malloc(sizeof(struct Selectedtables));
	(*t1)->table = (char *)malloc(strlen(s)+1);
	strcpy((*t1)->table,s);
	(*t1)->next_st = NULL;
}

void addCon1(struct Conditions **c1,struct Conditions *c2)
{
	*c1 = c2;
}

void addCon2(struct Conditions **c1,struct Conditions *c2,struct Conditions *c3,char c)
{
	*c1 = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c1)->op = c;
	(*c1)->left = c2;
	(*c1)->right = c3;
}

void createCon1(struct Conditions **c,struct Selectedfields *t1,char cc,struct Selectedfields *t2)
{
	*c = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->op = cc;
	(*c)->left = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->left->type = 0;
	if(t1->table)	
	{
		(*c)->left->table = (char *)malloc(strlen(t1->table)+1);
		strcpy((*c)->left->table,t1->table);
	}
	else	(*c)->left->table = NULL;
	(*c)->left->value = (char *)malloc(strlen(t1->field)+1);
	strcpy((*c)->left->value,t1->field);
	(*c)->right = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->right->type = 0;
	if(t2->table)
	{
		(*c)->right->table = (char *)malloc(strlen(t2->table)+1);
		strcpy((*c)->right->table,t2->table);
	}
	else	(*c)->right->table = NULL;
	(*c)->right->value = (char *)malloc(strlen(t2->field)+1);
	strcpy((*c)->right->value,t2->field);
}

void createCon2(struct Conditions **c,struct Selectedfields *t,char cc,char *s,int type)
{
	*c = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->op = cc;
	(*c)->left = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->left->type = 0;
	if(t->table)	
	{
		(*c)->left->table = (char *)malloc(strlen(t->table)+1);
		strcpy((*c)->left->table,t->table);
	}
	else	(*c)->left->table = NULL;
	(*c)->left->value = (char *)malloc(strlen(t->field)+1);
	strcpy((*c)->left->value,t->field);
	(*c)->right = (struct Conditions *)malloc(sizeof(struct Conditions));
	(*c)->right->type = type;
	(*c)->right->table = NULL;
	(*c)->right->value = (char *)malloc(strlen(s)+1);
	strcpy((*c)->right->value,s);
}

int isConOk2(char *s,struct Values *v,struct Conditions *c)
{
	if(c->op == 'o' || c->op == 'a')	return isConOk2(s,v,c->left) && isConOk2(s,v,c->right);
	else
	{
		struct Values *now = v;
		if(c->left->table && strcmp(c->left->table,s))	return 0;
		while(v && strcmp(v->string,c->left->value))	v = v->next_v;
		if(v == NULL)	return 0;
		if(c->right->type == 0)
		{
			if(c->right->table && strcmp(c->right->table,s))	return 0;
			while(now && strcmp(now->string,c->right->value))	now = now->next_v;
			if(now == NULL)	return 0;
			if(v->type != now->type)	return 0;
		}
		else if(v->type != c->right->type)	return 0;
		return 1;
	}
}

int isChOk(char *s,struct Values *v,struct Changestruct *ch)
{
	while(ch)
	{
		struct Values *now = v;
		while(v && strcmp(v->string,ch->string))	v = v->next_v;
		if(v == NULL)	return 0;
		if(v->type != ch->type)	return 0;
		ch = ch->next_ch;
	}
	return 1;
}

void changeCon(char *s,struct Conditions *c)
{
	if(c->op == 'a' || c->op == 'o')
	{
		changeCon(s,c->left);
		changeCon(s,c->right);
	}	
	c->left->table = (char *)malloc(strlen(s)+1);
	strcpy(c->left->table,s);
	if(c->right->type == 0)
	{
		c->right->table = (char *)malloc(strlen(s)+1);
		strcpy(c->right->table,s);
	}
}

void updateChan(char *s,struct Changestruct *ch,struct Conditions *c)
{
	char ss[1024] = "",s1[1024] = "",s2[1024] = "",s3[1024] = "",s4[1024] = "";
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		FILE *fp;
		struct Values *begin,*last,*v = (struct Values *)malloc(sizeof(struct Values));
		begin = v;
		strcpy(ss,nowpath);
		strcat(ss,s);
		strcat(ss,".txt");
		if(access(ss,0) == -1)
		{
			printf("table not exist.\n");
			return;
		}
		memset(ss,0,sizeof(ss));
		strcpy(ss,nowpath);
		strcat(ss,"sys.dat");
		fp = fopen(ss,"r");
		while(fgets(ss,1024,fp))
		{
			sscanf(ss,"%s%s%s%s",s1,s2,s3,s4);
			if(strcmp(s,s1) == 0)
			{
				if(strcmp(s4,"char") == 0)	v->type = 1;
				else	v->type = 2;
				v->string = (char *)malloc(strlen(s3)+1);
				strcpy(v->string,s3);
				last = v;
				v->next_v = (struct Values *)malloc(sizeof(struct Values));
				v = v->next_v;
			}
		}
		fclose(fp);
		last->next_v = NULL;
		if(!isConOk2(s,begin,c) || !isChOk(s,begin,ch))	printf("update error.\n");
		else
		{
			FILE *fp2;
			changeCon(s,c);
			memset(s1,0,sizeof(s1));
			strcpy(s1,nowpath);
			strcat(s1,s);
			strcat(s1,".txt");
			memset(s2,0,sizeof(s2));
			strcpy(s2,nowpath);
			strcat(s2,"2.txt");
			fp = fopen(s1,"r");
			fp2 = fopen(s2,"w");
			while(~fscanf(fp,"%s",ss))
			{
				struct Values2 *begin2,*v2 = (struct Values2 *)malloc(sizeof(struct Values2));
				begin2 = v2;
				v = begin;
				v2->table = (char *)malloc(strlen(s)+1);
				strcpy(v2->table,s);
				v2->string = (char *)malloc(strlen(v->string)+1);
				strcpy(v2->string,v->string);
				v2->value = (char *)malloc(strlen(ss)+1);
				strcpy(v2->value,ss);
				v2->type = v->type;
				v2->next_v = NULL;
				while(v->next_v)
				{
					v = v->next_v;
					v2->next_v = (struct Values2 *)malloc(sizeof(struct Values2));
					v2 = v2->next_v;
					fscanf(fp,"%s",ss);
					v2->table = (char *)malloc(strlen(s)+1);
					strcpy(v2->table,s);
					v2->string = (char *)malloc(strlen(v->string)+1);
					strcpy(v2->string,v->string);
					v2->value = (char *)malloc(strlen(ss)+1);
					strcpy(v2->value,ss);
					v2->type = v->type;
					v2->next_v = NULL;
				}
				if(isConTrue(begin2,c))	
				{
					v2 = begin2;
					while(v2)
					{
						struct Changestruct *ch2 = ch;
						while(ch2 && strcmp(ch2->string,v2->string))	ch2 = ch2->next_ch;
						if(ch2)	fprintf(fp2,"%s ",ch2->value);
						else	fprintf(fp2,"%s ",v2->value);
						v2 = v2->next_v;
					}
					fprintf(fp2,"\n");
				}
				else
				{
					v2 = begin2;
					while(v2)
					{
						fprintf(fp2,"%s ",v2->value);
						v2 = v2->next_v;
					}
					fprintf(fp2,"\n");
				}
			}
			fclose(fp);
			fclose(fp2);
			remove(s1);
			rename(s2,s1);
			printf("update successed.\n");
		}
		
	}
}

void addChan(struct Changestruct **ch1,struct Changestruct *ch2)
{
	*ch1 = ch2;
}

void addChans(struct Changestruct **ch1,struct Changestruct *ch2,struct Changestruct *ch3)
{
	*ch1 = ch2;
	while(ch2->next_ch)	ch2 = ch2->next_ch;
	ch2->next_ch = ch3;
}

void createChan(struct Changestruct **ch,char *s1,char *s2,int type)
{
	*ch = (struct Changestruct *)malloc(sizeof(struct Changestruct));
	(*ch)->type = type;
	(*ch)->string = (char *)malloc(strlen(s1));
	strcpy((*ch)->string,s1);
	(*ch)->value = (char *)malloc(strlen(s2));
	strcpy((*ch)->value,s2);
	(*ch)->next_ch = NULL;
}

void deleteValues(char *s,struct Conditions *c)
{
	char ss[1024] = "",s1[1024] = "",s2[1024] = "",s3[1024] = "",s4[1024] = "";
	if(strcmp(nowpath,"") == 0)	printf("please use database first.\n");
	else
	{
		FILE *fp;
		struct Values *begin,*last,*v = (struct Values *)malloc(sizeof(struct Values));
		begin = v;
		strcpy(ss,nowpath);
		strcat(ss,s);
		strcat(ss,".txt");
		if(access(ss,0) == -1)
		{
			printf("table not exist.\n");
			return;
		}	
		memset(ss,0,sizeof(ss));
		strcpy(ss,nowpath);
		strcat(ss,"sys.dat");
		fp = fopen(ss,"r");
		while(fgets(ss,1024,fp))
		{
			sscanf(ss,"%s%s%s%s",s1,s2,s3,s4);
			if(strcmp(s,s1) == 0)
			{
				if(strcmp(s4,"char") == 0)	v->type = 1;
				else	v->type = 2;
				v->string = (char *)malloc(strlen(s3)+1);
				strcpy(v->string,s3);
				last = v;
				v->next_v = (struct Values *)malloc(sizeof(struct Values));
				v = v->next_v;
			}
		}
		fclose(fp);
		last->next_v = NULL;
		if(!isConOk2(s,begin,c))	printf("delete error.\n");
		else
		{
			FILE *fp2;
			changeCon(s,c);
			memset(s1,0,sizeof(s1));
			strcpy(s1,nowpath);
			strcat(s1,s);
			strcat(s1,".txt");
			memset(s2,0,sizeof(s2));
			strcpy(s2,nowpath);
			strcat(s2,"2.txt");
			fp = fopen(s1,"r");
			fp2 = fopen(s2,"w");
			while(~fscanf(fp,"%s",ss))
			{
				struct Values2 *begin2,*v2 = (struct Values2 *)malloc(sizeof(struct Values2));
				begin2 = v2;
				v = begin;
				v2->table = (char *)malloc(strlen(s)+1);
				strcpy(v2->table,s);
				v2->string = (char *)malloc(strlen(v->string)+1);
				strcpy(v2->string,v->string);
				v2->value = (char *)malloc(strlen(ss)+1);
				strcpy(v2->value,ss);
				v2->type = v->type;
				v2->next_v = NULL;
				while(v->next_v)
				{
					v = v->next_v;
					v2->next_v = (struct Values2 *)malloc(sizeof(struct Values2));
					v2 = v2->next_v;
					fscanf(fp,"%s",ss);
					v2->table = (char *)malloc(strlen(s)+1);
					strcpy(v2->table,s);
					v2->string = (char *)malloc(strlen(v->string)+1);
					strcpy(v2->string,v->string);
					v2->value = (char *)malloc(strlen(ss)+1);
					strcpy(v2->value,ss);
					v2->type = v->type;
					v2->next_v = NULL;
				}
				if(!isConTrue(begin2,c))	
				{
					v2 = begin2;
					while(v2)
					{
						fprintf(fp2,"%s ",v2->value);
						v2 = v2->next_v;
					}
					fprintf(fp2,"\n");
				}
			}
			fclose(fp);
			fclose(fp2);
			remove(s1);
			rename(s2,s1);
			printf("delete successed.\n");
		}
	}
}

int main(void)
{
	int cnt = 0;
	while(1)
	{
		printf("SQL [%d]: ",++cnt);
		yyparse();
	}
}

