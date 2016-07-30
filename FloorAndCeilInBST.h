#ifndef FLOORANDCEILINBST_H
#define FLOORANDCEILINBST_H
#include<iostream>
#include "BNode.h"
using namespace std;
//Ceil Value Node: Node with smallest data larger than or equal to key value.
template<typename T>
BNode<T>* ceil(BNode<T>* root, const T& data){
    /* Algorithm
     * if root is null, return null
     * if root data is key data, return root
     * if root data is greater than key data
     *      recurse the function in left subtree
     *      if left subtree returns a node, i am done
     *      if left subtree returns no node, root is the required
     * if root data is smaller than key data
     *      return whatever right subtree instructs to
     */
    if(!root)return NULL;
    if(root->data==data)return root;
    if(root->data>data){
        BNode<T>* n = ceil(root->left, data);
        return (n?n:root);
    }else return ceil(root->right, data);
}

//Floor Value Node: Node with value is smaller than or equal to key value
template<typename T>
BNode<T>* floor(BNode<T>* root, const T& data){
    /* Algorithm
     * if root is null, return null
     * if root data is key data, return root
     * if root data is greater than key data
     *      recurse the function in left subtree
     * if root data is smaller than key data
     *      recurse the function in left subtree
     *      if right subtree returns a node, i am done
     *      if right subtree does not return a node, return root
     */
    if(!root)return NULL;
    if(root->data==data)return root;
    if(root->data>data)return floor(root->left, data);
    else{
        BNode<T>* n = floor(root->right, data);
        return (n?n:root);
    }
}
#endif /* FLOORANDCEILINBST_H */

