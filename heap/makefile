CXX = -c -g -std=c99 -pedantic-errors -Wall -Wextra -Werror

heaptest : heaptest.o heap_publicas.o heap_privadas.o
	gcc heaptest.o heap_publicas.o heap_privadas.o -lm -o heaptest 

heaptest.o: heaptest.c
	gcc $(CXX) heaptest.c

heap_privadas.o: heap_privadas.c
	gcc $(CXX) heap_privadas.c

heap_publicas.o: heap_publicas.c
	gcc $(CXX) heap_publicas.c

clean: 
	rm -f *.o
