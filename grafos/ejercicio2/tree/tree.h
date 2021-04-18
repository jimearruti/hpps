/*
 * File:   tree.h
 * Author: juan
 *
 * Created on May 7, 2013, 11:06 AM
 */

#ifndef TREE_H
#define	TREE_H

/**
 * Node of a tree
 */
struct _node
{
	int id;
	struct _node* parent;
	struct _node* first_child;
	struct _node* next_sibling;
};

typedef struct _node node;

/**
 * Directed tree
 */
typedef struct
{
	node* root;
	int n;
	node* nodes;
}tree;

#define ION(t,n) n-t->nodes

void read_tree(const char* filename, tree* t);
void tree_print(tree* t);
void tree_print_dot(tree* t);
void tree_delete(tree* t);

#endif	/* TREE_H */

