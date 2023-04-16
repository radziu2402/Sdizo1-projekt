//
// Created by radziu2402 on 20.03.2023.
//

#include "RedBlackTree.h"
// Tworzenie drzewa Red-Black.
// Inicjalizacja koloru NIL na 0 (czarny), wskaźników left i right na nullptr oraz ustawienie korzenia na NIL.
RedBlackTree::RedBlackTree() {
    NIL = new Node;
    NIL->color = 0;
    NIL->left = nullptr;
    NIL->right = nullptr;
    root = NIL;
}

// Usuwanie drzewa Red-Black.
// Usunięcie korzenia oraz NIL-a.
RedBlackTree::~RedBlackTree() {
    delete (root);
    delete NIL;
}

// Przejście drzewa w porządku Preorder.
// Wyświetlenie wartości w węźle, przejście do lewego poddrzewa, przejście do prawego poddrzewa.
void RedBlackTree::preOrderHelper(NodePtr node) {
    if (node != NIL) {
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

// Przejście drzewa w porządku Inorder.
// Przejście do lewego poddrzewa, wyświetlenie wartości w węźle, przejście do prawego poddrzewa.
void RedBlackTree::inOrderHelper(NodePtr node) {
    if (node != NIL) {
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

// Przejście drzewa w porządku Postorder.
// Przejście do lewego poddrzewa, przejście do prawego poddrzewa, wyświetlenie wartości w węźle.
void RedBlackTree::postOrderHelper(NodePtr node) {
    if (node != NIL) {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }
}

NodePtr RedBlackTree::searchTreeHelper(NodePtr node, int key) {
    if (node == NIL || key == node->data) {
        return node;
    }

    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

// naprawa drzewa po usunieciu wierzcholka
void RedBlackTree::deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    s->left->color = 0;
                    s->color = 1;
                    rightRotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    s->right->color = 0;
                    s->color = 1;
                    leftRotate(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}

void RedBlackTree::rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = NIL;
    NodePtr x, y;
    while (node != NIL) {
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == NIL) {
        cout << "Key not found in the tree" << endl;
        return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == NIL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
        deleteFix(x);
    }
}

// naprawa drzewa po dodaniu wierzcholka
void RedBlackTree::insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = 0;
}

void RedBlackTree::printHelper(NodePtr root, int level) {
    if (root != NIL) {
        printHelper(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        if (root->color) {
            cout << root->data << " (R)" << endl;
        } else {
            cout << root->data << " (B)" << endl;
        }
        printHelper(root->left, level + 1);
    }
}

void RedBlackTree::preorder() {
    preOrderHelper(this->root);
}

void RedBlackTree::inorder() {
    inOrderHelper(this->root);
}

void RedBlackTree::postorder() {
    postOrderHelper(this->root);
}

NodePtr RedBlackTree::searchTree(int k) {
    return searchTreeHelper(this->root, k);
}

NodePtr RedBlackTree::minimum(NodePtr node) {
    while (node->left != NIL) {
        node = node->left;
    }
    return node;
}


//rotacja w lewo
void RedBlackTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
//rotacja w prawo
void RedBlackTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != NIL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// dodawanie wierzcholka do drzewa
void RedBlackTree::insert(int key) {
    auto node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = NIL;
    node->right = NIL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != NIL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == nullptr) {
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    insertFix(node);
}

//usuwanie wierzcholka
void RedBlackTree::deleteNode(int data) {
    deleteNodeHelper(this->root, data);
}
// wyswietlanie drzewa
void RedBlackTree::printTree() {
    if (root) {
//        printHelper(this->root, "", true);
        printHelper(this->root,0);
    }
}
