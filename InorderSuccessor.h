#ifndef INORDERSUCCESSOR_H
#define INORDERSUCCESSOR_H
#include"BNode.h"
using namespace std;

template<typename T>
BNode<T>* inorderSuccessor(BNode<T>* root, const T& data){
    if(!root)return NULL;
    if(root->data==data)return findMin(root->right);
    if(root->data>data){
        BNode<T>* n = inorderSuccessor(root->left, data);
        return (n?n:root);
    }else return inorderSuccessor(root->right, data);
}
#endif /* INORDERSUCCESSOR_H */

