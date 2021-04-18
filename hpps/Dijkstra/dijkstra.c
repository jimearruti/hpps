#include <stdio.h>
#include <stdlib.h>
#include "heap_publicas.h"
#include "dijkstra.h"

extern ITEM* dist;     //en value va distancia de nodo_inicial a n
extern int* T;	//Es 1 si ya se calculó su distancia
extern int* prev; 


void dijkstra(int* matriz, int n, int nodo_inicial){

		// Inicializo
	for (int i = 0; i < n; i++){
        	dist[i].value = 2147483647;
		dist[i].label = i;
		dist[i].idx = i;
		prev[i] = 2147483647;
		T[i]=0;
  	}

     	dist[nodo_inicial].value = 0;
  
//sin heap--------------------------------------------------------

     	for (int count = 0; count < n-1; count++){


		// Encuentro el elemento con distancia mínima*/

       		int u = minDistance(dist, T, n); 
	

       		// Marco el elemento como procesado
       		T[u] = 1;
  
       		
       		for (int v = 0; v <n; v++)
  
         		if (!T[v] && dist[u].value != 2147483647 && dist[u].value+matriz[v+u*n] < dist[v].value && dist[u].value+matriz[v+u*n]>=dist[u].value){
            			prev[v]=u;
				dist[v].value = dist[u].value + matriz[v+u*n];				
     			}
	}
	
}

void dijkstra_heap(int* matriz, int n, int nodo_inicial){
	
		// Inicializo
	for (int i = 0; i < n; i++){
        	dist[i].value = 2147483647;
		dist[i].label = i;
		dist[i].idx = i;
		prev[i] = 2147483647;
		T[i]=0;
  	}

     	dist[nodo_inicial].value = 0;
//con heap -----------------------------------------------------------------------------
		//Creo heap
		HEAP cola;
		heap_init(&cola,n);
	
		//construyo heap de manera lineal
		buildheap(&cola,n,dist);

		
	for (int count = 0; count < n-1; count++){

		ITEM* pmin=heap_extractMin(&cola);
		ITEM item_minimo=*pmin;
		int u=item_minimo.label;
	 
       		// Marco el item como procesado
       		T[u] = 1;
  
       		// Actualizo distancias
       		for (int v = 0; v <n; v++)
  
         		if (!T[v] && dist[u].value != 2147483647 && dist[u].value+matriz[v+u*n] < dist[v].value && dist[u].value+matriz[v+u*n]>=dist[u].value){
            			prev[v]=u;
				dist[v].value = dist[u].value + matriz[v+u*n];

				//con heap
				heap_updateItem(&cola,&dist[v]);
				
     			}
	}

	heap_delete(&cola);
		
//---------------------------------------------------------------
 
}



int minDistance(ITEM* dist, int* T, int n){

   	// Initialize min value
   	int min = 2147483647;
	int min_index;
  
   	for (int v = 0; v < n; v++)
     		if (T[v] == 0 && dist[v].value < min){
         		min = dist[v].value;
			min_index = v;
  		}
   	return min_index;
}
