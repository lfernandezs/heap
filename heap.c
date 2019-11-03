#include <stdlib.h>
#include "heap.h"
#include <stdio.h>

#define TAM_I 31
<<<<<<< HEAD
=======
#define FACTOR_AGRANDAR 2
>>>>>>> branch_ori

/* Definición del struct heap */
struct heap {
    void** datos;
    size_t cant;
    size_t tam; // EN NINGUN MOMENTO EL TAM SE MODIFICA
    cmp_func_t cmp;
};

/* Prototipos de funciones auxiliares */
<<<<<<< HEAD
void upheap(void** arreglo, size_t pos, cmp_func_t* cmp);

/* Primitivas del heap */
heap_t* heap_crear(cmp_func_t* cmp) {
    heap_t* heap = malloc(sizeof(heap));
    if (!heap) return NULL;
    heap->datos = malloc(sizeof(void*) * TAM_I);
    if (!datos) {
=======
void upheap(void** arreglo, size_t pos, cmp_func_t cmp);
void downheap(void** arreglo, size_t tam, size_t pos, cmp_func_t cmp);
void swap(void** arreglo, size_t pos1, size_t pos2);
bool redimensionar(heap_t* heap);
heap_t* heapify(void *arreglo[], size_t n, cmp_func_t cmp);

/* Primitivas del heap */
heap_t *heap_crear(cmp_func_t cmp) {
    heap_t* heap = malloc(sizeof(heap_t));
    if (!heap) return NULL;
    heap->datos = malloc(sizeof(void*) * TAM_I);
    if (!heap->datos) {
>>>>>>> branch_ori
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
<<<<<<< HEAD
    return !heap->cant;
=======
    return heap->cant == 0; //ESTO CAMBIE
>>>>>>> branch_ori
}

bool heap_encolar(heap_t* heap, void* elem) {
    if (heap->cant == heap->tam) {
<<<<<<< HEAD
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
=======
        if (!redimensionar(heap)) return false;//ARREGLO NO ESTA DEFINIDO
    }
    heap->datos[heap->cant] = elem;
    upheap(heap->datos, heap->cant, heap->cmp); //FALTA ENCOLAR EL ELEM
    heap->cant++;
    return true;
}

void *heap_ver_max(const heap_t* heap) {
    if (heap->cant > 0) return heap->datos[0];
    return NULL;
}

void *heap_desencolar(heap_t* heap) {
    if (heap->cant == 0) return NULL;
    void* dato = heap->datos[0];
    heap->datos[0] = heap->datos[heap->cant-1];
    downheap(heap->datos, heap->cant, 0, heap->cmp); //ACA CAMBIE HEAP->CMP
    heap->cant--;
    return dato;
}

void heap_destruir(heap_t* heap, void f(void* e)) {
    if (f) for(size_t i = 0; i < heap->cant; i++) f(heap->datos[i]);
    free(heap->datos);
    free(heap);
}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp) {
    return heapify(arreglo, n, cmp);
}

/* Heapsort */
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
    heap_t* heap = heapify(elementos, cant, cmp);
    if (!heap) return;
    for(int i = heap->cant - 1; i > 0; i--) {
        swap(heap->datos, 0, i);
        downheap(heap->datos, i, 0, heap->cmp);
    }
    for (int i = 0; i < cant; i++) elementos[i] = heap->datos[i];
    heap_destruir(heap, NULL);
}

/* Funciones auxiliares */
void upheap(void** arreglo, size_t pos, cmp_func_t cmp) {
    if (pos == 0) return;
    size_t padre = (pos - 1) / 2;
    if (cmp(arreglo[padre], arreglo[pos]) < 0) {
        swap(arreglo, padre, pos);
        upheap(arreglo, padre, cmp);
    }
>>>>>>> branch_ori
}

void downheap(void** arreglo, size_t tam, size_t pos, cmp_func_t cmp) {
    if (pos >= tam) return;
    size_t padre = pos;
    size_t izq = 2 * pos + 1;
    size_t der = 2 * pos + 2;
    if (izq < tam && cmp(arreglo[padre], arreglo[izq]) < 0) padre = izq;
    if (der < tam && cmp(arreglo[padre], arreglo[der]) < 0) padre = der;
    if (padre != pos) {
        swap(arreglo, pos, padre);
        downheap(arreglo, tam, padre, cmp);
    }
}

void swap(void** arreglo, size_t pos1, size_t pos2) {
    void* aux = arreglo[pos1];
    arreglo[pos1] = arreglo[pos2];
    arreglo[pos2] = aux;
}

<<<<<<< HEAD
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

=======
>>>>>>> branch_ori
bool redimensionar(heap_t* heap) {
    void** datos_nuevo = realloc(heap->datos, sizeof(void*) * FACTOR_AGRANDAR * heap->tam);
    if (!datos_nuevo) return false;
    heap->datos = datos_nuevo;
<<<<<<< HEAD
    return true;
}
=======
    heap->tam *= FACTOR_AGRANDAR;
    return true;
}

heap_t* heapify(void *arreglo[], size_t n, cmp_func_t cmp){
    heap_t* heap = heap_crear(cmp);
    if(!heap) return NULL; 
    for(size_t i = 0; i < n; i++){
        if (heap->cant == heap->tam) if (!redimensionar(heap)) return NULL;    
        heap->datos[i] = arreglo[i];
        heap->cant++;
    }
    for(int i = (heap->cant/2) - 1; i >= 0 ; i--) downheap(heap->datos, heap->cant, i, heap->cmp);
    return heap;
}  
>>>>>>> branch_ori
