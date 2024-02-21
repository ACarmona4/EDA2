// Lista.h
#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
private:

public:
    Lista();
    ~Lista();
    
    void agregarElemento(const Persona& persona);
    void listar() const;
    void borrar(const Persona& persona);
    int longitud() const;

    // Elimina el modificador const en la declaración de dividirLista
    void dividirLista(Nodo* cabeza, Nodo** lista1, Nodo** lista2);

    void mergesort();
    Nodo* mergeListas(Nodo* lista1, Nodo* lista2) const;

    Nodo* cabeza;
    Nodo* const getCabeza() const;

};

#endif
