#include "BubbleSort.h"
#include <chrono>

void BubbleSort::bubbleSort(Lista& lista) {
    Nodo* cabeza = lista.cabeza;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return; 
    }

    bool intercambio = true;
    while (intercambio) {
        intercambio = false;
        Nodo* actual = cabeza;
        Nodo* siguiente = cabeza->siguiente;
        Nodo* anterior = nullptr; 

        while (siguiente != nullptr) {
            if (actual->Data > siguiente->Data) {
                if (anterior != nullptr) {
                    
                    anterior->siguiente = siguiente;
                } else {
                    
                    lista.cabeza = siguiente;
                }

                actual->siguiente = siguiente->siguiente;
                siguiente->siguiente = actual;

                anterior = siguiente;
                siguiente = actual->siguiente;
                intercambio = true;

            } else {
                anterior = actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
        }
        
        cabeza = lista.cabeza;
        actual = cabeza;
        siguiente = cabeza->siguiente;
        anterior = nullptr;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Tiempo de ejecución con Bubble Sort: " << elapsed_seconds.count() << " segundos" << std::endl;
    this->tiempo = elapsed_seconds.count();
}

double BubbleSort::getTiempo() {
    return this->tiempo;
}
