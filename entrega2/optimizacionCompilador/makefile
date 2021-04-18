CXX = -c -O3 -funroll-loops -g

testfir : testfir.o fir.o entradas.o
	gcc fir.o testfir.o entradas.o -o testfir 

testfir.o: testfir.c
	gcc $(CXX) testfir.c

fir.o: fir.c
	gcc $(CXX) fir.c

entradas.o: entradas.c
	gcc $(CXX) entradas.c

clean: 
	rm -f *.o
