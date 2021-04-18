#include "fir.h"
#include "entradas.h"
#include <stdio.h>

sample_t buffer[TAP_LENGTH];
sample_t coefs[TAP_LENGTH];
int contador=0;

//inicialización del fir
void ini_fir(sample_t coefs[]){
	int i;
	for (i=0;i<TAP_LENGTH;i++){
	coefs[i]=(float)1/(float)TAP_LENGTH;
	}
}

void ini_buffer(){
	int i;
	for (i=0;i<TAP_LENGTH;i++){
	buffer[i]=0;
	}
}

//fir

sample_t fir(sample_t muestra){
	int i;
	int k=contador%TAP_LENGTH;

	//guardo la muestra nueva
	buffer[k]=muestra;

	//proceso buffer
	float suma=0;
	for(i=k+1;i<TAP_LENGTH;i++){
		suma=suma+buffer[TAP_LENGTH-i+k]*coefs[i];
	}
	for(i=0;i<=k;i++){
		suma=suma+buffer[k-i]*coefs[i];
	}
	contador++;
	
	return suma;

}
