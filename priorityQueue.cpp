/*
 *   FileName      ：priorityQueue.cpp
 *   Author        ：@zch0423
 *   Date          ：2020年11月07日
 *   Description   ：优先队列二叉堆实现
*/
#include "priorityQueue.h"
template<typename T>
priorityQueue<T>::priorityQueue(int capacity=100){
    elem = new T[capacity ];
    maxSize = capacity;
    currentSize = 0;
}

template<typename T>
priorityQueue<T>::~priorityQueue(){
    delete []elem;
}

template<typename T>
bool priorityQueue<T>::isEmpty()const{
    return currentSize == 0;
}

template<typename T>
T priorityQueue<T>::getHead()const{
    return elem[1];
}

template<typename T>
void priorityQueue<T>::enQueue(const T&x){
    if(currentSize==maxSize-1)doubleSpace();
    // 向上过滤
    int hole = ++currentSize;
    for(;hole>1&&x<elem[hole/2];hole/=2){
        elem[hole] = elem[hole/2];
    }
    elem[hole] = x;
}

template<typename T>
T priorityQueue<T>::deQueue(){
    T minItem;
    minItem = elem[1];
    elem[1] = elem[currentSize--];
    percolateDown(1); //向下过滤
    return minItem;
}

template<typename T>
void priorityQueue<T>::percolateDown(int hole){
    int child;
    T temp = elem[hole];
    for(; hole*2<currentSize; hole=child){
        child = hole*2;
        if(child!=currentSize&&elem[child+1]<elem[child]){
            ++child;//选择左右子女中最小的那个
        }
        if(elem[child]<temp){
            elem[hole ] = elem[child];
        }else{
            break;
        }
    }
    elem[hole] = temp;
}

template<typename T>
void priorityQueue<T>::buildHeap(){
    // O(n)
    for(int i=currentSize/2;i>0;i--){
        // 叶节点不需要percolateDown，所以从最大非叶节点开始
        percolateDown(i);
    }

}

template<typename T>
priorityQueue<T>::priorityQueue(const T* items, int size ):maxSize(size+10),currentSize(size){
    elem = new T[maxSize];
    for(int i=0;i<size;++i){
        elem[i+1] = items[i];
    }
    buildHeap()
}

template<typename T>
void priorityQueue<T>::doubleSpace(){
    T* temp = elem;
    maxSize *= 2;
    elem = new T[maxSize ];
    for(int i=0;i<=currentSize;++i){
        elem[i] = temp[i];
    }
    delete [] temp;
}

template<typename T>
void leftHeap<T>::swapNode(node* &x, node* &y){
   node* temp;
   temp = x;
   x = y;
   y = temp;
}

template<typename T>
node* merge(node*&x, node*&y){
    if(x==nullptr){
        return y;
    }
    if(y==nullptr ){
        return x;
    }
    // x值小于y
    if(x->data>y->data){
        swapNode(x, y);
    }
    // 将y合并到x右子树
    x->right = merge(x->right, y);

    // 交换位置
    if(x->left==nullptr||x->left->npl<x->right->npl){
        swapNode(x->left, x->right);
    }
    // set npl
    if(x->right==nullptr ){
        x->npl = 0;
    }else{
        x->npl = x->right->npl+1;
    }
    return x;
}

template<typename T>
void leftHeap<T>::merge(leftHeap<T>*other ){
    root = merge(root, other->root);
}

template<typename T>
leftHeap<T>::leftHeap(){
    root = nullptr;
}

template<typename T>
void leftHeap<T>::clear(node*&h){
    if(h==nullptr ){
        return 
    }
    if(h->right!=nullptr ){
        clear(h->right );
    }
    if(h->left!=nullptr ){
        clear(h->left );
    }
    delete h;
}

template<typename T>
leftHeap<T>::~leftHeap(){
    clear(root);
}

template<typename T>
bool isEmpty()const{
    return root==nullptr;
}

template<typename T>
void leftHeap<T>::enQueue(const T& x){
    node* temp = new node(x);
    root = merge(root, temp);
}

template<typename T>
T leftHeap<T>::deQueue(){
    node* temp = root;
    root = merge(root->right, root->left);
    T result = temp->data;
    delete temp;
    return result;
}

