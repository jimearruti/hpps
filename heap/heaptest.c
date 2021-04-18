#include <stdio.h>
#include <stdlib.h>
#include "heap_publicas.h"



int main(){
	int i; 
	int nodos;
	
	//entrada forzada

/*	nodos=100000;*/

/*	float* entradas=malloc(sizeof(float)*nodos);	*/

/*	for (i=1;i<=nodos;i++){*/
/*		entradas[i-1]=i-1;*/
/*	}*/

	//entradas desde archivo
	FILE*fp=fopen("entradas.txt","r");
	
	//leo cantidad de nodos
	fscanf(fp,"%d",&nodos);
	
	float* entradas=malloc(sizeof(float)*nodos);
	
	//leo entradas
	for(i=0;i<nodos;i++){
		fscanf(fp,"%f",entradas+i);
	}

	fclose(fp);
	
	ITEM* items=malloc(sizeof(ITEM)*nodos);

	//lleno items
	for(i=0;i<nodos;i++){
		items[i].label=entradas[i];
		items[i].value=entradas[i];
		items[i].idx=-1;
	}
	
	HEAP cola;
	heap_init(&cola,nodos);

	//construyo heap de manera sencilla
	for(i=0;i<nodos;i++){
		heap_addItem(&cola,items+i);
	}

	//construyo heap de manera lineal
/*	buildheap(&cola,nodos,items);*/
	

	//imprimo valores del heap

/*	for(i=0;i<nodos;i++){*/
/*		printf("value=%f\n,idx=%d\n",(float)cola.data[i]->value,cola.data[i]->idx);*/
/*	}*/
	

	free(entradas);
	free(items);
	heap_delete(&cola);
	return 1;
}




