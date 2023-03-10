//
// Created by radziu2402 on 06.03.2023.
//

#ifndef SDIZO1_DOUBLYLINKEDLIST_H
#define SDIZO1_DOUBLYLINKEDLIST_H


#include "Node.h"

class DoublyLinkedList {

public:
    int size;

    Node *head;
    Node *tail;

    DoublyLinkedList();

    ~DoublyLinkedList();

    void insertHead(int value);

    void insertTail(int value);

    void insert(int value, int index);

    void removeHead();

    void removeTail();

    void remove(int index);

    void displayList();
    void displayListBackward();

    bool checkIfExist(int value);
};


#endif //SDIZO1_DOUBLYLINKEDLIST_H
