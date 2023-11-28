//
// Created by peter on 11/27/2023.
//

#ifndef NOVEMBER_27_BINARYSEARCHTREE_H
#define NOVEMBER_27_BINARYSEARCHTREE_H
#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* aLeft, Node* aRight);
    };
    Node* root;
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinarySearchTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();
};

#endif //NOVEMBER_27_BINARYSEARCHTREE_H
