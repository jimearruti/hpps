#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "heap_publicas.h"

ITEM* dist;
int* T;
int* prev;

int main(){
	
	FILE*fp=fopen("matrices/k_0010.mat","r");
	
	int n,m,i,nodo_inicial,nodo_final;

 

	//leo cantidad de filas y columnas
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);

	//reservo memoria para matriz
	int* A=malloc(sizeof(int)*n*m);

	
	//Accedo a A(n+m) como A(n+j*m)
	for(i=0;i<n*m;i++){
		fscanf(fp,"%d",A+i);
	}
	fclose(fp);
	
	//Reservo memora
	dist=malloc(sizeof(ITEM)*n);     //Item con distancia de nodo_inicial a n
	T=malloc(sizeof(int)*n);    	//Es 1 si ya se calculó su distancia
	prev=malloc(sizeof(int)*n); // Array con los nodos que constituyen en camino más corto

	//Leo nodo inicial de entrada estándar
	
	printf("Escriba el nodo inicial:\n");
	scanf("%d",&nodo_inicial);

	//Leo nodo final de entrada estándar
	
	printf("Escriba el nodo final:\n");
	scanf("%d",&nodo_final);



	//Dijkstra

/*	dijkstra(A,n,nodo_inicial);*/
	dijkstra_heap(A,n,nodo_inicial);

	//Imprimo salida	
	int nodos_camino[n-2];
	int cant_nodos_camino=0;

	for (i=0;i<n-2;i++){
		nodos_camino[i]=-1;
	}	

	for(i=nodo_final;prev[i]!=nodo_inicial;){
		nodos_camino[cant_nodos_camino]=prev[i];
		i=prev[i];
		cant_nodos_camino++;
	}
	
	fp=fopen("salida.txt","w");


	fprintf(fp,"%d #número de nodos\n",cant_nodos_camino+2);
	
	fprintf(fp,"%d #nodos del camino en orden (comenzando con el inicial)\n",nodo_inicial);


	for(i=cant_nodos_camino-1;i>=0;i--){
	fprintf(fp,"%d\n",nodos_camino[i]);
	}
	
	fprintf(fp,"%d\n",nodo_final);

	fprintf(fp,"%d #costo total del camino\n ",dist[nodo_final].value);
	
	fclose(fp);

	//libero memoria
	free(A);
	free(dist);
	free(prev);
	free(T);
	
}
