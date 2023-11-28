//
// Created by peter on 11/27/2023.
//

#include "BinarySearchTree.h"

BinarySearchTree::Node::Node(int aVal, Node* aLeft = nullptr, Node* aRight = nullptr) {
    val = aVal;
    left = aLeft;
    right = aRight;
}
void BinarySearchTree::insert(Node* &aNodePtr, Node* &aNewNodePtr) {
    Node* currentNode = aNodePtr;
    bool inserted = false;
    if (root == nullptr) {
        root = aNewNodePtr;
    }
    else {
        while (!inserted) {
            if (aNewNodePtr->val > currentNode->val) {
                if (currentNode->right == nullptr) {
                    currentNode->right = aNewNodePtr;
                    inserted = true;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
            else {
                if (currentNode->left == nullptr) {
                    currentNode->left = aNewNodePtr;
                    inserted = true;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
        }
    }
}
void BinarySearchTree::deleteNode(int aVal, Node* &aNodePtr) {
    Node* currentNode = aNodePtr;
    bool deleted = false;
    while (!deleted) {
        if (aVal == currentNode->val) {
            makeDeletion(currentNode);
            deleted = true;
        }
        else if (aVal > currentNode->val) {
            currentNode = currentNode->right;
        }
        else {
            currentNode = currentNode->left;
        }
    }
}
void BinarySearchTree::makeDeletion(Node* &aNodePtr) {
    //cout << "Deleting node with value: " << aNodePtr->val << endl;
    int target = aNodePtr->val;
    Node* currentNode = root;
    Node* parentNode = nullptr;
    bool parentFound = false;
    if (aNodePtr == root) {
        if (root != nullptr) {
            root = aNodePtr->right;
            insert(root, aNodePtr->left);
            delete aNodePtr;
        }
    }
    else {
        while (!parentFound && (currentNode != nullptr)) {
            if ((aNodePtr == currentNode->right) || (aNodePtr == currentNode->left)) {
                parentNode = currentNode;
                parentFound = true;
            }
            else if (target < currentNode->val) {
                currentNode = currentNode->left;
            }
            else {
                currentNode = currentNode->right;
            }
        }
        if (currentNode == nullptr) {
            cout << "Node not found" << endl;
        }
        else {
            if ((aNodePtr->left != nullptr) && (aNodePtr->right != nullptr)) {
                if (aNodePtr->val < parentNode->val) {
                    parentNode->left = aNodePtr->right;
                    insert(aNodePtr->right, aNodePtr->left);
                } else {
                    parentNode->right = aNodePtr->right;
                    insert(aNodePtr->right, aNodePtr->left);
                }
            }
            else if ((aNodePtr->left != nullptr) && (aNodePtr->right == nullptr)) {
                if (aNodePtr->val < parentNode->val) {
                    parentNode->left = aNodePtr->left;
                } else {
                    parentNode->right = aNodePtr->left;
                }
            }
            else if ((aNodePtr->left == nullptr) && (aNodePtr->right != nullptr)) {
                if (aNodePtr->val < parentNode->val) {
                    parentNode->left = aNodePtr->right;
                } else {
                    parentNode->right = aNodePtr->right;
                }
            }
            else {
                if (aNodePtr->val < parentNode->val) {
                    parentNode->left = nullptr;
                } else {
                    parentNode->right = nullptr;
                }
            }
            delete aNodePtr;
            //cout << "Crash?" << endl;
        }
    }
}
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}
void BinarySearchTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}
bool BinarySearchTree::searchNode(int aVal) {
    Node* currentNode = root;
    bool nodeFound = false;
    while ((currentNode != nullptr) && !nodeFound) {
        if (aVal == currentNode->val) {
            nodeFound = true;
        }
        else if (aVal > currentNode->val) {
            currentNode = currentNode->right;
        }
        else {
            currentNode = currentNode->left;
        }
    }
    return nodeFound;
}
void BinarySearchTree::remove(int aVal) {
    deleteNode(aVal, root);
}
void BinarySearchTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) { //cout << "print causes crash if parent pointer of leaf node is not set to null after delete" << endl;
        displayInOrder(aNodePtr->left);
        cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}
void BinarySearchTree::printTree(){
    displayInOrder(root);
    cout << endl;
};