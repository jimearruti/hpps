CXX = -c -g -std=c99 -pedantic-errors -Wall -Wextra #-Werror

treetest : treetest.o tree.o dfs.o
	gcc treetest.o tree.o dfs.o -lm -o treetest 

treetest.o: treetest.c
	gcc $(CXX) treetest.c

dfs.o: dfs.c
	gcc $(CXX) dfs.c

tree.o: tree/tree.c
	gcc $(CXX) tree/tree.c

clean: 
	rm -f *.o
