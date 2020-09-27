/*
filename: linearList.h
content: declaration of Linear List structure including seqList linklist
*/
#ifndef _LIST_H
#define _LIST_H

template <class elemType>
class list{
    public:
    virtual void clear()=0;
    virtual int length()=0;
    virtual void insert(int i, const elemType& x)=0;
    virtual void remove(int i)=0;
    virtual int search(const elemType& x)const=0;
    virtual elemType visit(int i)const=0;
    virtual void traverse()const =0;
    virtual ~list()= default;
};

template<class elemType>
class seqList:public list<elemType>{
    // 顺序表
    private:
        elemType* data;
        int currentLength;
        int maxSize;
        void doubleSpace();

    public:
        seqList(int initSize=10);
        ~seqList();
        void clear();
        int length()const;
        void insert(int i, const elemType& x);
        void remove(int i);
        int search(const elemType&x)const;
        elemType visit(int i)const;
        void erase(int i); // 删除所有等于第i个元素的元素 包括i
        void traverse()const;
};


#endif