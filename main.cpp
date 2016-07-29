#include <cstddef>
#include <iostream>
#include "BNode.h"
#include "SimpleOperationsOnBST.h"
#include "InorderSuccessor.h"
using namespace std;

int main() {
    /*
     *                  50
     *              /       \
     *            30        70
     *          /   \      /   \  
     *         20   40    60    80  
     */
    
    BNode<int>* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    
    BNode<int>* n = inorderSuccessor(root, 40);
    if(n)cout<<n->data<<endl;
    
    //Find minimum in BST
    //BNode<int>* n = findMin(root);
    //if(n)cout<<n->data<<endl;
    
    
    /* delete node in BST
    inorder(root);
    root = deleteNode(root, 70);
    inorder(root);*/
    return 0;
}

