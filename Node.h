//
// Created by radziu2402 on 06.03.2023.
//

#ifndef SDIZO1_NODE_H
#define SDIZO1_NODE_H


class Node {

public:
    int value;
    Node *prev;
    Node *next;

    Node(int, Node *, Node *);
};



#endif //SDIZO1_NODE_H
