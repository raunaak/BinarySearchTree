#ifndef DOUBLENODE_H
#define DOUBLENODE_H
template<class T>
class DoubleNode{
public:    
    T data;
    DoubleNode<T>* pre;
    DoubleNode<T>* next;
    DoubleNode(T& data, DoubleNode<T>* pre, DoubleNode<T>* next);
};

template<class T>
DoubleNode<T>::DoubleNode(T& data, DoubleNode<T>* next, DoubleNode<T>* pre){
    this->data = data;
    this->pre = pre;
    this->next = next;
}

#endif /* DOUBLENODE_H */

