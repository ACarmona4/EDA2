
#ifndef LISTABURBUJA_H
#define LISTABURBUJA_H

#include "Lista.h"

class BubbleSort{
public:
    void bubbleSort(Lista& lista);
    double getTiempo();

private:
    double tiempo;
};

#endif