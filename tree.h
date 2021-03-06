/*
Created by @zch0423 on 2020/10/20.
Filename: tree.h
Content: definition of tree structure
*/



#ifndef CLIONPROJECT_TREE_H
#define CLIONPROJECT_TREE_H
#include<string>
using namespace std;

template <typename T>
class tree {
public:
    // flag表示没有值时的返回值
    virtual void clear()=0;
    virtual bool isEmpty()const=0;
    virtual T root(T flag)const = 0;
    virtual T parent(T x, T flag)const =0;
    virtual T child(T x, int i, T flag)const=0; // 第i个child
    virtual void remove(T x, int i)=0; // 删除x的第i颗子树
    virtual void traverse()const=0;
};

//二叉树
template <typename T>
class btree{
public:
    virtual void clear()=0;
    virtual T root(T flag)const = 0;
    virtual T lchild(T x, T flag)const=0; // left child
    virtual T rchild(T x, T flag)const=0; // right child
    virtual T parent(T x, T flag)const = 0;
    virtual void delLeft(T x)=0;
    virtual void delRight(T x)=0;
    virtual void preOrder()const=0;
    virtual void postOrder()const=0;
    virtual void midOrder()const=0;
    virtual void levelOrder()const=0;
};

// seqBtree
template <typename T>
class seqBtree:public btree<T>{
private:
public:
};

// linked Binary tree
template <typename T>
class binaryTree:public btree<T>{
    friend printTree(const binaryTree<T>& t, T flag );
private:
struct node{
    T data;
    node* lchild;
    node* rchild;
    node(const T&x, node* l= nullptr, node*r= nullptr){
        data = x;
        lchild = l;
        rchild = r;
    }
    node(){
        lchild = nullptr;
        rchild = nullptr;
    }
    ~node(){}
};
struct StNode{
    //为遍历的非递归实现创建
    node* n;
    int timesPop;
    StNode(node* N=nullptr):n(N),timesPop(0){}
};

    node* r;
    node* find(const T& x, node* t)const;
    void clear(node* &t);
    void preOrder(node*t)const;
    void midOrder(node*t)const;
    void postOrder(node*t)const;
    int size(node* t)const;
    int height(node* t)const;
public:
    binaryTree(){r= nullptr;}
    explicit binaryTree(const T& x){r=new node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty()const;
    T root(T flag)const;
    T lchild(const T& x, T flag)const;
    T rchild(const T& x, T flag)const;
    void delLeft(const &T x);
    void delRight(const &T x);
    void preOrder()const;
    void midOrder()const;
    void postOrder()const;
    void levelOrder()const;
    void createTree(T flag);
    T parent(const T&x, T flag)const{return flag;} // node中没有指向父节点的指针 
    int size()const;
    int height()const;
    // 遍历的非递归实现
    void preOrderNRecur()const;
    void midOrderNRecur()const;
    void postOrderNRecur()const;
};


// huffman Tree
template<typename T>
class hfTree{
    private:
        struct node{
            T data;
            int weight;
            int parent, left, right;
        };
        node* elem;
        int length;
    public:
        struct hfCode{ // 保存huffman编码的类型
            T data;
            string code;
        }; 
        hfTree(const T*x, const int*w, int size);
        void getCode(hfCode result[]);
        ~hfTree(){delete [] elem;}

}



#endif //CLIONPROJECT_TREE_H
