/*
Created by @zch0423 on 2020/10/17.
Filename: queue.cpp
Content: 
*/
#include "queue.h"

// 循环顺序队列
template <typename T>
seqQueue<T>::seqQueue(int size) {
    maxSize = size;
    front = rear = 0;
    data = new T[size];
}

template <typename T>
seqQueue<T>::~seqQueue() {
    delete []data;
}

template <typename T>
bool seqQueue<T>::isEmpty() const {
    return front==rear;
}

template <typename T>
T seqQueue<T>::getHead() const{
    return data[(front+1)%maxSize];
}

template <typename T>
T seqQueue<T>::deQueue() {
    front = (front+1)%maxSize;
    return data[front]
}

template <typename T>
void seqQueue<T>::enQueue(const T &elem) {
    if((rear+1)%maxSize==front){
        doubleSpace();
    }
    rear = (rear+1)%maxSize;
    data[rear] = elem;
}

template <typename T>
void seqQueue<T>::doubleSpace() {
    T* temp = data;
    data = new T[maxSize*2];
    for (int i = 1; i <= maxSize; ++i) {
        data[i] = temp[(front+i)%maxSize];
    }
    front = 0;
    rear = maxSize;
    maxSize *= 2;
    delete []temp;
}

// 链式队列
template <typename T>
linkQueue<T>::linkQueue() {
    rear = nullptr;
}

template <typename T>
linkQueue<T>::~linkQueue() {
    while(rear!= nullptr){
        node* temp = rear->next;
        delete rear;
        rear = temp;
    }
}

template <typename T>
bool linkQueue<T>::isEmpty() const {
    return rear== nullptr;
}

template <typename T>
void linkQueue<T>::enQueue(const T &elem) {
    if(rear== nullptr){
        rear = new node(elem);
        rear->next = rear;
    }else{
        rear->next = new node(elem, rear->next);
        rear = rear->next;
    }
}

template <typename T>
T linkQueue<T>::deQueue() {
    node* temp = rear->next;
    T value = temp->data;
    if(rear==temp){
        rear = nullptr;
    }else{
        rear->next = temp->next;
    }
    delete temp;
    return value
}