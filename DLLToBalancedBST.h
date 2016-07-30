#ifndef DLLTOBALANCEDBST_H
#define DLLTOBALANCEDBST_H
#include<iostream>
#include<cstddef>
#include "BNode.h"
#include "LinkedDeque.h"
using namespace std;
// Next 3 functions display first method to convert doubly linked list to balanced binary search tree
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

//Second method to convert doubly linked list to balanced binary search tree
template<typename T>
BNode<T>* createBST(DoubleNode<T>** head, int n){
    /* Algorithm: Recursion
     * head is a pointer to the pointer which points to the current node to be added to BST
     * n is the number of nodes in the subtree under consideration
     * To create BST of n nodes, head currently is a pointer to pointer to the first node
     * Create the left subtree with n/2 nodes, head still being the same
     * Now, after we create left subtree, head, node under consideration is the n/2+1 th node since we have to add it to BST
     * Create binary tree node consisting of head data
     * Update head to point to next
     * Create the left subtree with n/2 nodes     
     * Now, after we create left subtree, head, node under consideration is the n+1 th node since we have to add it to BST
     * Connect root to the 2 subtrees
     */
    if(n<=0)return NULL;
    if(n==1)
    {
        DoubleNode<T>* h = *head;
        *head = (*head)->next;
        cout<<h->data<<" ";
        return newNode(h->data);
    }
    BNode<T>* left = createBST(head, n/2);
    BNode<T>* root = newNode((*head)->data); 
    cout<<(*head)->data<<" ";
    *head = (*head)->next;
    BNode<T>* right = createBST(head, n-n/2-1);
    root->left = left;
    root->right = right;
    return root;
}

template<typename T>
BNode<T>* sortedListToBST2(DoubleNode<T>* head){
    DoubleNode<T>* temp = head; int n = 0;
    while(temp){temp=temp->next; n++;}
    cout<<n<<" "<<head->data<<endl;
    return createBST(&head, n);
}
#endif /* DLLTOBALANCEDBST_H */