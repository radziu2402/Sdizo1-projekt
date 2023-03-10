//
// Created by radziu2402 on 10.03.2023.
//
#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray() {

    DynamicArray::head = nullptr;
    DynamicArray::size = 0;

}

DynamicArray::~DynamicArray() {

    if (head != nullptr) {
        delete []head;
    }
}

void DynamicArray::insertHead(int value) {
    int *newHead = new int[size + 1];
    newHead[0] = value;

    for (int i = 0; i < size; i++) {
        newHead[i + 1] = head[i];
    }

    delete head;
    head = newHead;

    size++;
}

void DynamicArray::insertTail(int value) {
    int *newHead = new int[size + 1];
    newHead[size] = value;

    for (int i = 0; i < size; i++) {
        newHead[i] = head[i];
    }

    delete [] head;
    head = newHead;

    size++;
}

void DynamicArray::insert(int value, int index) {
    if (index < 0 || index > size) {
        cout << "There is no element with index: [" << index << "]!" << endl;
    } else {
        int *newHead = new int[size + 1];
        newHead[index] = value;

        for (int i = 0; i < index; i++) {
            newHead[i] = head[i];
        }

        for (int i = index; i < size; i++) {
            newHead[i + 1] = head[i];
        }

        delete [] head;
        head = newHead;

        size++;
    }
}

void DynamicArray::removeHead() {
    if (size > 0) {
        int *newHead = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i + 1];
        }

        delete[] head;
        head = newHead;

        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

void DynamicArray::removeTail() {
    if (size > 0) {
        int *newHead = new int[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i];
        }

        delete[] head;
        head = newHead;

        size--;
    } else {
        cout << "Array is empty" << endl;
    }
}

void DynamicArray::remove(int index) {
    if (size > 0 || index > 0 || index < size) {

        int *newHead = new int[size - 1];

        for (int i = 0; i < index; i++) {
            newHead[i] = head[i];
        }

        for (int i = index; i < size - 1; i++) {
            newHead[i] = head[i + 1];
        }

        delete[] head;
        head = newHead;

        size--;
    } else {
        cout << "There is no element with index: [" << index << "]!" << endl;
    }

}

void DynamicArray::displayArray() {
    if (size > 0) {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << head[i] << ", ";
        }
        cout << "]";
    } else {
        cout << "Array is empty" << endl;
    }
}

bool DynamicArray::checkIfExist(int value) {
    for (int i = 0; i < size; i++) {
        if (head[i] == value) {
            cout << "This value exists in array with index: [" << i << "]" << endl;
            return true;
        }
    }
    cout << "This element doesnt exist in array" << endl;
    return false;
}
