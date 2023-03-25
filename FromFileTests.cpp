//
// Created by radziu2402 on 20.03.2023.
//

#include "FromFileTests.h"
#include "Time.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "BinaryHeap.h"
#include "RedBlackTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void FromFileTests::DoublyLinkedListTest() {
    srand(time(nullptr));
    Time time;
    DoublyLinkedList list;
    int choise = -1;
    int value;
    int randNum;
    int randIndex;
    string inputFileName;
    ifstream inputFile;

    cout << "Enter name of input file with data:  ";
    cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        cout << "Input file opened." << inputFileName << endl;
    } else {
        cout << "Failed to open input file." << endl;
        return;
    }

    while (choise != 0) {
        cout << "Choose what do you want to do:" << endl;
        cout << "   1. Insert head" << endl;
        cout << "   2. Insert tail" << endl;
        cout << "   3. Insert anywhere" << endl;
        cout << "   4. Remove head" << endl;
        cout << "   5. Remove tail" << endl;
        cout << "   6. Remove any" << endl;
        cout << "   7. Check if exists" << endl;
        cout << "   8. Display list" << endl;
        cout << "   9. Display list backwards" << endl;
        cout << "   0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;

        switch (choise) {
            default:
                cout << "Wrong choise!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                randNum = rand() % 1000000 - 1;
                time.timeStart();
                list.insertHead(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 2:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                randNum = rand() % 1000000 - 1;
                time.timeStart();
                list.insertTail(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 3:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                randNum = rand() % 1000000 - 1;
                randIndex = rand() % list.size;
                time.timeStart();
                list.insert(randNum, randIndex);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 4:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                time.timeStart();
                list.removeHead();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 5:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                time.timeStart();
                list.removeTail();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 6:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                randIndex = rand() % list.size;
                time.timeStart();
                list.remove(randIndex);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 7:
                while (inputFile.good()) {
                    inputFile >> value;
                    list.insertHead(value);
                }
                randNum = rand() % 1000 - 1;
                time.timeStart();
                list.checkIfExist(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 8:
                time.timeStart();
                list.displayList();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 9:
                time.timeStart();
                list.displayListBackward();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }
    }
}

void FromFileTests::ArrayTest() {
    srand(time(nullptr));
    Time time;
    DynamicArray array;
    int choise = -1;
    int value;
    int randNum;
    int randIndex;
    string inputFileName;
    ifstream inputFile;

    cout << "Enter name of input file with data:  ";
    cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        cout << "Input file opened." << inputFileName << endl;
    } else {
        cout << "Failed to open input file." << endl;
        return;
    }
    while (choise != 0) {
        cout << "Choose what do you want to do:" << endl;
        cout << "   1. Insert head" << endl;
        cout << "   2. Insert tail" << endl;
        cout << "   3. Insert anywhere" << endl;
        cout << "   4. Remove head" << endl;
        cout << "   5. Remove tail" << endl;
        cout << "   6. Remove any" << endl;
        cout << "   7. Check if exists" << endl;
        cout << "   8. Display array" << endl;
        cout << "   0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;

        switch (choise) {
            default:
                cout << "Wrong choise!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                array.insertHead(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 2:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                array.insertTail(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;

                inputFile.close();
                break;

            case 3:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                randNum = rand() % 500000 - 1;
                randIndex = rand() % array.size;
                time.timeStart();
                array.insert(randNum, randIndex);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 4:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                time.timeStart();
                array.removeHead();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 5:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                time.timeStart();
                array.removeTail();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 6:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                randIndex = rand() % array.size;
                time.timeStart();
                array.remove(randIndex);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                inputFile.close();
                break;

            case 7:
                while (inputFile.good()) {
                    inputFile >> value;
                    array.insertHead(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                array.checkIfExist(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;

                inputFile.close();
                break;

            case 8:
                time.timeStart();
                array.displayArray();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }
    }
}

void FromFileTests::BinaryHeapTest() {
    srand(time(nullptr));
    Time time;
    BinaryHeap binaryHeap;
    int choise = -1;
    int value;
    int randNum;
    int randIndex;
    string inputFileName;
    ifstream inputFile;

    cout << "Enter name of input file with data:  ";
    cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        cout << "Input file opened." << inputFileName << endl;
    } else {
        cout << "Failed to open input file." << endl;
        return;
    }
    while (choise != 0) {
        cout << "Choose what do you want to do:" << endl;
        cout << "    1. Insert value" << endl;
        cout << "    2. Delete Root" << endl;
        cout << "    3. Check if value exists" << endl;
        cout << "    4. Print Heap" << endl;
        cout << "    0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;
        switch (choise) {
            default:
                cout << "Wrong choise!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    inputFile >> value;
                    binaryHeap.insert(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                binaryHeap.insert(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                while (inputFile.good()) {
                    inputFile >> value;
                    binaryHeap.insert(value);
                }
                time.timeStart();
                binaryHeap.deleteRoot();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                while (inputFile.good()) {
                    inputFile >> value;
                    binaryHeap.insert(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                binaryHeap.checkIfExist(randNum);
                time.timeStop();
                if (binaryHeap.checkIfExist(randNum)) {
                    cout << "This element exists in Heap " << endl;
                } else {
                    cout << "This element doesn't exists in Heap " << endl;
                }
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                while (inputFile.good()) {
                    inputFile >> value;
                    binaryHeap.insert(value);
                }
                time.timeStart();
                binaryHeap.displayHeap();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }

    }
}

void FromFileTests::RedBlackTreeTest() {
    srand(time(nullptr));
    Time time;
    RedBlackTree rBTree;
    int choise = -1;
    int value;
    int randNum;
    int randIndex;
    string inputFileName;
    ifstream inputFile;

    cout << "Enter name of input file with data:  ";
    cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        cout << "Input file opened." << inputFileName << endl;
    } else {
        cout << "Failed to open input file." << endl;
        return;
    }
    while (choise != 0) {
        cout << "Choose what do you want to do:" << endl;
        cout << "    1. Insert value" << endl;
        cout << "    2. Delete value" << endl;
        cout << "    3. Check if value exists" << endl;
        cout << "    4. Print RBTree" << endl;
        cout << "    5. Print RBTree inorder" << endl;
        cout << "    6. Print RBTree preorder" << endl;
        cout << "    7. Print RBTree postorder" << endl;
        cout << "    0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;
        switch (choise) {
            default:
                cout << "Wrong choise!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                rBTree.insert(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                rBTree.deleteNode(randNum);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                randNum = rand() % 500000 - 1;
                time.timeStart();
                rBTree.searchTree(randNum);
                time.timeStop();
                if (rBTree.searchTree(randNum) != nullptr) {
                    cout << "This element exists in Tree " << endl;
                } else {
                    cout << "This element doesn't exists in Tree " << endl;
                }
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                time.timeStart();
                rBTree.printTree();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 5:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                time.timeStart();
                rBTree.inorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 6:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                time.timeStart();
                rBTree.preorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 7:
                while (inputFile.good()) {
                    inputFile >> value;
                    rBTree.insert(value);
                }
                time.timeStart();
                rBTree.postorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }
    }
}
