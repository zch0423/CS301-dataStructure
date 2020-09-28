/*
filename: linearList.cpp
content: implementation of linear list structure defined in linearList.h
*/
#include <iostream>
#include "linearList.h"
using namespace std;

// implementation of seqList
template<class elemType>
seqList<elemType>::~seqList(){
    delete []data;
}

template <class elemType>
void seqList<elemType>::clear() {
    currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const {
    return currentLength;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const {
    cout<<endl;
    for(int i=0;i<currentLength;++i){
        cout<<data[i];
    }
}

template <class elemType>
seqList<elemType>::seqList(int initSize) {
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const {
    for(int i=0;i<currentLength;++i){
        if(data[i]==x){
            return i;
        }
    }
    return -1;
}

template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType* temp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i=0;i<currentLength;++i){
        data[i] = temp[i];
    }
    delete []temp;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x) {
    if(currentLength==maxSize){
        doubleSpace();
    }
    for(int j=currentLength;j>i;--j){
        data[j] = data[j-1];
    }
    data[i] = x;
    ++currentLength;
}

template<class elemType>
void seqList<elemType>::remove(int i) {
    for(int j=i;j<currentLength-1;++j){
        data[j] = data[j+1];
    }
    --currentLength;
}

template <class elemType>
void seqList<elemType>::erase(int i) {
    elemType temp = data[i];
    int count = 0;
    for(int j=0;j<currentLength;++j){
        if(data[j]==temp){
            ++count;
        }else {
            data[j - count] = data[j];
        }
    }
    currentLength -= count;
}

// 单链表类
template <class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const {
    //向前移动i个，对head而言移动i+1次
    node * p = head;
    while(i-- >=0){
        p = p->next;
    }
    return p;
}

template <class elemType>
sLinkList<elemType>::sLinkList() {
    head = new node;
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::clear() {
    node *p = head->next, *temp;
    while(p!=nullptr){
        temp = p->next;
        delete p;
        p = temp;
    }
    head->next = nullptr;
    currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x) {
    node* p = move(i-1);
    node* temp = new node(x, p->next);
    p->next = temp;
    ++currentLength;
}

template <class elemType>
void sLinkList<elemType>::remove(int i) {
    node* p = move(i-1);
    node* temp;
    temp = p->next;
    p->next = temp->next;
    delete temp;
    --currentLength;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const {
    node* p = head->next;
    int count = 0;
    while(p!=nullptr){
        if(p->data==x){
            return count;
        }
        ++count;
        p = p->next;
    }
    return -1;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const {
    cout<<endl;
    node* p=head->next;
    while(p!= nullptr){
        cout<<p->data<<"  ";
        p = p->next;
    }
    cout<<endl;
}

