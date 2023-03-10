//
// Created by radziu2402 on 06.03.2023.
//

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    DoublyLinkedList::head = nullptr;
    DoublyLinkedList::tail = nullptr;
    DoublyLinkedList::size = 0;
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
    if (index < 0 || index > size) {
        cout << "There is no element with index: [" << index << "]" << endl;
        return;
    }

    if (index == 0) {
        insertHead(value);
        return;
    }

    else if (index == size - 1) {
        insertTail(value);
        return;
    }

    else{
        Node *prev_node = head;
        for (int i = 0; i < index-1; i++) {
            prev_node = prev_node->next;
        }
        Node *next_node = prev_node->next;
        Node *node = new Node(value, prev_node, next_node);
        prev_node->next = node;
        next_node->prev = node;
    }

    size++;
}

void DoublyLinkedList::removeHead() {
    if(head != nullptr){
        head->next->prev = nullptr;
        head = head->next;
        size--;
    }
    else{
        cout << "List is empty" << endl;
    }
}

void DoublyLinkedList::removeTail() {
    if(tail != nullptr){
        tail->prev->next = nullptr;
        tail = tail->prev;
        size--;
    }
    else{
        cout << "List is empty" << endl;
    }
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index > size) {
        cout << "There is no element with index: [" << index << "]" << endl;
        return;
    }

    if (index == 0) {
        removeHead();
        return;
    }

    if (index == size - 1) {
        removeTail();
        return;
    }
}

void DoublyLinkedList::displayList() {
    if(head != nullptr){
        Node *tempNode = head;
        while (tempNode != nullptr){
            cout << tempNode->value << " ";
            tempNode = tempNode->next;
        }
    }
    else{
        cout << "List is empty" << endl;
    }
}

void DoublyLinkedList::displayListBackward() {
    if(head != nullptr){
        Node *tempNode = tail;
        while (tempNode != nullptr){
            cout << tempNode->value << " ";
            tempNode = tempNode->prev;
        }
    }
    else{
        cout << "List is empty" << endl;
    }
}

bool DoublyLinkedList::checkIfExist(int value) {
    if(head != nullptr){
        Node *tempNode = head;
        while (tempNode->value != value){
            tempNode = tempNode->next;
            if(!tempNode){
                return false;
            }
        }
        cout << "This value exists in list" << endl;
        return true;
    }
    else{
        cout << "List is empty" << endl;
        return false;
    }
}
