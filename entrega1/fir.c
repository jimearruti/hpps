#include "fir.h"
#include "entradas.h"
#include <stdio.h>

sample_t buffer[TAP_LENGTH];
sample_t coefs[TAP_LENGTH];
int i;

//inicialización del fir
void ini_fir(sample_t coefs[]){
	for (i=0;i<TAP_LENGTH;i++){
	coefs[i]=(float)1/(float)TAP_LENGTH;
	}

}

//fir

sample_t fir(sample_t muestra){

	//guardo la muestra nueva
	for (i=0;i<TAP_LENGTH-1;i++){
		buffer[i]=buffer[i+1];
/*		printf("el buffer en %d es %f\n",i,buffer[i]);*/
	}
	buffer[TAP_LENGTH-1]=muestra;
/*	printf("el buffer en %d es %f\n",i,buffer[i]);*/

	//proceso buffer
	float suma=0;
	for(i=0;i<TAP_LENGTH;i++){
		suma=suma+buffer[TAP_LENGTH-i-1]*coefs[i];
	}
	
	return suma;

}
