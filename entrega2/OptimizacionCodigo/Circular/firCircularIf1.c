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
	int k;	
	//guardo la muestra nueva
	
	buffer[contador]=muestra;
	k=contador+TAP_LENGTH;
	
	//proceso buffer
	float suma=0;
	
	for(i=contador+1;i<TAP_LENGTH;i++){
		suma=suma+buffer[k-i]*coefs[i];
	}
	for(i=0;i<TAP_LENGTH;i++){
		suma=suma+buffer[contador-i]*coefs[i];
	}
	
	contador++;
	
	if (contador==TAP_LENGTH)
		contador=0;

	return suma;

}
