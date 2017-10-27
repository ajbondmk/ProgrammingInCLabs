int main(void) { 
  int i = 1;
  while (i > 0){
    i *= 2;
  }
  return 0;
}

/*
• Does this program terminate when compiled with no optimization?
	Yes
• Does this program terminate when compiled with optimizations (i.e., with the -O2 or -O3 flag)?
	No
• What is the undefined behaviour in this program?
	If executed, the while loop will repeat infinitely. However, it causes no side effects, so can be optimised away.
*/