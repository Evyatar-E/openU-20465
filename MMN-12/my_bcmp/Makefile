my_bcmp: my_bcmp.o functions.o
	gcc -ansi -Wall -pedantic -g my_bcmp.o functions.o -o $@
my_bcmp.o: my_bcmp.c my_bcmp.h
	gcc -c -ansi -Wall -pedantic -g my_bcmp.c -o $@
functions.o: functions.c my_bcmp.h
	gcc -c -ansi -Wall -pedantic -g functions.c -o $@