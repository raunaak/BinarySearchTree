#ifndef MERGETWOBST_H
#define MERGETWOBST_H
#include"BNode.h"
#include <stack>
using namespace std;
template<typename T>
void merge(BNode<T>* root1, BNode<T>* root2){
    /*Idea:
     * Iterative Inorder traversal 
     * 2 stacks for 2 bst
     * add elements to stack so that smallest element pops out
     * when stack is poped, refill by continuing the inorder traversal
     */
    stack<BNode<T>*> s1;
    stack<BNode<T>*> s2;
    while((!s1.empty()||root1)||(!s2.empty()||root2)){
        while(root1){s1.push(root1); root1 = root1->left;}
        while(root2){s2.push(root2); root2 = root2->left;}
        if(s1.size()>0&&s2.size()>0){
            if(s1.top()->data<=s2.top()->data){
                root1 = s1.top()->right;
                cout<<s1.top()->data<<" "; 
                s1.pop();
                while(root1){s1.push(root1); root1 = root1->left;}
            }
            else{
                root2 = s2.top()->right;
                cout<<s2.top()->data<<" ";
                s2.pop();
                while(root2){s2.push(root2); root2 = root2->left;}
            }
        }else if(s1.size()>0){
            root1 = s1.top()->right;
            cout<<s1.top()->data<<" "; 
            s1.pop();
            while(root1){s1.push(root1); root1 = root1->left;}            
        }else if(s2.size()>0){
            root2 = s2.top()->right;
            cout<<s2.top()->data<<" ";
            s2.pop();
            while(root2){s2.push(root2); root2 = root2->left;}
        }
    }
}


#endif /* MERGETWOBST_H */

