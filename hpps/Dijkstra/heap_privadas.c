#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap_publicas.h"
#include "heap_privadas.h"



void move_up(HEAP* h, int i){
	int j;	
	
	for(j=i;j>0&&((h->data[j]->value)<(h->data[parent(j)]->value));){ 
	//si existe el padre y el valor del nodo es menor que el valor del padre
		swap(h,j,parent(j));
		j=parent(j);
	}	
}

void move_down(HEAP* h, int i){
	int j;
	
	for(j=i;(right(j)<=h->n)&&(((h->data[right(j)]->value)<(h->data[j]->value))||((h->data[left(j)]->value)<(h->data[j]->value)));){ 
	//existe el hijo derecho y algun hijo tiene valor menor que el nodo
		
	//el más chico es el derecho
		if ((h->data[right(j)]->value)<(h->data[left(j)]->value)){ 
			swap(h,j,right(j));
			j=right(j);	
		}
		//el izquierdo es menor o igual	
		else {
			swap(h,j,left(j));
			j=left(j);
		}				
	}
		
		if ((left(parent(j))<=h->n)&&((h->data[left(parent(j))]->value)<(h->data[parent(j)]->value)))
			swap(h,j,left(parent(j)));				
}

void swap(HEAP* h, int i, int j){
	ITEM* aux=h->data[i];
	h->data[i]=h->data[j];
	h->data[i]->idx=i;
	h->data[j]=aux;
	h->data[j]->idx=j;
}

int left(int i){
return 2*i+1;
}

int right(int i){
return 2*i+2;
}

int parent(int i){
return floor((i-1)/2);
}

void MinHeapify(HEAP* h, int i){
	int izq=left(i);
	int der=right(i);
	int smallest;

	if (der<h->n && (h->data[der]->value<h->data[izq]->value))
		smallest=der;
	else if (izq<h->n)
		smallest=izq;
	else smallest=i;
	
	if (h->data[smallest]->value<h->data[i]->value){
		swap(h,i,smallest);
		MinHeapify(h,smallest);
	}
		
}

void lleno_heap(HEAP* h, int n, ITEM* items){
	int i;
	for (i=0;i<n;i++){
		int ultimo_lleno=h->n;
		h->data[ultimo_lleno]=items+i;
		h->data[ultimo_lleno]->idx=ultimo_lleno;
		h->n=ultimo_lleno+1;
	}

}
