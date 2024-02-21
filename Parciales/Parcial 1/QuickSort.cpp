#include "QuickSort.h"
#include <chrono>

Nodo* QuickSort::obtenerUltimoNodo(Nodo* cabeza) {
    while (cabeza && cabeza->siguiente) {
        cabeza = cabeza->siguiente;
    }
    return cabeza;
}

Nodo* QuickSort::particionar(Nodo* cabeza, Nodo* fin, Nodo** nuevoInicio, Nodo** nuevoFin) {
    Nodo* pivote = fin;
    Nodo* prev = nullptr;
    Nodo* curr = cabeza;
    Nodo* tail = pivote;

    
    while (curr != pivote) {
        if (curr->Data.getEdad() < pivote->Data.getEdad()) {
            
            if ((*nuevoInicio) == nullptr) {
                (*nuevoInicio) = curr;
            }

            prev = curr;
            curr = curr->siguiente;
        } else { 
            if (prev) {
                prev->siguiente = curr->siguiente;
            }
            Nodo* temp = curr->siguiente;
            curr->siguiente = nullptr;
            tail->siguiente = curr;
            tail = curr;
            curr = temp;
        }
    }
   
    if ((*nuevoInicio) == nullptr) {
        (*nuevoInicio) = pivote;
    }

    (*nuevoFin) = tail;

    return pivote;
}

void QuickSort::quickSortRecursivo(Nodo** cabezaRef, Nodo* fin) {
    if (!*cabezaRef || *cabezaRef == fin) return;

    Nodo* nuevoInicio = nullptr, *nuevoFin = nullptr;

    Nodo* pivote = particionar(*cabezaRef, fin, &nuevoInicio, &nuevoFin);

    if (nuevoInicio != pivote) {
 
        Nodo* temp = nuevoInicio;
        while (temp->siguiente != pivote) {
            temp = temp->siguiente;
        }
        temp->siguiente = nullptr;

        quickSortRecursivo(&nuevoInicio, temp);

        temp = obtenerUltimoNodo(nuevoInicio);
        temp->siguiente = pivote;
    }

    // Ordenar la sublista después del pivote
    quickSortRecursivo(&(pivote->siguiente), nuevoFin);

    // Actualizar la referencia de cabeza si es necesario
    if (*cabezaRef != nuevoInicio) *cabezaRef = nuevoInicio;
}

void QuickSort::ordenar(Lista& lista) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    Nodo* fin = obtenerUltimoNodo(lista.getCabeza());
    quickSortRecursivo(&(lista.cabeza), fin);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Tiempo de ejecución con Quick Sort: " << elapsed_seconds.count() << " segundos" << std::endl;
    this->tiempo = elapsed_seconds.count();
}

double QuickSort::getTiempo() {
    return this->tiempo;
}