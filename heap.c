#include <stdlib.h>

struct heap {
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t* cmp;
};

heap_t* heap_crear(cmp_func_t* cmp) {

}

size_t heap_cantidad(const heap_t* heap) {

}

bool heap_esta_vacio(const heap_t* heap) {

}

bool heap_encolar(heap_t* heap, void* elem) {

}

void* heap_ver_max(const heap_t* heap) {

}

void* heap_desencolar(heap_t* heap) {

}

void heap_destruir(heap_t* heap, void f(void* e) {

}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp) {
    
}
