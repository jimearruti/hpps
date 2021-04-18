
//Declaración de funciones

void move_up(HEAP* h, int i);
void move_down(HEAP* h, int i);
void swap(HEAP* h, int i, int j);
int left(int i);
int right(int i);
int parent(int i);

void MinHeapify(HEAP* h, int i);
void lleno_heap(HEAP* h, int n, ITEM* items);
