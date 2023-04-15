//
// Created by radziu2402 on 06.03.2023.
//

#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Implementacja konstruktora klasy DoublyLinkedList
DoublyLinkedList::DoublyLinkedList() {
    DoublyLinkedList::head = nullptr; // Ustawia głowę listy na nullptr
    DoublyLinkedList::tail = nullptr; // Ustawia ogon listy na nullptr
    DoublyLinkedList::size = 0; // Ustawia początkowy rozmiar listy na 0
}

// Implementacja destruktora klasy DoublyLinkedList
DoublyLinkedList::~DoublyLinkedList() {
    while (head != tail) { // Pętla, która będzie wykonywać się, dopóki głowa nie osiągnie ogona listy
        head = head->next; // Ustawia głowę listy na następny element
        delete head->prev; // Usuwa poprzedni element
    }
    delete tail; // Usuwa ogon listy
}

// Implementacja metody insertHead klasy DoublyLinkedList
void DoublyLinkedList::insertHead(int value) {
    auto *node = new ListNode(value, nullptr,
                                  head); // Tworzy nowy węzeł z wartością, poprzednim elementem ustawionym na nullptr oraz następnym na głowę listy
    if (head != nullptr) {
        head->prev = node; // Jeśli lista nie jest pusta, ustawia poprzedni element głowy na nowy węzeł
    } else {
        tail = node; // Jeśli lista jest pusta, ustawia ogon na nowy węzeł
    }
    head = node; // Ustawia nowy węzeł jako głowę listy
    size++; // Zwiększa rozmiar listy o 1
}

// Implementacja metody insertTail klasy DoublyLinkedList
void DoublyLinkedList::insertTail(int value) {
    auto *node = new ListNode(value, tail,nullptr); // Tworzy nowy węzeł z wartością, poprzednim elementem ustawionym na ogon listy oraz następnym na nullptr
    if (tail != nullptr) {
        tail->next = node; // Jeśli lista nie jest pusta, ustawia następny element ogona na nowy węzeł
    } else {
        head = node; // Jeśli lista jest pusta, ustawia głowę na nowy węzeł
    }
    tail = node; // Ustawia nowy węzeł jako ogon listy
    size++; // Zwiększa rozmiar listy o 1
}

// Metoda wstawiająca nowy węzeł z wartością "value" na określonej pozycji "index"
void DoublyLinkedList::insert(int value, int index) {
// Sprawdzenie, czy indeks jest poprawny
    if (index < 0 || index > size) {
        cout << "There is no element with index: [" << index << "]" << endl;
        return;
    }

// Wstawienie węzła na początek listy
    if (index == 0) {
        insertHead(value);
        return;
    }
// Wstawienie węzła na koniec listy
    else if (index == size - 1) {
        insertTail(value);
        return;
    }
// Wstawienie węzła w środku listy
    else {
        ListNode *prev_node = head;
        for (int i = 0; i < index - 1; i++) {
            prev_node = prev_node->next;
        }
        auto next_node = prev_node->next;
        auto *node = new ListNode(value, prev_node, next_node);
        prev_node->next = node;
        next_node->prev = node;
    }

    size++;
}

// usuwa element na początku listy dwukierunkowej
void DoublyLinkedList::removeHead() {
    if (head != nullptr) {
        if (size != 1) {
            // Ustawia wskaźnik prev elementu head na nullptr, ponieważ będzie to nowa głowa listy.
            head->next->prev = nullptr;
            // Ustawia wskaźnik head na następny element.
            head = head->next;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    } else {
        cout << "List is empty" << endl;
    }
}

// usuwa element na końcu listy dwukierunkowej
void DoublyLinkedList::removeTail() {
    if (tail != nullptr) {
        if (size != 1) {
            // Ustawia wskaźnik next elementu tail na nullptr, ponieważ będzie to nowy koniec listy.
            tail->prev->next = nullptr;
            // Ustawia wskaźnik tail na poprzedni element.
            tail = tail->prev;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        size--;
    } else {
        cout << "List is empty" << endl;
    }
}

// usuwa element o danym indeksie z listy dwukierunkowej
void DoublyLinkedList::remove(int index) {
    // jeśli indeks jest mniejszy od zera lub większy niż rozmiar listy, wypisz komunikat i zakończ funkcję
    if (index < 0 || index >= size) {
        cout << "There is no element with index: [" << index << "]" << endl;
        return;
    }

    // jeśli indeks wynosi zero, wywołaj metodę removeHead() i zakończ funkcję
    if (index == 0) {
        removeHead();
        return;
    }

    // jeśli indeks wynosi size - 1, wywołaj metodę removeTail() i zakończ funkcję
    if (index == size - 1) {
        removeTail();
        return;
    }

    // w przeciwnym razie znajdź element o danym indeksie i usuń go
    ListNode *node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    size--;
}


// wyświetla zawartość listy od początku do końca
void DoublyLinkedList::displayList() {
    if (head != nullptr) {
        ListNode *tempNode = head;
        while (tempNode != nullptr) {
            cout << tempNode->value << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    } else {
        cout << "List is empty" << endl;
    }
}

// wyświetla zawartość listy od końca do początku
void DoublyLinkedList::displayListBackward() {
    if (head != nullptr) {
        ListNode *tempNode = tail;
        while (tempNode != nullptr) {
            cout << tempNode->value << " ";
            tempNode = tempNode->prev;
        }
    } else {
        cout << "List is empty" << endl;
    }
}

// sprawdza, czy element o podanej wartości istnieje w liście
bool DoublyLinkedList::checkIfExist(int value) {
    if (head != nullptr) {
        ListNode *tempNode = head;
        while (tempNode->value != value) {
            tempNode = tempNode->next;
            if (!tempNode) {
                return false;
            }
        }
        cout << "This value exists in list" << endl;
        return true;
    } else {
        cout << "List is empty" << endl;
        return false;
    }
}

