#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char a[2];

    a[0] = 'a';

    if(!strcmp(a, "a")) {
        puts("a is \"a\"");
    }

    return 0;
}

/*
• What does this program do when compiled with no optimization?
	Fails the if condition
• What does this program do when compiled with optimizations (i.e., with the -O2 or -O3 flag)?
	Passes the if condition
• What is the undefined behaviour in this program?
	a[1] is being used without being defined
*/