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
    Node *node = new Node(value, nullptr, nullptr);
    node->next = head;
    if(head != nullptr){
        head->prev = node;
    }
    else{
        tail = node;
    }
    head = node;
    size++;
}

void DoublyLinkedList::insertTail(int value) {
    Node *node = new Node(value, nullptr, nullptr);
    node->prev = tail;
    if(tail != nullptr){
        tail->next = node;
    }
    else{
        head = node;
    }
    tail = node;
    size++;
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
