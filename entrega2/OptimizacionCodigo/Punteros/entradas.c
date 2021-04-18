#include "fir.h"
#include "entradas.h"
#include <stdio.h>

int i;

void step (sample_t arreglo[], int tsubida, sample_t altura){
	for(i=0;i<tsubida;i++){
		arreglo[i]=0;
	}
	for(i=tsubida;i<SIGNAL_LENGTH;i++){
		arreglo[i]=altura;
	}

}

void impulso(sample_t arreglo[], int tsubida, sample_t altura){
	for(i=0;i<SIGNAL_LENGTH;i++){
		arreglo[i]=0;
	}
	arreglo[tsubida]=altura;

}
