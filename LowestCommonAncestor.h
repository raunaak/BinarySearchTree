#ifndef LOWESTCOMMONANCESTOR_H
#define LOWESTCOMMONANCESTOR_H
#include"BNode.h"
#include "SimpleOperationsOnBST.h"
using namespace std;

template<typename T> lca(BNode<T>* root, const T& key1, const T& key2){
    if(root){
        if((root->data-key1)*(root->data-key2)<=0)return root;
        else if(root->data<key1)return lca(root->right, key1, key2);
        else return lca(root->data>key2);
    }
}

template<typename T>
BNode<T>* lowestCommonAncestor(BNode<T>* root, const T& key1, const T& key2){
    if(search(root, key1)&&search(root, key2))return lca(root, key1, key2);
    return NULL;
    
}

#endif /* LOWESTCOMMONANCESTOR_H */
