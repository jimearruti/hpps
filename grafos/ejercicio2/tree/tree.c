#include "tree.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void read_tree(const char* filename, tree* t)
{
	FILE *fid = fopen(filename, "r");
	if (!fid)
	{
		printf("can't open \"%s\" (%s)",
							filename, strerror(errno));
		exit(1);
	}
	int n;
	int r = fscanf(fid, "%d\n", &n);
	if ((r != 1) || (n <= 0))
	{
		printf("the file \"%s\" has a wrong format", filename);
		exit(1);
	}
	t->n=n;
	t->nodes=malloc(n*sizeof(*(t->nodes)));

	for(int i=0;i<t->n;i++)
	{
		t->nodes[i].id=i;
		t->nodes[i].parent=NULL;
		t->nodes[i].next_sibling=NULL;
		t->nodes[i].first_child=NULL;
	}

	int idx_root;
	fscanf(fid, "%d\n", &idx_root);
	t->root=t->nodes+idx_root;

	for(int i=0;i<t->n;i++)
	{
		int idx = -1;
		fscanf(fid, "%d\n", &idx);
		//printf("%d %d\n", i, idx);
		if (idx > 0)
		{
			node* parent = t->nodes + idx;
			t->nodes[i].parent = parent;

			if (parent->first_child == NULL)
			{
				parent->first_child = t->nodes + i;
			}
			else
			{
				node *aux = parent->first_child;
				while (aux->next_sibling != NULL)
				{
					aux = aux->next_sibling;
				}
				aux->next_sibling = t->nodes + i;
			}
		}
	}
	fclose(fid);
}

void tree_print(tree* t)
{

	for(int i=0;i<t->n;i++)
	{
		node* n=t->nodes+i;
		int idx_s=-1;
		if (n->next_sibling)
			idx_s=ION(t,n->next_sibling);
		int idx_p=-1;
		if (n->parent)
			idx_p=ION(t,n->parent);
		printf("n: %d p: %d s: %d\n",i,idx_p,idx_s);
	}

}

void tree_print_dot(tree* t)
{
	printf("digraph tree{\n");
	for(int i=0;i<t->n;i++)
	{
		node* n=t->nodes+i;
		int idx_p=-1;
		if (n->parent)
			idx_p=ION(t,n->parent);
		if(idx_p>=0)
			printf("%d -> %d\n",idx_p,i);
	}
	printf("}\n");
}


void tree_delete(tree* t)
{
free(t->nodes);
t->n=0;
}
