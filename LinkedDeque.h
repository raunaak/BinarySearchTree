#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H
#include "DoubleNode.h"
#include <cstddef>
using namespace std;
template<class T>
class LinkedDeque{
public:
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
    LinkedDeque();
    void insertFront(T& data);
    void insertLast(T& data);
    T& deleteFront();
    T& deleteLast();
    T& getFront();
    T& getRear();
    void print();
    bool isEmpty();
};

template<class T>
LinkedDeque<T>::LinkedDeque(){
    head = NULL;
    tail = NULL;
}

template<class T>
void LinkedDeque<T>::insertFront(T& data){
    DoubleNode<T>* n = new DoubleNode<T>(data, head, NULL);
    if(tail==NULL){tail=n; head=n;}
    else{head->pre=n; head=n;}
} 

template<class T>
void LinkedDeque<T>::insertLast(T& data){
    DoubleNode<T>* n = new DoubleNode<T>(data,NULL,tail);
    if(head==NULL){head = n; tail=n;}
    else{tail->next=n; tail=n;}
}

template<class T>
T& LinkedDeque<T>::deleteFront(){
    if(head==NULL)throw string("Deque empty");
    T t = head->data;
    DoubleNode<T>* n = head;
    if(head==tail)tail=NULL;
    head = head->next;
    if(head)head->pre=NULL;
    delete n;
    return t;
}

template<class T>
T& LinkedDeque<T>::deleteLast(){
   if(head==NULL)throw string("Deque empty");
   T t = tail->data;
   DoubleNode<T>* n = tail;
   if(head==tail)head = NULL;
   tail = tail->pre;
   if(tail)tail->next = NULL;
   delete n;
   return t;
}

template<class T>
T& LinkedDeque<T>::getFront(){
   if(head==NULL)throw string("Deque empty");
   return head->data; 
}

template<class T>
T& LinkedDeque<T>::getRear(){
    if(head==NULL)throw string("Deque empty");
    return tail->data;
}

template<class T>
void LinkedDeque<T>::print(){
    DoubleNode<T>* n = head;
    while(n){cout<<n->data<<" "; n = n->next;}
    cout<<endl;
}

template<class T>
bool LinkedDeque<T>::isEmpty(){
    return head==NULL;
}
#endif /* LINKEDDEQUE_H */

