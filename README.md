# content

Cpp implementation codes of data structures in course CS031

# implementation

## Linear list
- seqList 顺序表
- sLinkList 单链表
- dLinkList 双链表
- cLinkList 循环链表

*methods **
- void clear()
- int length()const;
- void insert(int i, const T&x)
- void remove(int i)
- int search(const T&x)const;
- elemType visit(int i)const;
- void traverse()const;

## Stack
- seqStack
- linkStack

methods
- bool isEmpty()const;
- void push(const T& temp);
- T pop();
- T top()const;

## Queue
- seqQueue
- linkQueue

methods
- bool isEmpty()const;
- void enQueue(const T&elem);
- T deQueue();
- T getHead()const;

## Tree
- seqBinaryTree // 未实现
- binaryTree
- hfTree // huffman tree

methods
- void clear()const;
- bool isEmpty()const;
- T root(T flag)const;
- T lchild(const T&x ,T flag )const;
- T rchild(const T&x, T flag )const;
- void delLeft(const T&x);
- void delRight(const T&x);
- void preOrder()const;
- void midOrder()const;
- void postOrder()const;
- void levelOrder()const;
- void createTree(T flag );
- int size()const;
- int height()const;
- friend void printTree(const binaryTree<T>&t, T flag );
- void preOrderNRecur()const; //非递归实现
- void midOrderNRecur()const;
- void postOrderNRecur()const;
- void getCode(hfCode result[]); // 从huffman树生成huffman编码

## priorityQueue
- priorityQueue //二叉堆
- leftHeap //左堆

method
- bool isEmpty()const;
- void enQueue(const T&x);
- T deQueue();
- T getHead()const;
- void merge(leftHeap<T> * other); // 左堆的合并


# Reference
数据结构：思想与实现，上海交通大学出版社
