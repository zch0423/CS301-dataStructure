/*
Created by @zch0423 on 2020/10/17.
Filename: queue.h
Content: 
*/



#ifndef CLIONPROJECT_QUEUE_H
#define CLIONPROJECT_QUEUE_H

template <typename T>
class queue{
public:
    virtual bool isEmpty() const=0;
    virtual void enQueue(const T& elem)=0;
    virtual T deQueue()=0;
    virtual T getHead()const =0;
    virtual ~queue()=0;
};

// 顺序队列
template <typename T>
class seqQueue:public queue<T>{
// 牺牲一个单位来区别空和满
// 也可用length+front实现
private:
    T* data;
    int maxSize;
    void doubleSpace();
    int front;
    int rear;
public:
    explicit seqQueue(int size=10);
    bool isEmpty()const;
    void enQueue(const T&elem);
    T deQueue();
    T getHead()const;
    ~seqQueue();
};

// 链式队列
template <typename T>
class linkQueue:public queue<T>{
private:
    struct node{
        T data;
        node* next;
        node(){
            next = nullptr;
        }
        node(const T&elem, node* n= nullptr){
            data = elem;
            next = n;
        }
        ~node(){}
    };
    node *rear; // 使用循环链表存储
public:
    linkQueue();
    ~linkQueue();
    bool isEmpty()const;
    void enQueue(const T&elem);
    T deQueue();
    T getHead()const;
};

#endif //CLIONPROJECT_QUEUE_H
