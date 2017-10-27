all:
	gcc -Wall -pedantic -c lab8.c
	gcc -Wall -pedantic -c parse.c
	gcc -Wall -pedantic -c expr.c
	gcc -o lab8 lab8.o parse.o expr.o 

clean:
	rm -f lab8 lab8.o parse.o expr.o 

run: all
	./lab8 "3"
	./lab8 "3+4"
	./lab8 "3+4*5"
	./lab8 "3+4*5+2"
	./lab8 "3+4*(5+2)"
	./lab8 "(3+4)*(5+2)"
	./lab8 "1 + 2"
	./lab8 "1-2"