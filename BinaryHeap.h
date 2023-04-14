//
// Created by radziu2402 on 17.03.2023.
//

#ifndef SDIZO1_BINARYHEAP_H
#define SDIZO1_BINARYHEAP_H

class BinaryHeap {
public:
    int *array;
    int size;

    BinaryHeap();

    ~BinaryHeap();

    void insert(int value);

    void deleteRoot();

    bool checkIfExist(int value);

    void displayHeap();

private:
    void heapify();

    void printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent);
};

#endif //SDIZO1_BINARYHEAP_H
