#include <cstddef>
#include <iostream>
#include "BNode.h"
#include "SimpleOperationsOnBST.h"
using namespace std;

int main() {
    BNode<int>* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    root = deleteNode(root, 70);
    inorder(root);
    return 0;
}

