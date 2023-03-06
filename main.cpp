#include <iostream>

using namespace std;

int main() {

    int choise = -1;


    while (choise != 0) {
        cout << "Wybierz strukture danych:" << endl;
        cout << "   1. Tablica dynamiczna" << endl;
        cout << "   2. Lista" << endl;
        cout << "   3. Kopiec binarny" << endl;
        cout << "   4. Drzewo czerwono-czarne" << endl;
        cout << "   0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> choise;

        if (choise == 0) return 0;
    }


    






    return 0;
}
