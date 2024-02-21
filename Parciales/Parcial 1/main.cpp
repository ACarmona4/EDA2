#include <iostream>
#include <iomanip>
#include <chrono>
#include "Persona.h"
#include "Lista.h"
#include "MergeSort.h"
#include "Generador.h" 
#include "QuickSort.h"
#include "BubbleSort.h"


void determinarMenorTiempo(double tiempoMerge, double tiempoQuick, double tiempoBubble) {
    if (tiempoMerge < tiempoQuick && tiempoMerge < tiempoBubble) {
        std::cout << "El algoritmo con menor tiempo de ejecución es Merge Sort con " << tiempoMerge << " segundos." << std::endl;
    } else if (tiempoQuick < tiempoMerge && tiempoQuick < tiempoBubble) {
        std::cout << "El algoritmo con menor tiempo de ejecución es Quick Sort " << tiempoQuick << " segundos." << std::endl;
    } else {
        std::cout << "El algoritmo con menor tiempo de ejecución es Bubble Sort " << tiempoBubble << " segundos." << std::endl;
    }
}

int main(int argc, char* argv[]) {
    // Verificar que se haya proporcionado el número de elementos como argumento
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero_de_elementos>" << std::endl;
        return 1; // Salir con código de error
    }

    // Obtener el número de elementos desde el argumento
    int numElementos = std::atoi(argv[1]);

    // Crear un generador con archivos de nombres y apellidos
    Generador generadorNombres("nombres.txt", "apellidos.txt");

    // Crear una lista e insertar personas generadas aleatoriamente
    Lista lista1;
    Lista lista2;
    Lista lista3;

    for (int i = 0; i < numElementos; ++i) {
        Persona personaGenerada = generadorNombres.generarPersona();
        lista1.agregarElemento(personaGenerada);
        lista2.agregarElemento(personaGenerada);
        lista3.agregarElemento(personaGenerada);
    }

    // Mostrar la lista desordenada
    std::cout << "Lista de personas generadas aleatoriamente (desordenada):" << std::endl;
    lista1.listar();
    std::cout << "------------------------------------" << std::endl;

    //-----[MERGE SORT]-----
    MergeSort mergeSort;
    mergeSort.ordenar(lista1);


    // Mostrar la lista ordenada
    std::cout << "LISTA ORDENADA POR MERGE SORT:" << std::endl;
    std::cout << std::endl;
    lista1.listar();
    std::cout << "------------------------------------" << std::endl;


    //-----[QUICK SORT]-----
    QuickSort quickSort;
    quickSort.ordenar(lista2); 

    // Mostrar la lista ordenada
    std::cout << "LISTA ORDENADA POR QUICK SORT:" << std::endl;
    std::cout << std::endl;
    lista2.listar();
    std::cout << "------------------------------------" << std::endl;
    
    //-----[BUBBLE SORT]-----
    BubbleSort listaBurbuja;
    listaBurbuja.bubbleSort(lista3);

    // Mostrar la lista ordenada por Burbuja
    std::cout << "LISTA ORDENADA POR BUBBLE SORT:" << std::endl;
    std::cout << std::endl;
    lista3.listar();
    std::cout << "------------------------------------" << std::endl;

    //-----[MOSTRAR TIEMPOS]-----
    std::cout << "TIEMPOS DE EJECUCION:" << std::endl;
    std::cout << std::endl;
    std::cout << "Tiempo de ejecución con Merge Sort: " << mergeSort.getTiempo() << " segundos" << std::endl;
    std::cout << "Tiempo de ejecución con Quick Sort: " << quickSort.getTiempo() << " segundos" << std::endl;
    std::cout << "Tiempo de ejecución con Bubble Sort: " << listaBurbuja.getTiempo() << " segundos" << std::endl;
    std::cout << std::endl;
    double tiempoMerge = mergeSort.getTiempo();
    double tiempoQuick = quickSort.getTiempo();
    double tiempoBubble = listaBurbuja.getTiempo();
    determinarMenorTiempo(tiempoMerge, tiempoQuick, tiempoBubble);
    std::cout << "------------------------------------" << std::endl;
    return 0;
}

