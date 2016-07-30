#include <cstddef>
#include <iostream>
#include "BNode.h"
#include "SimpleOperationsOnBST.h"
#include "InorderSuccessor.h"
#include "kthSmallestElementInBST.h"
#include "MergeTwoBST.h"
#include "FloorAndCeilInBST.h"
using namespace std;

int main() {
    /*
     *                  50
     *              /       \
     *            30        70
     *          /   \      /   \  
     *         20   40    60    80  
     */
    
    /*
     *                  35
     *                /    \
     *              25      45
     */
    BNode<int>* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    /*Floor and ceil function in BST*/
    BNode<int>* n = floor(root, 75);
    if(n)cout<<n->data<<endl;
    n = ceil(root, 20);
    if(n)cout<<n->data<<endl;
    
    
    /*BNode<int>* root1 = NULL;
    root1 = insert(root1, 35);
    root1 = insert(root1, 45);
    root1 = insert(root1, 25);
    printmerge(root, root1); 
    */
    
    //Find kth smallest element in BST
    //BNode<int>* n = findMin(root, 5);
    //if(n)cout<<n->data<<endl;
    
    //Find inorder successor in BST
    //BNode<int>* n = inorderSuccessor(root, 40);
    //if(n)cout<<n->data<<endl;
    
    //Find minimum in BST
    //BNode<int>* n = findMin(root);
    //if(n)cout<<n->data<<endl;
    
    
    /* delete node in BST
    inorder(root);
    root = deleteNode(root, 70);
    inorder(root);*/
    return 0;
}

