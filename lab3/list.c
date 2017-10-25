#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List *cons(int head, List *tail) {
	/* malloc() will be explained in the next lecture! */
	List *cell = malloc(sizeof(List));
	cell->head = head;
	cell->tail = tail;
	return cell;
}

int sum(List *list) {
	if (list) return list->head + sum(list->tail);
	return 0;
}

void iterate(int (*f)(int), List *list) {
	if (list) {
		list->head = f(list->head);
		iterate(f, list->tail);
	}
}

void print_list(List *list) {
	printf("[");
	bool firstItem = true;
	List *currentItem = list;
	while (currentItem) {
		if (firstItem) {
			firstItem = false;
		}
		else {
			printf(", ");
		}
		printf("%d", currentItem->head);
		currentItem = currentItem->tail;
	}
	printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) {
	/* TODO */
	return NULL;  
}

void split(List *list, List **list1, List **list2) {
	/* TODO */
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}