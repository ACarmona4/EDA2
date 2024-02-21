#ifndef MERGESORT_H
#define MERGESORT_H

#include "Lista.h"

class MergeSort {
public:
    void ordenar(Lista& lista); 
    double getTiempo();

private:
    Nodo* mergeSort(Nodo* cabeza); 
    Nodo* encontrarMitad(Nodo* cabeza);
    Nodo* unirListas(Nodo* lista1, Nodo* lista2); 
    double tiempo;
};

#endif
