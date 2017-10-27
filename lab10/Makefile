DEBUG_FLAGS = -g -fno-omit-frame-pointer -Wall -pedantic

all:
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c lab10.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c parse.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c expr.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -o lab10 lab10.o parse.o expr.o 

clean:
	rm -f lab10 lab10.o parse.o expr.o 

run: all
	./lab10 "3"
	./lab10 "3+4"
	./lab10 "3+4*5"
	./lab10 "3+4*5+2"
	./lab10 "3+4*(5+2)"
	./lab10 "(3+4)*(5+2)"
	./lab10 "1 + 2"
	./lab10 "1-2"