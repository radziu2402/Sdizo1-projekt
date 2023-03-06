//
// Created by radziu2402 on 06.03.2023.
//

#ifndef SDIZO1_LISTELEMENTS_H
#define SDIZO1_LISTELEMENTS_H


class ListElements {

public:
    ListElements *next;
    ListElements *before;
    int value;

    ListElements(int, ListElements *, ListElements *);
};



#endif //SDIZO1_LISTELEMENTS_H
