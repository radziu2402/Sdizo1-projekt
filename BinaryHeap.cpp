//
// Created by radziu2402 on 17.03.2023.
//

#include "BinaryHeap.h"
#include <iostream>

using namespace std;

BinaryHeap::BinaryHeap() {
    array = nullptr; // ustawienie początkowej wartości tablicy na nullptr
    size = 0; // ustawienie początkowego rozmiaru na 0
}

BinaryHeap::~BinaryHeap() {
    if (BinaryHeap::size > 0) { // sprawdzenie, czy rozmiar tablicy jest większy od 0
        delete[]array; // zwolnienie pamięci zaalokowanej dla tablicy
    }
}

void BinaryHeap::insert(int value) {
    if (size == 0) { // sprawdzenie, czy rozmiar tablicy jest równy 0
        array = new int[1]; // zaalokowanie pamięci dla tablicy o rozmiarze 1
        array[0] = value; // przypisanie wartości do pierwszego elementu tablicy
        size++; // zwiększenie rozmiaru tablicy
        return;
    }
    int *newArray = new int[size + 1]; // utworzenie nowej tablicy o rozmiarze o 1 większym od aktualnego
    for (int i = 0; i < size; i++) { // skopiowanie zawartości aktualnej tablicy do nowej
        newArray[i] = array[i];
    }
    newArray[size] = value; // dodanie nowej wartości do końca tablicy
    delete[]array; // zwolnienie pamięci zaalokowanej dla aktualnej tablicy
    array = newArray; // przypisanie nowej tablicy do pola klasy array
    size++; // zwiększenie rozmiaru tablicy
    heapify(); // ustawienie elementów tablicy w odpowiedniej kolejności, aby zachować właściwości kopca binarnego
}

void BinaryHeap::deleteRoot() {
    if (size != 0) { // sprawdzenie, czy rozmiar tablicy jest różny od 0
        int *newArray = new int[size - 1]; // utworzenie nowej tablicy o rozmiarze o 1 mniejszym od aktualnego
        for (int k = 1; k < size; k++) { // skopiowanie zawartości aktualnej tablicy do nowej, pomijając pierwszy element
            newArray[k - 1] = array[k];
        }
        delete[]array; // zwolnienie pamięci zaalokowanej dla aktualnej tablicy
        array = newArray; // przypisanie nowej tablicy do pola klasy array
        heapify(); // ustawienie elementów tablicy w odpowiedniej kolejności, aby zachować właściwości kopca binarnego
        size--; // zmniejszenie rozmiaru tablicy
    }
}

void BinaryHeap::heapify() {
    int parent, leftChild, rightChild, maxChild;
// Iteruje od końca kopca do jego początku
    for (int i = size - 1; i >= 0; i--) {
        parent = i;
// Wykonuje operacje naprawiania kopca dla każdego węzła
        while (true) {
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
// Sprawdza, czy węzeł ma lewe dziecko
            if (leftChild >= size) {
                break;
            }
            maxChild = leftChild;
// Sprawdza, czy węzeł ma prawe dziecko i czy wartość prawego dziecka jest większa niż wartość lewego dziecka
            if (rightChild < size && array[rightChild] > array[leftChild]) {
                maxChild = rightChild;
            }
// Sprawdza, czy wartość rodzica jest większa niż wartość największego dziecka
            if (array[parent] >= array[maxChild]) {
                break;
            }
// Zamienia wartości rodzica i największego dziecka i aktualizuje wartość rodzica
            swap(array[parent], array[maxChild]);
            parent = maxChild;
        }
    }
}

bool BinaryHeap::checkIfExist(int value) {
// Przeszukuje elementy kopca w celu znalezienia wartości
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true; // Zwraca true, jeśli wartość została znaleziona
        }
    }
    return false; // Zwraca false, jeśli wartość nie została znaleziona
}

void BinaryHeap::displayHeap() {
// Sprawdza, czy kopiec nie jest pusty
    if (array != nullptr) {
// Wywołuje funkcję printHeap, aby wyświetlić kopiec
        printHeap(array, size, 0, 2);
    } else {
        cout << "Heap is empty" << endl; // Wyświetla komunikat, że kopiec jest pusty
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
        cout << " ";
    cout << heapArray[currentNodeIndex] << endl;

// Wywołuje rekurencyjnie funkcję printHeap dla lewego dziecka
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 1, levelIndent + indentIncrease);
}


