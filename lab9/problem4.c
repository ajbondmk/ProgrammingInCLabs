#include <stdio.h>

int *G;

int f(void) {
  int l = 1;
  int res = *G;
  G = &l;
  return res;
}

int main(void) {
  int x = 2;
  G = &x;
  f();
  printf("%d\n", f());
}

/*
• What does this program print when compiled with no optimization?
	Prints 1
• What does this program print when compiled with optimizations (i.e., with the -O2 or -O3 flag)?
	Prints 0
• What is the undefined behaviour in this program?
	When the function f returns, l is destroyed, but G still points to l.
*/