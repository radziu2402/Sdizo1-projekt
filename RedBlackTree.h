//
// Created by radziu2402 on 20.03.2023.
//

#ifndef SDIZO1_REDBLACKTREE_H
#define SDIZO1_REDBLACKTREE_H


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr NIL;



    void preOrderHelper(NodePtr node);

    void inOrderHelper(NodePtr node);

    void postOrderHelper(NodePtr node);

    NodePtr searchTreeHelper(NodePtr node, int key);

    void deleteFix(NodePtr x);

    void rbTransplant(NodePtr u, NodePtr v);

    void deleteNodeHelper(NodePtr node, int key);

    void insertFix(NodePtr k);

    void printHelper(NodePtr ptr, int level);

    NodePtr minimum(NodePtr node);

    void leftRotate(NodePtr x);

    void rightRotate(NodePtr x);


public:
    int size;
    RedBlackTree();

    ~RedBlackTree();

    void preorder();

    void inorder();

    void postorder();

    void insert(int key);

    void deleteNode(int data);

    void printTree();

    NodePtr searchTree(int k);
};


#endif //SDIZO1_REDBLACKTREE_H
