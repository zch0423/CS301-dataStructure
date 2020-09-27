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
