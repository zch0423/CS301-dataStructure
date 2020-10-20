//
// Created by @zch0423 on 2020/9/28.
// Filename: stack.cpp
// Content: implementation of stack
//
#include "stack.h"
#include <iostream>
using namespace std;

//stack 顺序栈
template <typename T>
seqStack<T>::seqStack(int initSize) {
    data = new T[initSize];
    topP = -1;
    maxSize = initSize;
}

template <typename T>
seqStack<T>::~seqStack() {
    delete []data;
}

template <typename T>
void seqStack<T>::doubleSpace() {
    T* temp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < maxSize; ++i) {
        data[i] = temp[i];
    }
    delete []temp;
}

template <typename T>
bool seqStack<T>::isEmpty() const {
    return topP==-1;
}

template <typename T>
void seqStack<T>::push(const T &temp) {
    if(topP==maxSize-1){
        doubleSpace();
    }
    data[++topP] = temp;
}

template <typename T>
T seqStack<T>::pop() {
    return data[topP--];
}

template <typename T>
T seqStack<T>::top() const {
    return data[topP];
}

//链表栈
template <typename T>
linkStack<T>::linkStack() {
    topP= nullptr;
}

template <typename T>
linkStack<T>::~linkStack() {
    node* temp;
    while(topP!= nullptr){
        temp = topP->next;
        delete topP;
        topP = temp;
    }
}

template <typename T>
bool linkStack<T>::isEmpty() const {
    return topP== nullptr;
}

template <typename T>
void linkStack<T>::push(const T &temp) {
    topP = new node(temp, topP);
}

template <typename T>
T linkStack<T>::pop() {
    node* temp = topP;
    T data = temp->data;
    topP = topP->next;
    delete temp;
    return data;
}

template <typename T>
T linkStack<T>::top() const {
    return topP->data;
}
