#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap_publicas.h"
#include "heap_privadas.h"

int heap_isEmpty(HEAP*h){
	if (h->n==0) return 1;
	else return 0;
}

int heap_isFull(HEAP*h){
	if (h->n==h->n_max) return 1;
	else return 0;
}

int heap_init(HEAP* h, long size){
	h->n=0;
	h->n_max=size;
	h->data=malloc(sizeof(int)*size);
	return 1;
}

void heap_delete(HEAP* h){
	h->n=0;
	h->n_max=0;
	free(h->data);
}

int heap_addItem(HEAP* h, ITEM* p){
	if (!heap_isFull(h)){
		int ultimo_lleno=h->n;
		h->data[ultimo_lleno]=p;
		h->data[ultimo_lleno]->idx=ultimo_lleno;
		h->n=ultimo_lleno+1;
		move_up(h,ultimo_lleno);
	return 1;
	}
	
	else return 0;	
}

void heap_updateItem(HEAP* h, ITEM *p){
	int value_nodo=h->data[p->idx]->value;
	int value_parent=h->data[parent(p->idx)]->value;
	if (value_nodo<value_parent)
		move_up(h,p->idx);
	else move_down(h,p->idx);
}


ITEM* heap_extractMin(HEAP* h){
	ITEM* min=h->data[0];
	h->data[0]=h->data[h->n-1];
	h->n=h->n-1;
	move_down(h,0);
	return min;
}

ITEM* heap_queryMin(HEAP* h){
	return h->data[0];
}

void buildheap(HEAP* h, int n, ITEM* items){
	int i;
	//lleno el heap con valores sin orden
	
	lleno_heap(h, n, items);
	
	for (i=floor((n-1)/2);i>=0;i--){
		MinHeapify(h,i);
	}
}


float find_minimum(float* entradas, int n){
	int i;
	int minimo=0;
	for (i=1;i<n;i++){
		if ((entradas[i])<entradas[minimo])
			minimo=i;
	}
	
	return entradas[minimo];
}

float extract_minimum(float* entradas, int n){
	int i;
	int minimo=0;
	for (i=1;i<n;i++){
		if ((entradas[i])<entradas[minimo])
			minimo=i;
	}
	
	float valor_minimo= entradas[minimo];
	
	entradas[minimo]=INFINITY;
		
	return valor_minimo;
}

