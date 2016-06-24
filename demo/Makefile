#justify:	justify.o word.o line.o
#	gcc -o justify justify.o word.o line.o
#
#justify.o:	justify.c word.h line.h
#	gcc -c justify.c
#
#word.o:	word.c word.h
#	gcc -c word.c
#
#line.o:	line.c line.h
#	gcc -c line.c


access:		access.o user.o connection.o
	gcc -o access access.o user.o connection.o -lmysqlclient

access.o:	access.c model/user.h db/connection.h
	gcc -c access.c

user.o:		model/user.c model/user.h
	gcc -c model/user.c

connection.o:	db/connection.c db/connection.h db/mysql/include/mysql.h 
	gcc -c db/connection.c 
