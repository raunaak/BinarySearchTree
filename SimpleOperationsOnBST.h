#ifndef SIMPLEOPERATIONSONBST_H
#define SIMPLEOPERATIONSONBST_H
#include<iostream>
#include"BNode.h"
#include<limits>
using namespace std;

const int INT_MIN = numeric_limits<int>::min();
const int INT_MAX = numeric_limits<int>::max(); 

template<typename T>
BNode<T>* search(BNode<T>* root, const T& key){
    /*
     * Go to root
     * root.data = key FOUND!!
     * if(root.data<key) search in the right subtree
     * if(root.data>key) search in the left subtree
     */
    if(!root)return NULL;
    if(root->data==key)return root;
    if(root->data>key)return search(root->left, key);
    else return search(root->right, key);
}

template<typename T>
BNode<T>* insert(BNode<T>* root, const T& key){
    if(!root){root = newNode(key); return root;}
    if(root->data>=key)root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

template<typename T>
BNode<T>* deleteNode(BNode<T>* root, const T& key){
    if(root->data>key){
        root->left = deleteNode(root->left, key); return root;
    }else if(root->data<key){
        root->right = deleteNode(root->right, key); return root;
    }else{
        if(!root)return NULL;
        else if(!root->left){
            BNode<T>* temp = root->right;
            delete root;
            return temp;
        }else if(!root->right){
            BNode<T>* temp = root->left;
            delete root;
            return temp;
        }else{
            BNode<T>* node = root->left;
            while(node->right)node = node->right;
            T data = node->data;
            root->left = deleteNode(root->left, data);            
            root->data = data;
            return root;
        }
    }
}


template<typename T>
void inorder(BNode<T>* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

template<typename T>
BNode<T>* findMin(BNode<T>* root){
    if(!root)return NULL;
    while(root->left)root = root->left;
    return root;
}

template<typename T>
BNode<T>* findMax(BNode<T>* root){
    if(!root)return NULL;
    while(root->right)root = root->right;
    return root;
}
#endif /* SIMPLEOPERATIONSONBST_H */

