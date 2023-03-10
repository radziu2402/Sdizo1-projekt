//
// Created by radziu2402 on 06.03.2023.
//

#include "Node.h"

Node::Node(int value, Node *prev, Node *next) {
    Node::value = value;
    Node::prev = prev;
    Node::next = next;
}
