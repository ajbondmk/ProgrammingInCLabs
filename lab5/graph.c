#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) {
	Node *r = malloc(sizeof(Node));
	r->marked = false;
	r->value = value;
	r->left = left;
	r->right = right;
	return r;
}

/* Basic Problems */

int size(Node *node) {
	int count = 0;
	if (node && !(node->marked)) {
		node->marked = true;
		count++;
		count += size(node->left);
		count += size(node->right);
	}
	return count;
}

void unmark(Node *node) {
	if (node && node->marked) {
		node->marked = false;
		unmark(node->left);
		unmark(node->right);
	}
}

bool path_from(Node *node1, Node *node2) {
	if (!node1 || !node2) return false;
	if (node1 == node2) return true;
	return (path_from(node1->left, node2) || path_from(node1->right, node2));
}

bool cyclic(Node *node) {
	return (path_from(node->left, node) || path_from(node->right, node));
} 


/* Challenge problems */

void get_nodes(Node *node, Node **dest) {
	/* TODO */
}

void graph_free(Node *node) {
	/* TODO */
}