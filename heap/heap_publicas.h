
//Definición de estructuras
typedef struct
{
 int label;
 float value;
 int idx;
} ITEM;

typedef struct
{
int n;
int n_max;
ITEM** data;
} HEAP;



//Declaración de funciones

int heap_isEmpty(HEAP *h);
int heap_isFull(HEAP*h);
int heap_init(HEAP* h, long size);
void heap_delete(HEAP* h);
int heap_addItem(HEAP* h, ITEM* p);
void heap_updateItem(HEAP* h, ITEM *p);
ITEM* heap_extractMin(HEAP* h);
ITEM* heap_queryMin(HEAP* h);

void buildheap(HEAP* h, int n, ITEM* entradas);
float find_minimum(float* entradas, int n);
float extract_minimum(float* entradas, int n);
