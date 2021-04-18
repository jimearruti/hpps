#include <stdio.h>
#include <stdlib.h>
#include "./tree/tree.h"
#include "dfs.h"

int* visitados;

int main() {
	
	tree arbol;

	read_tree("tree/t3.tree",&arbol);

	visitados=calloc(arbol.n,sizeof(int));

	tree_print(&arbol);

/*	dfs_rec(&arbol,arbol.root);*/
	
	dfs_it(&arbol,arbol.root); 

	free(visitados);

	return 1;

}
