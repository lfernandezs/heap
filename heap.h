#include <stdbool.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct heap;
typedef struct heap heap_t;
typedef int (*cmp_func_t) (const void *a, const void *b);

/* ******************************************************************
 *                     PRIMITIVAS DEL HEAP
 * *****************************************************************/
// Crea un heap.
// Post: devuelve un heap vacío.
heap_t* heap_crear();

// Recibe un hash y devuelve la cantidad de elementos que contiene.
size_t heap_cantidad(const heap_t* heap);

// Recibe un hash y devuelve true si está vacío.
bool heap_esta_vacio(const heap_t* heap);

// Recibe un hash y un puntero a void. Encola el elemento
// en el hash.
bool heap_encolar(heap_t* heap, void* elem);

// Devuelve el máximo elemento del hash.
void* heap_ver_max(const heap_t* heap);

// Recibe un hash y desencola un elemento.
void* heap_desencolar(heap_t* heap);

// Destruye el hash.
void heap_destruir(heap_t* heap, void f(void* e);

// Recibe un arreglo y una función de comparación y
// lo convierte en un heap.
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp);