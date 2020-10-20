/*
Created by @zch0423 on 2020/9/28.
Filename: stack.h
Content: declaration of stack structure
*/

#ifndef CLIONPROJECT_STACK_H
#define CLIONPROJECT_STACK_H
// stack 抽象类
template <typename T>
class stack{
public:
    virtual bool isEmpty()const=0;
    virtual void push(const T& temp)=0;
    virtual T pop()=0;
    virtual T top()const =0;
    virtual ~stack(){}
};

// 顺序栈
template <typename T>
class seqStack:public stack<T>{
private:
    T* data;
    int maxSize;
    int topP;
    void doubleSpace();
public:
    explicit seqStack(int initSize=10);
    bool isEmpty()const;
    void push(const T& temp);
    T pop();
    T top()const;
    ~seqStack();
};

// 链表栈
template <typename T>
class linkStack:public stack<T>{
private:
    struct node{
        T data;
        node* next;
        node(const T&temp, node* n= nullptr){data=temp;next=n;}
        node(){next= nullptr;}
        ~node(){}
    };
    node* topP;
public:
    linkStack();
    ~linkStack();
    bool isEmpty()const;
    void push(const T&temp);
    T pop();
    T top()const ;
};

#endif //CLIONPROJECT_STACK_H
