#include <stdio.h>
#include "./tree/tree.h"
#include "dfs.h"

void dfs_rec(tree* t, node*n){

	visitados[n->id]=1;

	
	if ((n->first_child!=0) && (visitados[n->first_child->id]==0)) {
		dfs_rec(t,&(t->nodes[n->first_child->id]));

	}
	else if ((n->next_sibling!=0) && (visitados[n->next_sibling->id]==0)){
		printf("nodo leído: %d\n",n->id);
		dfs_rec(t,&(t->nodes[n->next_sibling->id]));
	}
	else{
		printf("nodo leído: %d\n",n->id);
		if (n->parent!=0) dfs_rec(t,&(t->nodes[n->parent->id]));	 
	}

}


void dfs_it(tree* t, node*n){
	

	node* nodo=n;
	
	for(;visitados[nodo->id]==0;){
		visitados[nodo->id]=1;
		if (nodo->first_child!=0) nodo=nodo->first_child;
		else{
			
			for(;nodo->next_sibling==0;){
				printf("nodo leído: %d\n",nodo->id);
				if (nodo==t->root) return;
				nodo=nodo->parent;
			}

			printf("nodo leído: %d\n",nodo->id);
			nodo=nodo->next_sibling;

		}
	}

}
	


