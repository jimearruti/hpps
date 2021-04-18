#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE*fp=fopen("matriz_binaria.txt","r");
	
	int n,m,i,j;
	

	//leo cantidad de filas y columnas
	fscanf(fp,"%d %d",&n,&m);

	//reservo memoria para matriz
	int* A=malloc(sizeof(int)*n*m);

	int grado[m];
	int vertices[m];
	
	//Accedo a A(n+m) como A(n+j*m)
	for(i=0;i<n*m;i++){
		fscanf(fp,"%d",A+i);
	}

	for(j=0;j<m;j++){
		grado[j]=0;
		for(i=0;i<n;i++){
			grado[j]=grado[j]+A[i+j*m];
		}
	}
	
	for(j=0;j<m;j++){
		vertices[j]=0;
	}

	for(j=0;j<m;j++){
		vertices[grado[j]]=vertices[grado[j]]+1;
	}
	
	for(j=0;j<m;j++){
		printf("%d ",vertices[j]);
	}
	printf("\n");

	fclose(fp);

	free(A);	

	
}
