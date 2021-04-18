#include "fir.h"
#include "entradas.h"
#include <stdio.h>


sample_t coefs[TAP_LENGTH];
sample_t buffer[TAP_LENGTH];
sample_t* pi=buffer;

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
	*pi=0;
	pi++;
	}
	pi=buffer;
}

//fir

sample_t fir(sample_t muestra){
	int i;
	//guardo la muestra nueva
	*pi=muestra;
	
	//proceso buffer
	float suma=0;
	for(i=contador+1;i<TAP_LENGTH;i++){
		suma=suma+*(pi-i+TAP_LENGTH)*coefs[i];
	}

	for(i=0;i<=contador;i++){
		suma=suma+*(pi-i)*coefs[i];
	}
	
	
	//acomodo puntero para la siguiente llamada	
	pi++;
	contador++;
	if (contador==TAP_LENGTH){
		contador=0;
		pi=buffer;
	}
	return suma;
	
}
