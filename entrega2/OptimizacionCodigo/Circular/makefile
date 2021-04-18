CXX = -c -O3 -funroll-loops -g

testfir : testfir.o firCircularIf2.o entradas.o
	gcc firCircularIf2.o testfir.o entradas.o -o testfir 

testfir.o: testfir.c
	gcc $(CXX) testfir.c

fir.o: firCircularIf2.c
	gcc $(CXX) firCircularIf2.c

entradas.o: entradas.c
	gcc $(CXX) entradas.c

clean: 
	rm -f *.o
