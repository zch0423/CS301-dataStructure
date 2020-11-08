/*
 *   FileName      ：priorityQueue.h
 *   Author        ：@zch0423
 *   Date          ：2020年11月07日
 *   Description   ：definition of priorityQueue  二叉堆
*/
#ifndef  H_priorityQueue
#define H_priorityQueue

template<typename T>
class priorityQueue{
    public:
        priorityQueue(int capacity=100);
        priorityQueue(const T data[], int size);
        ~priorityQueue();
        bool isEmpty()const;
        void enQueue(const T&x);
        T deQueue();
        T getHead()const;
    private:
        int currentLength;
        T* elem;
        int maxSize;
        void doubleSpace();
        void buildHeap();
        void percolateDown(int hole); //向下过滤
};

template<typename T>
class leftHeap{
private:
    struct node{
        T data;
        node* lchild;
        node* rchild;
        int nlp;
        node(const T&d, node* l =nullptr, node* r=nullptr ){
            nlp = 0;
            data = d;
            lchild = l;
            rchild = r;
        }
        node(){
            lchild = nullptr;
            rchild = nullptr;
            nlp = 0;
        }
        ~node() = default;
    };
    void swapNode(node* &x, node* &y); // 交换xy 
    void clear(node*& h);
    node* merge(node* &x, node* &y);
    node* root;

public:
    leftHeap();
    ~leftHeap();
    void enQueue(const T& x);
    T deQueue();
    bool isEmpty() const;
    void merge(leftHeap<T> * other);
};


#endif
