#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Lista.h" 

class QuickSort {
public:
    void ordenar(Lista& lista);
    double getTiempo();
    
private:
    void quickSortRecursivo(Nodo** cabezaRef, Nodo* fin);
    Nodo* particionar(Nodo* inicio, Nodo* fin, Nodo** nuevoInicio, Nodo** nuevoFin);
    Nodo* obtenerUltimoNodo(Nodo* cabeza);

    double tiempo;
};

#endif 