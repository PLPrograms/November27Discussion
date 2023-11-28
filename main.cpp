#include <iostream>
#include "BinarySearchTree.h"

/* Add these methods to your class to be able to print the tree

     void displayInOrder(Node* aNodePtr){
        if (aNodePtr) {
            displayInOrder(aNodePtr->left);
            std::cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    }

    void printTree(){
        displayInOrder(root);
        std::cout << std::endl;
    };
*/



int main() {

    auto tree = BinarySearchTree();

    tree.insertNode(5);
    tree.insertNode(10);
    tree.insertNode(1);
    tree.printTree();

    // Insert nodes around 1
    tree.insertNode(0);
    tree.insertNode(3);
    tree.printTree();

    // Insert Nodes around 10
    tree.insertNode(9);
    tree.insertNode(11);
    tree.printTree();


    // Testing Delete:
    // Removing a branch
    tree.remove(0);
    tree.printTree();

    // Removing a Node in the middle
    tree.remove(1);
    tree.printTree();

    // Removing root
    tree.remove(5);
    tree.printTree();

    // Validating Search
    std::cout << tree.searchNode(5) << std::endl;
    std::cout << tree.searchNode(10) << std::endl;
    std::cout << tree.searchNode(100) << std::endl;

    return 0;
}
