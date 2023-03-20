#include <iostream>
#include "Tests.h"
#include "FromFileTests.h"


using namespace std;

int main() {
    Tests tests;
    FromFileTests fromFileTests;
    int choise = -1;
    string fromFile;

    while (choise != 0) {
        cout << "Select data structure:" << endl;
        cout << "   1. Doubly Linked List" << endl;
        cout << "   2. Dynamic Array" << endl;
        cout << "   3. Binary Heap" << endl;
        cout << "   4. Red-Black Tree" << endl;
        cout << "   0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;
        cout << "Do you want to use data from File? Type yes/no: ";
        cin >> fromFile;
        switch (choise) {
            case 0:
                return 0;
            case 1:
                if (fromFile == "yes") {
                    fromFileTests.DoublyLinkedListTest();
                } else
                    tests.DoublyLinkedListTest();
                break;
            case 2:
                if (fromFile == "yes") {
                    fromFileTests.ArrayTest();
                } else
                    tests.ArrayTest();
                break;
            case 3:
                if (fromFile == "yes") {
                    fromFileTests.BinaryHeapTest();
                } else
                    tests.BinaryHeapTest();
                break;
            case 4:
                if (fromFile == "yes") {
                    fromFileTests.RedBlackTreeTest();
                } else
                    tests.RedBlackTreeTest();
                break;
            default:
                cout << "Wrong choise!" << endl;
                break;
        }
    }
    return 0;
}
