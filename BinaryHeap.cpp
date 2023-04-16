//
// Created by radziu2402 on 17.03.2023.
//

#include "BinaryHeap.h"
#include <iostream>


void BinaryHeap::heapify(int index) {
    if (index == 0) {
        return;
    }
    int parentIndex = (index - 1) / 2;
    if (data[parentIndex] < data[index]) {
        swap(parentIndex, index);
        heapify(parentIndex);
    }
}

void BinaryHeap::swap(int index1, int index2) {
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

void BinaryHeap::insert(int elem) {
    if (len == 0) {
        data = new int[1];
        data[0] = elem;
        len++;
    } else {
        int *newData = new int[len + 1];
        for (int i = 0; i < len; i++) {
            newData[i] = data[i];
        }
        newData[len] = elem;
        delete[] data;
        data = newData;
        len++;
        heapify(len - 1);
    }
}

void BinaryHeap::deleteRoot() {
    if (len == 0) return;
    int index = checkIfExist(data[0]);
    if (index == -1) return;
    if (index != len - 1)
        swap(index, len - 1);

    int *newData = new int[len - 1];
    for (int i = 0; i < len - 1; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    len--;
    heapify(index);
    downHeapify(index);
}

int BinaryHeap::checkIfExist(int val) {
    if (len == 0) {
        return -1;
    }
    for (int i = 0; i < len; i++) {
        if (data[i] == val) {
            return i;
        }
    }
    return -1;
}

BinaryHeap::BinaryHeap() {
    data = nullptr;
    len = 0;
}

BinaryHeap::~BinaryHeap() {
    delete[] data;
}

int BinaryHeap::left(int index) {
    return index * 2 + 1;
}

int BinaryHeap::right(int index) {
    return index * 2 + 2;
}

void BinaryHeap::downHeapify(int index) {
    int leftIndex = left(index);
    int rightIndex = right(index);
    int largest = index;
    if (leftIndex < len && data[leftIndex] > data[largest]) {
        largest = leftIndex;
    }
    if (rightIndex < len && data[rightIndex] > data[largest]) {
        largest = rightIndex;
    }
    if (largest != index) {
        swap(index, largest);
        downHeapify(largest);
    }
}

void BinaryHeap::displayHeap() {
// Sprawdza, czy kopiec nie jest pusty
    if (data != nullptr) {
// Wywołuje funkcję printHeap, aby wyświetlić kopiec
        printHeap(data, len, 0, 2);
    } else {
        std::cout << "Heap is empty" << std::endl; // Wyświetla komunikat, że kopiec jest pusty
    }
}

void BinaryHeap::printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent) {
// Sprawdza, czy indeks węzła nie wykracza poza rozmiar kopca
    if (currentNodeIndex >= heapSize)
        return;
    int indentIncrease = 4;
// Wywołuje rekurencyjnie funkcję printHeap dla prawego dziecka
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 2, levelIndent + indentIncrease);

// Wyświetla wartość węzła
    for (int j = 0; j < levelIndent; j++)
        std::cout << " ";
    std::cout << heapArray[currentNodeIndex] << std::endl;

// Wywołuje rekurencyjnie funkcję printHeap dla lewego dziecka
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 1, levelIndent + indentIncrease);
}

