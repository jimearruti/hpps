CXX = -c -O3 -funroll-loops -g

testfir : testfir.o firPunteros.o entradas.o
	gcc firPunteros.o testfir.o entradas.o -o testfir 

testfir.o: testfir.c
	gcc $(CXX) testfir.c

fir.o: firPunteros.c
	gcc $(CXX) firPunteros.c

entradas.o: entradas.c
	gcc $(CXX) entradas.c

clean: 
	rm -f *.o
