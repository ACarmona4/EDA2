// Lista.cpp
#include "Lista.h"

void Lista::dividirLista(Nodo* cabeza, Nodo** lista1, Nodo** lista2) {
    Nodo* puntoA;
    Nodo* puntoB;

    int size= 0;
    for(Nodo* x = cabeza; x != nullptr; x=x->siguiente){
        ++size;
    }
    int mitad = size/2;

    std::cout << "en dividirLista.. (Tamaño: "<< std::to_string(size) <<") : (Mitad: "<< std::to_string(mitad) <<")" << std::endl;

    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        *lista1 = cabeza;
        *lista2 = nullptr;
    } else {
        puntoB = cabeza;
        puntoA = cabeza->siguiente;

        // Avanzar 'puntoA' dos nodos y 'puntoB' un nodo
        while (puntoA != nullptr) {
            puntoA = puntoA->siguiente;
            if (puntoA != nullptr) {
                puntoB = puntoB->siguiente;
                puntoA = puntoA->siguiente;
            }
        }
        // 'puntoB' ahora está en el nodo medio, dividir la lista en dos en este punto
        *lista1 = cabeza;
        *lista2 = puntoB->siguiente;
        puntoB->siguiente = nullptr;
    }
    std::cout << "Terminó DividirLista" << std::endl;
    //std::cout << "Lista 1" << std::endln;
    
}

Lista::Lista() : cabeza(nullptr) {}

Lista::~Lista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Lista::agregarElemento(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::listar() const {
    Nodo* actual = cabeza;
    int i = 1;
    while (actual != nullptr) {
        std::cout << "[" << i << "]: " << actual->Data << std::endl; 
        actual = actual->siguiente;
        ++i;
    }
    std::cout << std::endl;
}

void Lista::borrar(const Persona& persona) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && !(actual->Data == persona)) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        std::cout << "La persona no está en la lista." << std::endl;
        return;
    }

    if (anterior == nullptr) {
        // El nodo a borrar es el primero
        cabeza = actual->siguiente;
    } else {
        // El nodo a borrar no es el primero
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
}

int Lista::longitud() const {
    int count = 0;
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        count++;
        actual = actual->siguiente;
    }

    return count;
}

void Lista::mergesort() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return; // La lista está vacía o tiene un solo elemento, ya está ordenada
    }

    Nodo* lista1;
    Nodo* lista2;

    dividirLista(cabeza, &lista1, &lista2); // Dividir la lista en dos

    // Recursivamente ordenar las dos sublistas
    Lista mitad1;
    Lista mitad2;

    mitad1.cabeza = lista1;
    mitad2.cabeza = lista2;

    mitad1.mergesort();
    mitad2.mergesort();

    // Combinar las sublistas ordenadas
    cabeza = mergeListas(mitad1.getCabeza(), mitad2.getCabeza());
    std::cout << "mitad 1" << std::endl;
    mitad1.listar();
    std::cout << "mitad 2" << std::endl;
    mitad2.listar();
}

Nodo* Lista::mergeListas(Nodo* lista1, Nodo* lista2) const {

    std::cout << "....en mergeListas" << std::endl;
    std::cout << "    lista1: "<< lista1->Data << std::endl;

    std::cout << "    lista2: "<< lista2->Data <<"\n--------------------" << std::endl;

    
    Nodo* resultado = nullptr;

    if (lista1 == nullptr) {
        return lista2;
    } else if (lista2 == nullptr) {
        return lista1;
    }

    // Comparar los nodos y fusionar recursivamente
    if (lista1->Data < lista2->Data) {
        resultado = lista1;
        resultado->siguiente = mergeListas(lista1->siguiente, lista2);
    } else {
        resultado = lista2;
        resultado->siguiente = mergeListas(lista1, lista2->siguiente);
    }

    return resultado;
}

Nodo* const Lista::getCabeza() const {
    return cabeza;
}