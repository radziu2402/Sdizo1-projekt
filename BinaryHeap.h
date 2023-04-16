//
// Created by radziu2402 on 17.03.2023.
//

#ifndef SDIZO1_BINARYHEAP_H
#define SDIZO1_BINARYHEAP_H

class BinaryHeap {

private:
    int *data;


    void heapify(int index);

    void downHeapify(int index);

    void swap(int index1, int index2);

    int left(int index);

    int right(int index);

public:
    int len;
    void insert(int elem);

    void deleteRoot();

    int checkIfExist(int val);

    BinaryHeap();

    ~BinaryHeap();

    void displayHeap();

    void printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent);
};

#endif //SDIZO1_BINARYHEAP_H
