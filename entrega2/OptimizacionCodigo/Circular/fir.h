//defino nuevos tipo de datos
typedef float sample_t;

//definición de constantes
#define TAP_LENGTH 128
#define SIGNAL_LENGTH 1024

//declaración de funciones
void ini_fir( sample_t coefs[]);
void ini_buffer();
sample_t fir(sample_t muestra);

