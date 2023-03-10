#include <iostream>
#include "Tests.h"


using namespace std;

int main() {
    Tests tests;
    int choise = -1;

    while (choise != 0) {
        cout << "Select data structure:" << endl;
        cout << "   1. Doubly Linked List" << endl;
        cout << "   2. Dynamic Array" << endl;
        cout << "   3. Binary Heap" << endl;
        cout << "   4. Red-Black Tree" << endl;
        cout << "   0. Exit" << endl << endl;
        cout << "Choise: ";
        cin >> choise;

        switch (choise) {
            case 0:
                return 0;
            case 1:
                tests.DoublyLinkedListTest();
                break;
            case 2:
                tests.ArrayTest();
                break;
        }

    }
    return 0;
}
