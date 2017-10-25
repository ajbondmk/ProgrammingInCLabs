#include <stdio.h>

void foo(int i) { 
  while (i) { 
    /* loop? */
  }
}

int main(void) { 
  foo(1); 
  printf("Done!?\n");
  return 0;
}

/*
• What does this program do when compiled with no optimization?
	Gets stuck in the infinite while loop
• What does this program do when compiled with optimizations (i.e., with the -O2 or -O3 flag)?
	Still gets stuck in the infinite while loop
• What is the undefined behaviour in this program?
	The function foo has no side effects, so does not need to be called
*/