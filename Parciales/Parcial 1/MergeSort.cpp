#include "MergeSort.h"
#include <chrono>

Nodo* MergeSort::encontrarMitad(Nodo* cabeza) {
    Nodo* rapido = cabeza->siguiente;
    Nodo* lento = cabeza;

    while (rapido && rapido->siguiente) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    return lento;
}

Nodo* MergeSort::unirListas(Nodo* lista1, Nodo* lista2) {
    Nodo dummyHead; 
    Nodo* tail = &dummyHead; 

    while (lista1 && lista2) {
        if (lista1->Data <= lista2->Data) {
            tail->siguiente = lista1;
            lista1 = lista1->siguiente;
        } else {
            tail->siguiente = lista2;
            lista2 = lista2->siguiente;
        }
        tail = tail->siguiente;
    }

    tail->siguiente = lista1 ? lista1 : lista2;
    return dummyHead.siguiente; 
}

Nodo* MergeSort::mergeSort(Nodo* cabeza) {
    if (!cabeza || !cabeza->siguiente) {
        return cabeza;
    }
    Nodo* mitad = encontrarMitad(cabeza);
    Nodo* siguienteDeMitad = mitad->siguiente;
    mitad->siguiente = nullptr;

    Nodo* izquierda = mergeSort(cabeza);
    Nodo* derecha = mergeSort(siguienteDeMitad);

    return unirListas(izquierda, derecha);
    
}

void MergeSort::ordenar(Lista& lista) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    lista.cabeza = mergeSort(lista.getCabeza());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Tiempo de ejecución con Merge Sort: " << elapsed_seconds.count() << " segundos" << std::endl;
    this->tiempo = elapsed_seconds.count();
}

double MergeSort::getTiempo() {
    return this->tiempo;
}


