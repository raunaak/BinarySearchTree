#ifndef KTHSMALLESTELEMENTINBST_H
#define KTHSMALLESTELEMENTINBST_H
#include"BNode.h"
using namespace std;
template<typename T>
BNode<T>* findMin1(BNode<T>* root, int & k){
    /*Idea: inorder traversal in BST traverses from minimum to maximum
     */
    
    /*Algorithm:
     * Go to root
     * If root is NULL, return NULL
     * Go to its left subtree and try to find kth minimum there first
     * If left subtree contains kth smallest, return it else
     * Check whether root is the kth smallest, we are reducing k every time print a node
     * So, when we pass through leftmost node (the first node in inorder traversal our k is k-1)
     * So, when we pass through kth smallest node our k is 0
     * if(k=0) when passing a node, return node (we have hit jackpot)
     * else go to right subtree and return whatever it intends to
     */
    if(root){
       BNode<T>* n = findMin1(root->left, k);
       if(n)return n;
       k--;
       if(k==0)return root;
       return findMin1(root->right, k);
    }
    return NULL;
}

template<typename T>
BNode<T>* findMin(BNode<T>* root, const int k){
    int a = k;
    return findMin1(root, a);
}
#endif /* KTHSMALLESTELEMENTINBST_H */

