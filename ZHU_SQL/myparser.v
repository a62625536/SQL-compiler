#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 10 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 06/20/18
# Time: 21:45:36
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : statements $end

    1  statements : statements statement
    2             | statement
    3             | error '/n'

    4  statement : createdb
    5            | dropdb
    6            | showdb
    7            | exit
    8            | usedb
    9            | createsql
   10            | showtb
   11            | droptb
   12            | insertsql
   13            | selectsql
   14            | updatesql
   15            | deletesql

   16  exit : EXIT ';'

   17  createdb : CREATE DATABASE ID ';'

   18  showdb : SHOW DATABASES ';'

   19  dropdb : DROP DATABASE ID ';'

   20  usedb : USE DATABASE ID ';'

   21  createsql : CREATE TABLE ID '(' field_types ')' ';'

   22  field_types : field_type
   23              | field_types ',' field_type

   24  field_type : ID type

   25  type : CHAR '(' NUMBER ')'
   26       | INT

   27  showtb : SHOW TABLES ';'

   28  droptb : DROP TABLE ID ';'

   29  insertsql : INSERT INTO ID '(' values ')' ';'

   30  values : value
   31         | values ',' value

   32  value : STRING
   33        | NUMBER

   34  selectsql : SELECT fields_star FROM tables ';'
   35            | SELECT fields_star FROM tables WHERE conditions ';'

   36  fields_star : table_fields
   37              | '*'

   38  table_fields : table_field
   39               | table_fields ',' table_field

   40  table_field : ID
   41              | ID '.' ID

   42  tables : tables ',' ID
   43         | ID

   44  conditions : condition
   45             | '(' conditions ')'
   46             | conditions AND conditions
   47             | conditions OR conditions

   48  condition : table_field op table_field
   49            | table_field op STRING
   50            | table_field op NUMBER

   51  op : '='
   52     | '<'
   53     | '>'
   54     | '!'

   55  updatesql : UPDATE ID SET changes WHERE conditions ';'

   56  changes : change
   57          | changes ',' change

   58  change : ID '=' STRING
   59         | ID '=' NUMBER

   60  deletesql : DELET FROM ID WHERE conditions ';'


##############################################################################
# States
##############################################################################

state 0
	$accept : . statements $end

	error  shift 1
	EXIT  shift 2
	CREATE  shift 3
	SHOW  shift 4
	DROP  shift 5
	USE  shift 6
	INSERT  shift 7
	SELECT  shift 8
	UPDATE  shift 9
	DELET  shift 10

	dropdb  goto 11
	exit  goto 12
	droptb  goto 13
	statements  goto 14
	createdb  goto 15
	showdb  goto 16
	usedb  goto 17
	createsql  goto 18
	showtb  goto 19
	insertsql  goto 20
	selectsql  goto 21
	updatesql  goto 22
	statement  goto 23
	deletesql  goto 24


state 1
	statements : error . '/n'

	'/n'  shift 25


state 2
	exit : EXIT . ';'

	';'  shift 26


state 3
	createdb : CREATE . DATABASE ID ';'
	createsql : CREATE . TABLE ID '(' field_types ')' ';'

	DATABASE  shift 27
	TABLE  shift 28


state 4
	showdb : SHOW . DATABASES ';'
	showtb : SHOW . TABLES ';'

	DATABASES  shift 29
	TABLES  shift 30


state 5
	dropdb : DROP . DATABASE ID ';'
	droptb : DROP . TABLE ID ';'

	DATABASE  shift 31
	TABLE  shift 32


state 6
	usedb : USE . DATABASE ID ';'

	DATABASE  shift 33


state 7
	insertsql : INSERT . INTO ID '(' values ')' ';'

	INTO  shift 34


state 8
	selectsql : SELECT . fields_star FROM tables ';'
	selectsql : SELECT . fields_star FROM tables WHERE conditions ';'

	'*'  shift 35
	ID  shift 36

	table_field  goto 37
	fields_star  goto 38
	table_fields  goto 39


state 9
	updatesql : UPDATE . ID SET changes WHERE conditions ';'

	ID  shift 40


state 10
	deletesql : DELET . FROM ID WHERE conditions ';'

	FROM  shift 41


state 11
	statement : dropdb .  (5)

	.  reduce 5


state 12
	statement : exit .  (7)

	.  reduce 7


state 13
	statement : droptb .  (11)

	.  reduce 11


state 14
	$accept : statements . $end  (0)
	statements : statements . statement

	$end  accept
	EXIT  shift 2
	CREATE  shift 3
	SHOW  shift 4
	DROP  shift 5
	USE  shift 6
	INSERT  shift 7
	SELECT  shift 8
	UPDATE  shift 9
	DELET  shift 10

	dropdb  goto 11
	exit  goto 12
	droptb  goto 13
	createdb  goto 15
	showdb  goto 16
	usedb  goto 17
	createsql  goto 18
	showtb  goto 19
	insertsql  goto 20
	selectsql  goto 21
	updatesql  goto 22
	statement  goto 42
	deletesql  goto 24


state 15
	statement : createdb .  (4)

	.  reduce 4


state 16
	statement : showdb .  (6)

	.  reduce 6


state 17
	statement : usedb .  (8)

	.  reduce 8


state 18
	statement : createsql .  (9)

	.  reduce 9


state 19
	statement : showtb .  (10)

	.  reduce 10


state 20
	statement : insertsql .  (12)

	.  reduce 12


state 21
	statement : selectsql .  (13)

	.  reduce 13


state 22
	statement : updatesql .  (14)

	.  reduce 14


state 23
	statements : statement .  (2)

	.  reduce 2


state 24
	statement : deletesql .  (15)

	.  reduce 15


state 25
	statements : error '/n' .  (3)

	.  reduce 3


state 26
	exit : EXIT ';' .  (16)

	.  reduce 16


state 27
	createdb : CREATE DATABASE . ID ';'

	ID  shift 43


state 28
	createsql : CREATE TABLE . ID '(' field_types ')' ';'

	ID  shift 44


state 29
	showdb : SHOW DATABASES . ';'

	';'  shift 45


state 30
	showtb : SHOW TABLES . ';'

	';'  shift 46


state 31
	dropdb : DROP DATABASE . ID ';'

	ID  shift 47


state 32
	droptb : DROP TABLE . ID ';'

	ID  shift 48


state 33
	usedb : USE DATABASE . ID ';'

	ID  shift 49


state 34
	insertsql : INSERT INTO . ID '(' values ')' ';'

	ID  shift 50


state 35
	fields_star : '*' .  (37)

	.  reduce 37


state 36
	table_field : ID .  (40)
	table_field : ID . '.' ID

	'.'  shift 51
	.  reduce 40


state 37
	table_fields : table_field .  (38)

	.  reduce 38


state 38
	selectsql : SELECT fields_star . FROM tables ';'
	selectsql : SELECT fields_star . FROM tables WHERE conditions ';'

	FROM  shift 52


state 39
	fields_star : table_fields .  (36)
	table_fields : table_fields . ',' table_field

	','  shift 53
	.  reduce 36


state 40
	updatesql : UPDATE ID . SET changes WHERE conditions ';'

	SET  shift 54


state 41
	deletesql : DELET FROM . ID WHERE conditions ';'

	ID  shift 55


state 42
	statements : statements statement .  (1)

	.  reduce 1


state 43
	createdb : CREATE DATABASE ID . ';'

	';'  shift 56


state 44
	createsql : CREATE TABLE ID . '(' field_types ')' ';'

	'('  shift 57


state 45
	showdb : SHOW DATABASES ';' .  (18)

	.  reduce 18


state 46
	showtb : SHOW TABLES ';' .  (27)

	.  reduce 27


state 47
	dropdb : DROP DATABASE ID . ';'

	';'  shift 58


state 48
	droptb : DROP TABLE ID . ';'

	';'  shift 59


state 49
	usedb : USE DATABASE ID . ';'

	';'  shift 60


state 50
	insertsql : INSERT INTO ID . '(' values ')' ';'

	'('  shift 61


state 51
	table_field : ID '.' . ID

	ID  shift 62


state 52
	selectsql : SELECT fields_star FROM . tables ';'
	selectsql : SELECT fields_star FROM . tables WHERE conditions ';'

	ID  shift 63

	tables  goto 64


state 53
	table_fields : table_fields ',' . table_field

	ID  shift 36

	table_field  goto 65


state 54
	updatesql : UPDATE ID SET . changes WHERE conditions ';'

	ID  shift 66

	change  goto 67
	changes  goto 68


state 55
	deletesql : DELET FROM ID . WHERE conditions ';'

	WHERE  shift 69


state 56
	createdb : CREATE DATABASE ID ';' .  (17)

	.  reduce 17


state 57
	createsql : CREATE TABLE ID '(' . field_types ')' ';'

	ID  shift 70

	field_type  goto 71
	field_types  goto 72


state 58
	dropdb : DROP DATABASE ID ';' .  (19)

	.  reduce 19


state 59
	droptb : DROP TABLE ID ';' .  (28)

	.  reduce 28


state 60
	usedb : USE DATABASE ID ';' .  (20)

	.  reduce 20


state 61
	insertsql : INSERT INTO ID '(' . values ')' ';'

	NUMBER  shift 73
	STRING  shift 74

	values  goto 75
	value  goto 76


state 62
	table_field : ID '.' ID .  (41)

	.  reduce 41


state 63
	tables : ID .  (43)

	.  reduce 43


state 64
	selectsql : SELECT fields_star FROM tables . ';'
	selectsql : SELECT fields_star FROM tables . WHERE conditions ';'
	tables : tables . ',' ID

	','  shift 77
	';'  shift 78
	WHERE  shift 79


state 65
	table_fields : table_fields ',' table_field .  (39)

	.  reduce 39


state 66
	change : ID . '=' STRING
	change : ID . '=' NUMBER

	'='  shift 80


state 67
	changes : change .  (56)

	.  reduce 56


state 68
	updatesql : UPDATE ID SET changes . WHERE conditions ';'
	changes : changes . ',' change

	','  shift 81
	WHERE  shift 82


state 69
	deletesql : DELET FROM ID WHERE . conditions ';'

	'('  shift 83
	ID  shift 36

	conditions  goto 84
	table_field  goto 85
	condition  goto 86


state 70
	field_type : ID . type

	CHAR  shift 87
	INT  shift 88

	type  goto 89


state 71
	field_types : field_type .  (22)

	.  reduce 22


state 72
	createsql : CREATE TABLE ID '(' field_types . ')' ';'
	field_types : field_types . ',' field_type

	')'  shift 90
	','  shift 91


state 73
	value : NUMBER .  (33)

	.  reduce 33


state 74
	value : STRING .  (32)

	.  reduce 32


state 75
	insertsql : INSERT INTO ID '(' values . ')' ';'
	values : values . ',' value

	')'  shift 92
	','  shift 93


state 76
	values : value .  (30)

	.  reduce 30


state 77
	tables : tables ',' . ID

	ID  shift 94


state 78
	selectsql : SELECT fields_star FROM tables ';' .  (34)

	.  reduce 34


state 79
	selectsql : SELECT fields_star FROM tables WHERE . conditions ';'

	'('  shift 83
	ID  shift 36

	conditions  goto 95
	table_field  goto 85
	condition  goto 86


state 80
	change : ID '=' . STRING
	change : ID '=' . NUMBER

	NUMBER  shift 96
	STRING  shift 97


state 81
	changes : changes ',' . change

	ID  shift 66

	change  goto 98


state 82
	updatesql : UPDATE ID SET changes WHERE . conditions ';'

	'('  shift 83
	ID  shift 36

	conditions  goto 99
	table_field  goto 85
	condition  goto 86


state 83
	conditions : '(' . conditions ')'

	'('  shift 83
	ID  shift 36

	conditions  goto 100
	table_field  goto 85
	condition  goto 86


state 84
	conditions : conditions . AND conditions
	deletesql : DELET FROM ID WHERE conditions . ';'
	conditions : conditions . OR conditions

	';'  shift 101
	OR  shift 102
	AND  shift 103


state 85
	condition : table_field . op NUMBER
	condition : table_field . op STRING
	condition : table_field . op table_field

	'!'  shift 104
	'<'  shift 105
	'='  shift 106
	'>'  shift 107

	op  goto 108


state 86
	conditions : condition .  (44)

	.  reduce 44


state 87
	type : CHAR . '(' NUMBER ')'

	'('  shift 109


state 88
	type : INT .  (26)

	.  reduce 26


state 89
	field_type : ID type .  (24)

	.  reduce 24


state 90
	createsql : CREATE TABLE ID '(' field_types ')' . ';'

	';'  shift 110


state 91
	field_types : field_types ',' . field_type

	ID  shift 70

	field_type  goto 111


state 92
	insertsql : INSERT INTO ID '(' values ')' . ';'

	';'  shift 112


state 93
	values : values ',' . value

	NUMBER  shift 73
	STRING  shift 74

	value  goto 113


state 94
	tables : tables ',' ID .  (42)

	.  reduce 42


state 95
	conditions : conditions . AND conditions
	selectsql : SELECT fields_star FROM tables WHERE conditions . ';'
	conditions : conditions . OR conditions

	';'  shift 114
	OR  shift 102
	AND  shift 103


state 96
	change : ID '=' NUMBER .  (59)

	.  reduce 59


state 97
	change : ID '=' STRING .  (58)

	.  reduce 58


state 98
	changes : changes ',' change .  (57)

	.  reduce 57


state 99
	conditions : conditions . AND conditions
	updatesql : UPDATE ID SET changes WHERE conditions . ';'
	conditions : conditions . OR conditions

	';'  shift 115
	OR  shift 102
	AND  shift 103


state 100
	conditions : conditions . AND conditions
	conditions : '(' conditions . ')'
	conditions : conditions . OR conditions

	')'  shift 116
	OR  shift 102
	AND  shift 103


state 101
	deletesql : DELET FROM ID WHERE conditions ';' .  (60)

	.  reduce 60


state 102
	conditions : conditions OR . conditions

	'('  shift 83
	ID  shift 36

	conditions  goto 117
	table_field  goto 85
	condition  goto 86


state 103
	conditions : conditions AND . conditions

	'('  shift 83
	ID  shift 36

	conditions  goto 118
	table_field  goto 85
	condition  goto 86


state 104
	op : '!' .  (54)

	.  reduce 54


state 105
	op : '<' .  (52)

	.  reduce 52


state 106
	op : '=' .  (51)

	.  reduce 51


state 107
	op : '>' .  (53)

	.  reduce 53


state 108
	condition : table_field op . NUMBER
	condition : table_field op . STRING
	condition : table_field op . table_field

	ID  shift 36
	NUMBER  shift 119
	STRING  shift 120

	table_field  goto 121


state 109
	type : CHAR '(' . NUMBER ')'

	NUMBER  shift 122


state 110
	createsql : CREATE TABLE ID '(' field_types ')' ';' .  (21)

	.  reduce 21


state 111
	field_types : field_types ',' field_type .  (23)

	.  reduce 23


state 112
	insertsql : INSERT INTO ID '(' values ')' ';' .  (29)

	.  reduce 29


state 113
	values : values ',' value .  (31)

	.  reduce 31


state 114
	selectsql : SELECT fields_star FROM tables WHERE conditions ';' .  (35)

	.  reduce 35


state 115
	updatesql : UPDATE ID SET changes WHERE conditions ';' .  (55)

	.  reduce 55


state 116
	conditions : '(' conditions ')' .  (45)

	.  reduce 45


state 117
	conditions : conditions . AND conditions
	conditions : conditions OR conditions .  (47)
	conditions : conditions . OR conditions

	AND  shift 103
	.  reduce 47


state 118
	conditions : conditions AND conditions .  (46)
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	.  reduce 46


state 119
	condition : table_field op NUMBER .  (50)

	.  reduce 50


state 120
	condition : table_field op STRING .  (49)

	.  reduce 49


state 121
	condition : table_field op table_field .  (48)

	.  reduce 48


state 122
	type : CHAR '(' NUMBER . ')'

	')'  shift 123


state 123
	type : CHAR '(' NUMBER ')' .  (25)

	.  reduce 25


##############################################################################
# Summary
##############################################################################

37 token(s), 29 nonterminal(s)
61 grammar rule(s), 124 state(s)


##############################################################################
# End of File
##############################################################################
