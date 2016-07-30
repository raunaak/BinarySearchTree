#ifndef DLLTOBALANCEDBST_H
#define DLLTOBALANCEDBST_H
#include<iostream>
#include<cstddef>
#include "BNode.h"
#include "LinkedDeque.h"
using namespace std;

template<typename T>
DoubleNode<T>* findMid(DoubleNode<T>* head, DoubleNode<T>* tail){
    DoubleNode<T>* slow = head; DoubleNode<T>* fast = head;
    while(fast!=tail){
        fast = fast->next;
        if(fast!=tail){fast = fast->next; slow = slow->next;}
    }
    return slow;
}

template<typename T>
BNode<T>* sortedListToBST12(DoubleNode<T>* head, DoubleNode<T>* tail){
    /* Algorithm:
     * Go to middle node
     * Create left subtree
     * Create right subtree
     * Make them as left and right child of mid node
     * return mid
     */
    if(head==tail)return NULL;
    if(head->next==tail)return newNode(head->data);
    DoubleNode<T>* mid = findMid(head,tail);
    BNode<T>* left = sortedListToBST12(head, mid);
    BNode<T>* right = sortedListToBST12(mid->next,tail);
    BNode<T>* root = newNode(mid->data);
    root->left = left;
    root->right = right;
    return root;
}

template<typename T>
BNode<T>* sortedListToBST1(DoubleNode<T>* head){
    DoubleNode<T>* tail = NULL;
    return sortedListToBST12(head, tail);
}


#endif /* DLLTOBALANCEDBST_H */

