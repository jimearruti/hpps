#include "fir.h"
#include "entradas.h"
#include <stdio.h>

sample_t buffer[TAP_LENGTH];
sample_t coefs[TAP_LENGTH];

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
	//guardo la muestra nueva
	for (i=0;i<TAP_LENGTH-1;i++){
		buffer[i]=buffer[i+1];
	}
	buffer[TAP_LENGTH-1]=muestra;

	//proceso buffer
	float suma=0;
	for(i=0;i<TAP_LENGTH;i++){
		suma=suma+buffer[TAP_LENGTH-i-1]*coefs[i];
	}
	
	return suma;

}
