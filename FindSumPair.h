#ifndef FINDSUMPAIR_H
#define FINDSUMPAIR_H
#include "BNode.h"
#include <stack>
#include <iostream>
using namespace std;

bool isPairSum(BNode<int>* root, int sum){
    /* Algorithm
     * Traverse inorder and reverse inorder 
     * If we find the sum is greater than required sum, reverse inorder
     * If we find the sum is smaller than required sum, inorder
     * If we find the sum equal, return true
     */
    stack<BNode<int>*> s1, s2;
    BNode<int>* curr1 = root; BNode<int>* curr2 = root;
    while(!((!curr1&&s1.empty())||(!curr2&&s2.empty()))){
        while(curr1){s1.push(curr1); curr1 = curr1->left;}
        while(curr2){s2.push(curr2); curr2 = curr2->right;}
        curr1 = s1.top(); s1.pop();
        curr2 = s2.top(); s2.pop();
        if(curr1->data+curr2->data==sum)return true;
        else if(curr1->data+curr2->data>sum){
            s1.push(curr1); curr2 = curr2->left;
        }else{
            s2.push(curr2); curr1 = curr1->right;
        }
    }    
    return false;
}

#endif /* FINDSUMPAIR_H */