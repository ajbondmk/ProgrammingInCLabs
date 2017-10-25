#include <stdlib.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) {
	if (tree == NULL) return 0;
	if (tree->value == x) return 1;
	if (tree->value > x) return tree_member(x, tree->left);
	return tree_member(x, tree->right);
}

Tree *tree_insert(int x, Tree *tree) {
	if (tree == NULL) {
		Tree *newTree = malloc(sizeof(Tree));
		newTree->left = NULL;
		newTree->value = x;
		newTree->right = NULL;
		return newTree;
	}
	if (x == tree->value) return tree;
	if (x < tree->value) tree->left = tree_insert(x, tree->left);
	else tree->right = tree_insert(x, tree->right);
	return tree;
}

void tree_free(Tree *tree) {
	if (tree == NULL) return;
	tree_free(tree->left);
	tree_free(tree->right);
	free(tree);
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
	/* TODO */
}

Tree *tree_remove(int x, Tree *tree) { 
	/* TODO */
	return empty;
}