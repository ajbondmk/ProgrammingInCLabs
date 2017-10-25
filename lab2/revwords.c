#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) {
	char c;
	int i, j;
	for (i = start, j = end; i < j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

int find_next_start(char str[], int len, int i) {
	for (; i < len; i++) {
		char thisChar = str[i];
		if ((thisChar >= 'A' && thisChar <= 'Z')
			|| (thisChar >= 'a' && thisChar <= 'z')) {
			return i;
		}
	}
	return -1;
}

int find_next_end(char str[], int len, int i) {
	for (; i < len; i++) {
		char thisChar = str[i];
		if (thisChar < 'A'
			|| (thisChar > 'Z' && thisChar < 'a')
			|| thisChar > 'z') {
			return i;
		}
	}
	return len;
}

void reverse_words(char s[]) {
	int length = strlen(s);
	int next_start = find_next_start(s, length, 0);
	while (next_start >= 0) {
		int next_end = find_next_end(s, length, next_start);
		reverse_substring(s, next_start, next_end - 1);
		next_start = find_next_start(s, length, next_end);
	}
}