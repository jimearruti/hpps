testfir : testfir.o fir.o entradas.o
	gcc fir.o testfir.o entradas.o -o testfir

testfir.o: testfir.c
	gcc -c -g testfir.c

fir.o: fir.c
	gcc -c -g fir.c

entradas.o: entradas.c
	gcc -c -g entradas.c
