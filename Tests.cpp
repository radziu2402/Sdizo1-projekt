//
// Created by radziu2402 on 10.03.2023.
//
#include <iostream>
#include "Tests.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "Time.h"
#include "BinaryHeap.h"
#include "RedBlackTree.h"

using namespace std;


void Tests::ArrayTest() {
    Time time;
    DynamicArray array;
    int choise = -1;
    int value;
    int index;

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
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                array.insertHead(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                array.insertTail(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter index: ";
                cin >> index;
                time.timeStart();
                array.insert(value, index);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                array.removeHead();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 5:
                time.timeStart();
                array.removeTail();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 6:
                cout << "Enter index: ";
                cin >> index;
                time.timeStart();
                array.remove(index);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 7:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                array.checkIfExist(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
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

void Tests::DoublyLinkedListTest() {
    Time time;
    DoublyLinkedList list;
    int choise = -1;
    int value;
    int index;

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
        cout << "   9. Display array backwards" << endl;
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
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                list.insertHead(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                list.insertTail(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter index: ";
                cin >> index;
                time.timeStart();
                list.insert(value, index);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                list.removeHead();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 5:
                time.timeStart();
                list.removeTail();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 6:
                cout << "Enter index: ";
                cin >> index;
                time.timeStart();
                list.remove(index);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 7:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                list.checkIfExist(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
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

void Tests::BinaryHeapTest() {
    Time time;
    BinaryHeap binaryHeap;
    int choise = -1;
    int value;
    bool ifExist;
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
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                binaryHeap.insert(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                time.timeStart();
                binaryHeap.deleteRoot();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                ifExist = binaryHeap.checkIfExist(value);
                if (ifExist){
                    cout << "This element exists in Heap " << endl;
                }
                else
                    cout << "This element doesn't exists in Heap " << endl;
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                binaryHeap.displayHeap();
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }

    }
}

void Tests::RedBlackTreeTest() {
    Time time;
    RedBlackTree rBTree;
    int choise = -1;
    int value;
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
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                rBTree.insert(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                rBTree.deleteNode(value);
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                time.timeStart();
                if(rBTree.searchTree(value) != nullptr){
                    cout << "This element exists in Tree " << endl;
                }
                else
                    cout << "This element doesn't exists in Tree " << endl;
                time.timeStop();
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;

            case 4:
                time.timeStart();
                rBTree.printTree();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 5:
                time.timeStart();
                rBTree.inorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 6:
                time.timeStart();
                rBTree.preorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
            case 7:
                time.timeStart();
                rBTree.postorder();
                time.timeStop();
                cout << endl;
                cout << "Execution time: " << time.elapsedTime() << "ns" << endl;
                break;
        }
    }
}
