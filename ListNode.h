//
// Created by radziu2402 on 06.03.2023.
//

#ifndef SDIZO1_LISTNODE_H
#define SDIZO1_LISTNODE_H


class ListNode {

public:
    int value;
    ListNode *prev;
    ListNode *next;

    ListNode(int value, ListNode *prev, ListNode *next);
};


#endif //SDIZO1_LISTNODE_H
