void foo(int i) { 
  foo(i+1);
}

int main(void) { 
  foo(0);
  return 0;
}

/*
• What does this program do when compiled with no optimization?
	Segmentation fault
• What does this program do when compiled with optimizations (i.e., with the -O2 or -O3 flag)?
	No segmentation fault, but program does not exit
• Why did the behaviour change?
	The function foo is called inline, so memory does not run out, but it recurses infinitely
*/