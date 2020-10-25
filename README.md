# content

Cpp implementation codes of data structures in course CS031

# implementation

## Linear list
- seqList 顺序表
- sLinkList 单链表
- dLinkList 双链表
- cLinkList 循环链表

**methods**
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
- seqBinaryTree
- binaryTree

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

# Reference
数据结构：思想与实现，上海交通大学出版社
