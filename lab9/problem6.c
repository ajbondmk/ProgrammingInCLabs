#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
  int a,b,c;
} st;

int main(void) { 
  st obj = {10,12,15};
  st *p1 = &obj;
  st *p2 = NULL;
  intptr_t n = (intptr_t) &p2->b;
  printf("%li", n);

  printf("%ld\n", *(intptr_t *) ((char*)p1 + n));
  return 0;
}

/*
• Where is the undefined behaviour in this program?
	The NULL pointer p2 gets dereferenced
• Was there a segmentation fault?
	No
• Why or why not?
	The compiler optimised &p2->b to be &p2+4
*/