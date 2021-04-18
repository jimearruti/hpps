#include "fir.h"
#include "entradas.h"
#include <stdio.h>

sample_t entrada[SIGNAL_LENGTH];
sample_t salida[SIGNAL_LENGTH];
sample_t coefs[TAP_LENGTH];

int main(){
	int j;
	step(entrada,SIGNAL_LENGTH/2,1);
	ini_fir(coefs);
	ini_buffer;

	for(j=0;j<SIGNAL_LENGTH;j++){
		salida[j]=fir(entrada[j]);
/*		printf("e(%d)=%f,y(%d)=%f\n",j,entrada[j],j,salida[j]);*/
	}
}


