//
// Created by radziu2402 on 06.03.2023.
//

#ifndef SDIZO1_LIST_H
#define SDIZO1_LIST_H


#include "ListElements.h"

class List {

public:

    int size;

    List();

    ~List();

    ListElements *firstyElement;
    ListElements *lastElement;
    ListElements *actualElement;

    void addOnBeggining(int wartosc);

    void addSomewhere(int wartosc, int pozycja);

    void addOnEnd(int wartosc);

    void displayList();

    void deleteFirst();

    void deletelast();

    void deleteSelected(int);

    bool checkIfExist(int wartosc);
};


#endif //SDIZO1_LIST_H
