%{
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
%}

%union
{
	char ch;
	char *yych;				
	struct Createfieldsdef *cfdef_var;	
	struct Values *val;
	struct Conditions *con;
	struct Selectedfields *sel_fie;
	struct Selectedtables *sel_tab;
	struct Changestruct *chan;
}

%term EXIT CREATE DATABASE SHOW DATABASES DROP USE TABLE TABLES INSERT INTO SELECT FROM OR WHERE UPDATE SET DELET
%left OR
%left AND
%term<yych> ID NUMBER CHAR INT STRING
%nonterm<yych> type
%nonterm<cfdef_var> field_types field_type
%nonterm<val> value values
%nonterm<ch> op
%nonterm<con> condition conditions
%nonterm<sel_fie> table_field table_fields fields_star
%nonterm<sel_tab> tables
%nonterm<chan> change changes

%%

statements:		statements statement | statement | error '/n';
statement:		createdb | dropdb | showdb | exit | usedb | createsql | showtb | droptb | insertsql | selectsql | updatesql | deletesql;
exit:			EXIT ';' {exit(0);};
createdb:		CREATE DATABASE ID ';' {createDatabase($3);};
showdb:			SHOW DATABASES ';' {showDatabases();};
dropdb:			DROP DATABASE ID ';' {dropDatabase($3);};
usedb:			USE DATABASE ID ';' {useDatabase($3);};
createsql:		CREATE TABLE ID '(' field_types ')'	';' {createTable($3,$5);};
field_types:	field_type {addField(&$$,$1);} | field_types ',' field_type {addFields(&$$,$1,$3);};
field_type:		ID type {createField(&$$,$1,$2);};
type:			CHAR '(' NUMBER ')' {getType1(&$$,$1,$3);} | INT {getType2(&$$,$1);};
showtb:			SHOW TABLES ';' {showTables();};
droptb:			DROP TABLE ID ';' {dropTable($3);};
insertsql:		INSERT INTO ID '(' values ')' ';' {insertValues($3,$5);};
values:			value {addValue(&$$,$1);} | values ',' value {addValues(&$$,$1,$3);};
value:			STRING {getValue(&$$,$1,1);} | NUMBER {getValue(&$$,$1,2);};
selectsql: 		SELECT fields_star FROM tables ';' {selectValues($2,$4,NULL);} | SELECT fields_star FROM tables WHERE conditions ';' {selectValues($2,$4,$6);}; 
fields_star: 	table_fields {createFs(&$$,$1);} | '*' {createFs(&$$,NULL);};
table_fields: 	table_field {addTbf(&$$,$1);} | table_fields ',' table_field {addTbfs(&$$,$1,$3);};
table_field: 	ID {createTbf1(&$$,$1);} | ID '.' ID {createTbf2(&$$,$1,$3);};
tables: 		tables ',' ID {addTab1(&$$,$1,$3);} | ID {addTab2(&$$,$1);};
conditions: 	condition {addCon1(&$$,$1);} | '(' conditions ')' {addCon1(&$$,$2);} | conditions AND conditions {addCon2(&$$,$1,$3,'a');} | conditions OR conditions {addCon2(&$$,$1,$3,'o');};
condition:		table_field op table_field {createCon1(&$$,$1,$2,$3);} | table_field op STRING {createCon2(&$$,$1,$2,$3,1);} | table_field op NUMBER {createCon2(&$$,$1,$2,$3,2);};
op:				'=' {$$ = '=';} | '<' {$$ = '<';} | '>' {$$ = '>';} | '!' {$$ = '!';};
updatesql:		UPDATE ID SET changes WHERE conditions ';'{updateChan($2,$4,$6);};
changes:		change {addChan(&$$,$1);} | changes ',' change {addChans(&$$,$1,$3);};
change:			ID '=' STRING {createChan(&$$,$1,$3,1);} | ID '=' NUMBER {createChan(&$$,$1,$3,2);};
deletesql:		DELET FROM ID WHERE conditions ';' {deleteValues($3,$5);};

%%

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
