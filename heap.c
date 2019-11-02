#include <stdlib.h>

#define TAM_I 31

/* Definición del struct heap */
struct heap {
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t* cmp;
};

/* Prototipos de funciones auxiliares */
void upheap(void** arreglo, size_t pos, cmp_func_t* cmp);

/* Primitivas del heap */
heap_t* heap_crear(cmp_func_t* cmp) {
    heap_t* heap = malloc(sizeof(heap));
    if (!heap) return NULL;
    heap->datos = malloc(sizeof(void*) * TAM_I);
    if (!datos) {
        free(heap);
        return NULL;
    }
    heap->tam = TAM_I;
    heap->cant = 0;
    heap->cmp = cmp;
    return heap;
}

size_t heap_cantidad(const heap_t* heap) {
    return heap->cant;
}

bool heap_esta_vacio(const heap_t* heap) {
    return !heap->cant;
}

bool heap_encolar(heap_t* heap, void* elem) {
    if (heap->cant == heap->tam) {
        if (!redimensionar(arreglo)) return false;
    heap->cant++;
    upheap(arreglo, cant, heap->cmp);
    return true;
}

void* heap_ver_max(const heap_t* heap) {
    return heap->datos[0];
}

void* heap_desencolar(heap_t* heap) {
    void* dato = heap->datos[0];
    heap->datos[0] = heap->datos[cant-1];
    cant--;
    downheap(heap->datos, heap->tam, 0, cmp);
    return dato;
}

void heap_destruir(heap_t* heap, void f(void* e) {

}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp) {

}

/* Funciones auxiliares */
void upheap(void** arreglo, size_t pos, cmp_func_t* cmp) {
    if (pos == 0) return ;
    size_t padre = (pos - 1) / 2;
    if (cmp(arreglo[padre], arreglo[pos]) < 0) {
        swap(arreglo, padre, pos);
        upheap(arreglo, padre, cmp);
    }
}

void downheap(void** arreglo, size_t tam, size_t pos, cmp_func_t cmp) {
    if (pos >= tam) return;
    size_t padre = pos;
    size_t izq = 2 * pos + 1;
    size_t der = 2 * pos + 2;
    if (izq < tam && cmp(arreglo[padre], arreglo[izq]) < 0)  padre = izq;
    if (der < tam && cmp(arreglo[padre], arreglo[der]) < 0) padre = der;
    if (padre != pos) {
        swap(pos, padre);
        downheap(arreglo, tam, padre, cmp);
    }
}

void swap(void** arreglo, size_t pos1, size_t pos2) {
    void* aux = arreglo[pos1];
    arreglo[pos1] = arreglo[pos2];
    arreglo[pos2] = aux;
}

bool redimensionar(heap_t* heap) {
    void** datos_nuevo = realloc(heap->datos, sizeof(void*) * FACTOR_AGRANDAR * heap->tam);
    if (!datos_nuevo) return false;
    heap->datos = datos_nuevo;
    return true;
}
