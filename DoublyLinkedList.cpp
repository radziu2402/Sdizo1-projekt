//
// Created by radziu2402 on 06.03.2023.
//

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != tail) {
        head = head->next;
        delete head->prev;
    }
    delete tail;
}

void DoublyLinkedList::insertHead(int value) {

}

void DoublyLinkedList::insertTail(int value) {

}

void DoublyLinkedList::insert(int value, int index) {

}

void DoublyLinkedList::removeHead() {

}

void DoublyLinkedList::removeTail() {

}

void DoublyLinkedList::remove(int index) {

}

void DoublyLinkedList::displayList() {

}

bool DoublyLinkedList::checkIfExist(int value) {
    return false;
}
