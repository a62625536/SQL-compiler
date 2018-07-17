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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 06/20/18
# Time: 21:45:36
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ ]+

    2  ";"

    3  "("

    4  ")"

    5  ","

    6  ">"

    7  "<"

    8  "="

    9  "!="

   10  "."

   11  "*"

   12  "\n"

   13  create|CREATE

   14  drop|DROP

   15  database|DATABASE

   16  databases|DATABASES

   17  show|SHOW

   18  use|USE

   19  table|TABLE

   20  tables|TABLES

   21  insert|INSERT

   22  into|INTO

   23  select|SELECT

   24  from|FROM

   25  and|AND

   26  or|OR

   27  where|WHERE

   28  update|UPDATE

   29  set|SET

   30  delete|DELETE

   31  exit|EXIT

   32  char|CHAR

   33  int|INT

   34  [A-Za-z][A-Za-z0-9_]*

   35  [0-9]+

   36  "'"[A-Za-z0-9]+"'"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2c               goto 10
	0x2e               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41               goto 17
	0x42               goto 18
	0x43               goto 19
	0x44               goto 20
	0x45               goto 21
	0x46               goto 22
	0x47 - 0x48 (2)    goto 18
	0x49               goto 23
	0x4a - 0x4e (5)    goto 18
	0x4f               goto 24
	0x50 - 0x52 (3)    goto 18
	0x53               goto 25
	0x54               goto 26
	0x55               goto 27
	0x56               goto 18
	0x57               goto 28
	0x58 - 0x5a (3)    goto 18
	0x61               goto 29
	0x62               goto 18
	0x63               goto 30
	0x64               goto 31
	0x65               goto 32
	0x66               goto 33
	0x67 - 0x68 (2)    goto 18
	0x69               goto 34
	0x6a - 0x6e (5)    goto 18
	0x6f               goto 35
	0x70 - 0x72 (3)    goto 18
	0x73               goto 36
	0x74               goto 37
	0x75               goto 38
	0x76               goto 18
	0x77               goto 39
	0x78 - 0x7a (3)    goto 18


state 2
	^INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2c               goto 10
	0x2e               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41               goto 17
	0x42               goto 18
	0x43               goto 19
	0x44               goto 20
	0x45               goto 21
	0x46               goto 22
	0x47 - 0x48 (2)    goto 18
	0x49               goto 23
	0x4a - 0x4e (5)    goto 18
	0x4f               goto 24
	0x50 - 0x52 (3)    goto 18
	0x53               goto 25
	0x54               goto 26
	0x55               goto 27
	0x56               goto 18
	0x57               goto 28
	0x58 - 0x5a (3)    goto 18
	0x61               goto 29
	0x62               goto 18
	0x63               goto 30
	0x64               goto 31
	0x65               goto 32
	0x66               goto 33
	0x67 - 0x68 (2)    goto 18
	0x69               goto 34
	0x6a - 0x6e (5)    goto 18
	0x6f               goto 35
	0x70 - 0x72 (3)    goto 18
	0x73               goto 36
	0x74               goto 37
	0x75               goto 38
	0x76               goto 18
	0x77               goto 39
	0x78 - 0x7a (3)    goto 18


state 3
	match 12


state 4
	0x20               goto 4

	match 1


state 5
	0x3d               goto 40


state 6
	0x30 - 0x39 (10)   goto 41
	0x41 - 0x5a (26)   goto 41
	0x61 - 0x7a (26)   goto 41


state 7
	match 3


state 8
	match 4


state 9
	match 11


state 10
	match 5


state 11
	match 10


state 12
	0x30 - 0x39 (10)   goto 12

	match 35


state 13
	match 2


state 14
	match 7


state 15
	match 8


state 16
	match 6


state 17
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4d (13)   goto 18
	0x4e               goto 42
	0x4f - 0x5a (12)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 18
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 19
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x47 (7)    goto 18
	0x48               goto 43
	0x49 - 0x51 (9)    goto 18
	0x52               goto 44
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 20
	0x30 - 0x39 (10)   goto 18
	0x41               goto 45
	0x42 - 0x44 (3)    goto 18
	0x45               goto 46
	0x46 - 0x51 (12)   goto 18
	0x52               goto 47
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 21
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x57 (23)   goto 18
	0x58               goto 48
	0x59 - 0x5a (2)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 22
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x51 (17)   goto 18
	0x52               goto 49
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 23
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4d (13)   goto 18
	0x4e               goto 50
	0x4f - 0x5a (12)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 24
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x51 (17)   goto 18
	0x52               goto 51
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 25
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 52
	0x46 - 0x47 (2)    goto 18
	0x48               goto 53
	0x49 - 0x5a (18)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 26
	0x30 - 0x39 (10)   goto 18
	0x41               goto 54
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 27
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4f (15)   goto 18
	0x50               goto 55
	0x51 - 0x52 (2)    goto 18
	0x53               goto 56
	0x54 - 0x5a (7)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 28
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x47 (7)    goto 18
	0x48               goto 57
	0x49 - 0x5a (18)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 29
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6d (13)   goto 18
	0x6e               goto 58
	0x6f - 0x7a (12)   goto 18

	match 34


state 30
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x67 (7)    goto 18
	0x68               goto 59
	0x69 - 0x71 (9)    goto 18
	0x72               goto 60
	0x73 - 0x7a (8)    goto 18

	match 34


state 31
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 61
	0x62 - 0x64 (3)    goto 18
	0x65               goto 62
	0x66 - 0x71 (12)   goto 18
	0x72               goto 63
	0x73 - 0x7a (8)    goto 18

	match 34


state 32
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x77 (23)   goto 18
	0x78               goto 64
	0x79 - 0x7a (2)    goto 18

	match 34


state 33
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x71 (17)   goto 18
	0x72               goto 65
	0x73 - 0x7a (8)    goto 18

	match 34


state 34
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6d (13)   goto 18
	0x6e               goto 66
	0x6f - 0x7a (12)   goto 18

	match 34


state 35
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x71 (17)   goto 18
	0x72               goto 51
	0x73 - 0x7a (8)    goto 18

	match 34


state 36
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 67
	0x66 - 0x67 (2)    goto 18
	0x68               goto 68
	0x69 - 0x7a (18)   goto 18

	match 34


state 37
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 69
	0x62 - 0x7a (25)   goto 18

	match 34


state 38
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6f (15)   goto 18
	0x70               goto 70
	0x71 - 0x72 (2)    goto 18
	0x73               goto 71
	0x74 - 0x7a (7)    goto 18

	match 34


state 39
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x67 (7)    goto 18
	0x68               goto 72
	0x69 - 0x7a (18)   goto 18

	match 34


state 40
	match 9


state 41
	0x27               goto 73
	0x30 - 0x39 (10)   goto 41
	0x41 - 0x5a (26)   goto 41
	0x61 - 0x7a (26)   goto 41


state 42
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x43 (3)    goto 18
	0x44               goto 74
	0x45 - 0x5a (22)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 43
	0x30 - 0x39 (10)   goto 18
	0x41               goto 75
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 44
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 76
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 45
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 77
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 46
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4b (11)   goto 18
	0x4c               goto 78
	0x4d - 0x5a (14)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 47
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4e (14)   goto 18
	0x4f               goto 79
	0x50 - 0x5a (11)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 48
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x48 (8)    goto 18
	0x49               goto 80
	0x4a - 0x5a (17)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 49
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4e (14)   goto 18
	0x4f               goto 81
	0x50 - 0x5a (11)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 50
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x52 (18)   goto 18
	0x53               goto 82
	0x54               goto 83
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 51
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 26


state 52
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4b (11)   goto 18
	0x4c               goto 84
	0x4d - 0x53 (7)    goto 18
	0x54               goto 85
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 53
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4e (14)   goto 18
	0x4f               goto 86
	0x50 - 0x5a (11)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 54
	0x30 - 0x39 (10)   goto 18
	0x41               goto 18
	0x42               goto 87
	0x43 - 0x5a (24)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 55
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x43 (3)    goto 18
	0x44               goto 88
	0x45 - 0x5a (22)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 56
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 89
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 57
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 90
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 58
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x63 (3)    goto 18
	0x64               goto 74
	0x65 - 0x7a (22)   goto 18

	match 34


state 59
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 91
	0x62 - 0x7a (25)   goto 18

	match 34


state 60
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 92
	0x66 - 0x7a (21)   goto 18

	match 34


state 61
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 93
	0x75 - 0x7a (6)    goto 18

	match 34


state 62
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6b (11)   goto 18
	0x6c               goto 94
	0x6d - 0x7a (14)   goto 18

	match 34


state 63
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6e (14)   goto 18
	0x6f               goto 95
	0x70 - 0x7a (11)   goto 18

	match 34


state 64
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x68 (8)    goto 18
	0x69               goto 96
	0x6a - 0x7a (17)   goto 18

	match 34


state 65
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6e (14)   goto 18
	0x6f               goto 97
	0x70 - 0x7a (11)   goto 18

	match 34


state 66
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x72 (18)   goto 18
	0x73               goto 98
	0x74               goto 99
	0x75 - 0x7a (6)    goto 18

	match 34


state 67
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6b (11)   goto 18
	0x6c               goto 100
	0x6d - 0x73 (7)    goto 18
	0x74               goto 85
	0x75 - 0x7a (6)    goto 18

	match 34


state 68
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6e (14)   goto 18
	0x6f               goto 101
	0x70 - 0x7a (11)   goto 18

	match 34


state 69
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 18
	0x62               goto 102
	0x63 - 0x7a (24)   goto 18

	match 34


state 70
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x63 (3)    goto 18
	0x64               goto 103
	0x65 - 0x7a (22)   goto 18

	match 34


state 71
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 89
	0x66 - 0x7a (21)   goto 18

	match 34


state 72
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 104
	0x66 - 0x7a (21)   goto 18

	match 34


state 73
	match 36


state 74
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 25


state 75
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x51 (17)   goto 18
	0x52               goto 105
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 76
	0x30 - 0x39 (10)   goto 18
	0x41               goto 106
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 77
	0x30 - 0x39 (10)   goto 18
	0x41               goto 107
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 78
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 108
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 79
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4f (15)   goto 18
	0x50               goto 109
	0x51 - 0x5a (10)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 80
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 110
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 81
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4c (12)   goto 18
	0x4d               goto 111
	0x4e - 0x5a (13)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 82
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 112
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 83
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4e (14)   goto 18
	0x4f               goto 113
	0x50 - 0x5a (11)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 33


state 84
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 114
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 85
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 29


state 86
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x56 (22)   goto 18
	0x57               goto 115
	0x58 - 0x5a (3)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 87
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x4b (11)   goto 18
	0x4c               goto 116
	0x4d - 0x5a (14)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 88
	0x30 - 0x39 (10)   goto 18
	0x41               goto 117
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 89
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 18


state 90
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x51 (17)   goto 18
	0x52               goto 118
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 91
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x71 (17)   goto 18
	0x72               goto 105
	0x73 - 0x7a (8)    goto 18

	match 34


state 92
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 119
	0x62 - 0x7a (25)   goto 18

	match 34


state 93
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 120
	0x62 - 0x7a (25)   goto 18

	match 34


state 94
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 121
	0x66 - 0x7a (21)   goto 18

	match 34


state 95
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6f (15)   goto 18
	0x70               goto 109
	0x71 - 0x7a (10)   goto 18

	match 34


state 96
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 110
	0x75 - 0x7a (6)    goto 18

	match 34


state 97
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6c (12)   goto 18
	0x6d               goto 111
	0x6e - 0x7a (13)   goto 18

	match 34


state 98
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 122
	0x66 - 0x7a (21)   goto 18

	match 34


state 99
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6e (14)   goto 18
	0x6f               goto 113
	0x70 - 0x7a (11)   goto 18

	match 33


state 100
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 123
	0x66 - 0x7a (21)   goto 18

	match 34


state 101
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x76 (22)   goto 18
	0x77               goto 115
	0x78 - 0x7a (3)    goto 18

	match 34


state 102
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x6b (11)   goto 18
	0x6c               goto 124
	0x6d - 0x7a (14)   goto 18

	match 34


state 103
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 125
	0x62 - 0x7a (25)   goto 18

	match 34


state 104
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x71 (17)   goto 18
	0x72               goto 126
	0x73 - 0x7a (8)    goto 18

	match 34


state 105
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 32


state 106
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 127
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 107
	0x30 - 0x39 (10)   goto 18
	0x41               goto 18
	0x42               goto 128
	0x43 - 0x5a (24)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 108
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 129
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 109
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 14


state 110
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 31


state 111
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 24


state 112
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x51 (17)   goto 18
	0x52               goto 130
	0x53 - 0x5a (8)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 113
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 22


state 114
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x42 (2)    goto 18
	0x43               goto 131
	0x44 - 0x5a (23)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 115
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 17


state 116
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 132
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 117
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 133
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 118
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 134
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 119
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 135
	0x75 - 0x7a (6)    goto 18

	match 34


state 120
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 18
	0x62               goto 136
	0x63 - 0x7a (24)   goto 18

	match 34


state 121
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 137
	0x75 - 0x7a (6)    goto 18

	match 34


state 122
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x71 (17)   goto 18
	0x72               goto 138
	0x73 - 0x7a (8)    goto 18

	match 34


state 123
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x62 (2)    goto 18
	0x63               goto 139
	0x64 - 0x7a (23)   goto 18

	match 34


state 124
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 140
	0x66 - 0x7a (21)   goto 18

	match 34


state 125
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 141
	0x75 - 0x7a (6)    goto 18

	match 34


state 126
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 134
	0x66 - 0x7a (21)   goto 18

	match 34


state 127
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 142
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 128
	0x30 - 0x39 (10)   goto 18
	0x41               goto 143
	0x42 - 0x5a (25)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 129
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 144
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 130
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 145
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 131
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x53 (19)   goto 18
	0x54               goto 146
	0x55 - 0x5a (6)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 132
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x52 (18)   goto 18
	0x53               goto 147
	0x54 - 0x5a (7)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 19


state 133
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 148
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 134
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 27


state 135
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 142
	0x66 - 0x7a (21)   goto 18

	match 34


state 136
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61               goto 149
	0x62 - 0x7a (25)   goto 18

	match 34


state 137
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 144
	0x66 - 0x7a (21)   goto 18

	match 34


state 138
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 145
	0x75 - 0x7a (6)    goto 18

	match 34


state 139
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x73 (19)   goto 18
	0x74               goto 146
	0x75 - 0x7a (6)    goto 18

	match 34


state 140
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x72 (18)   goto 18
	0x73               goto 147
	0x74 - 0x7a (7)    goto 18

	match 19


state 141
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 148
	0x66 - 0x7a (21)   goto 18

	match 34


state 142
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 13


state 143
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x52 (18)   goto 18
	0x53               goto 150
	0x54 - 0x5a (7)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 144
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 30


state 145
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 21


state 146
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 23


state 147
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 20


state 148
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 28


state 149
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x72 (18)   goto 18
	0x73               goto 151
	0x74 - 0x7a (7)    goto 18

	match 34


state 150
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x44 (4)    goto 18
	0x45               goto 152
	0x46 - 0x5a (21)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 34


state 151
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x64 (4)    goto 18
	0x65               goto 153
	0x66 - 0x7a (21)   goto 18

	match 34


state 152
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x52 (18)   goto 18
	0x53               goto 154
	0x54 - 0x5a (7)    goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 15


state 153
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x72 (18)   goto 18
	0x73               goto 154
	0x74 - 0x7a (7)    goto 18

	match 15


state 154
	0x30 - 0x39 (10)   goto 18
	0x41 - 0x5a (26)   goto 18
	0x5f               goto 18
	0x61 - 0x7a (26)   goto 18

	match 16


#############################################################################
# Summary
#############################################################################

1 start state(s)
36 expression(s), 154 state(s)


#############################################################################
# End of File
#############################################################################
