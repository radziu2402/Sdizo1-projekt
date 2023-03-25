//
// Created by radziu2402 on 17.03.2023.
//

#include "BinaryHeap.h"
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap() {
    BinaryHeap::array = nullptr;
    BinaryHeap::size = 0;
}

BinaryHeap::~BinaryHeap() {
    if (BinaryHeap::size > 0) {
        delete[]array;
    }
}

void BinaryHeap::insert(int value) {
    if (size == 0) {
        array = new int[1];
        array[0] = value;
        size++;
        return;
    }
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = value;
    delete[]array;
    array = newArray;
    size++;
    heapify();
}

void BinaryHeap::deleteRoot() {
    if (size != 0) {
        int *newArray = new int[size - 1];
        for (int k = 1; k < size; k++) {
            newArray[k - 1] = array[k];
        }
        delete[]array;
        array = newArray;
        heapify();
        size--;
    }
}

bool BinaryHeap::checkIfExist(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void BinaryHeap::displayHeap() {
    if (array != nullptr) {
        printHeap(array, size, 0, 2);
    } else {
        cout << "Heap is empty" << endl;
    }
}


void BinaryHeap::heapify() {
    int parent, leftChild, rightChild, maxChild;
    for (int i = size - 1; i >= 0; i--) {
        parent = i;
        while (true) {
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
            if (leftChild >= size) {
                break;
            }
            maxChild = leftChild;
            if (rightChild < size && array[rightChild] > array[leftChild]) {
                maxChild = rightChild;
            }
            if (array[parent] >= array[maxChild]) {
                break;
            }
            swap(array[parent], array[maxChild]);
            parent = maxChild;
        }
    }
}

void BinaryHeap::printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent) {
    if (currentNodeIndex >= heapSize)
        return;

    int indentIncrease = 4;
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 2, levelIndent + indentIncrease);

    for (int j = 0; j < levelIndent; j++)
        cout << " ";
    cout << heapArray[currentNodeIndex] << endl;

    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 1, levelIndent + indentIncrease);
}


