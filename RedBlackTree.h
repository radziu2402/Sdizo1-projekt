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
    NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr parent);
    void preOrderHelper(NodePtr node);
    void inOrderHelper(NodePtr node);
    void postOrderHelper(NodePtr node);
    NodePtr searchTreeHelper(NodePtr node, int key);
    void deleteFix(NodePtr x);
    void rbTransplant(NodePtr u, NodePtr v);
    void deleteNodeHelper(NodePtr node, int key);
    void insertFix(NodePtr k);
    void printHelper(NodePtr root, string indent, bool last);
    NodePtr minimum(NodePtr node);
    NodePtr maximum(NodePtr node);
    NodePtr successor(NodePtr x);
    NodePtr predecessor(NodePtr x);
    void leftRotate(NodePtr x);
    void rightRotate(NodePtr x);
    NodePtr getRoot();
public:
    RedBlackTree();
    void preorder();
    void inorder();
    void postorder();
    void insert(int key);
    void deleteNode(int data);
    void printTree();
    NodePtr searchTree(int k);
};


#endif //SDIZO1_REDBLACKTREE_H
