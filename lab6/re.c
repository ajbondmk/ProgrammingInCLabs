#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) {
	arena_t arena = malloc(sizeof(struct arena));
	arena->size = size;
	arena->current = 0;
	arena->elts = malloc(size * sizeof(Regexp));
	return arena;
}

void arena_free(arena_t a) {
	free(a->elts);
	free(a);
}

Regexp *re_alloc(arena_t a) {
	if (a->current < a->size) {
		Regexp *exp = a->elts + a->current;
		a->current += 1;
		return exp;
	}
	return NULL;
}

Regexp *re_chr(arena_t a, char c) {
	Regexp *exp = re_alloc(a);
	if (exp) {
		exp->type = CHR;
		exp->data.chr = c;
	}
	return exp;
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) {
	Regexp *exp = re_alloc(a);
	if (exp) {
		exp->type = ALT;
		exp->data.pair.fst = r1;
		exp->data.pair.snd = r2;
	}
	return exp;
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) {
	Regexp *exp = re_alloc(a);
	if (exp) {
		exp->type = SEQ;
		exp->data.pair.fst = r1;
		exp->data.pair.snd = r2;
	}
	return exp;
}

int re_match(Regexp *r, char *s, int i) {
	if (r != NULL) {
		int first;
		switch (r->type) {
		case CHR:
			if (r->data.chr == s[i]) {
				return i + 1;
			}
			break;
		case SEQ:
			first = re_match(r->data.pair.fst, s, i);
			if (first != -1) {
				return re_match(r->data.pair.snd, s, first);
			}
			break;
		case ALT:
			first = re_match(r->data.pair.fst, s, i);
			if (first != -1) return first;
			return re_match(r->data.pair.snd, s, i);
			break;
		}
	}
	return -1;
}



void re_print(Regexp *r) {
	if (r != NULL) {
		switch (r->type) {
		case CHR:
			printf("%c", r->data.chr);
			break;
		case SEQ:
			if (r->data.pair.fst->type == ALT) {
				printf("(");
				re_print(r->data.pair.fst);
				printf(")");
			} else {
				re_print(r->data.pair.fst);
			}
			if (r->data.pair.snd->type == ALT) {
				printf("(");
				re_print(r->data.pair.snd);
				printf(")");
			} else {
				re_print(r->data.pair.snd);
			}
			break;
		case ALT:
			re_print(r->data.pair.fst);
			printf("+");
			re_print(r->data.pair.snd);
			break;
		}
	} else {
		printf("NULL");
	}
}