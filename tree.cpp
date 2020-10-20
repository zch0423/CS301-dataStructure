/*
Created by @zch0423 on 2020/10/20.
Filename: tree.cpp
Content: implementation of tree especially binaryTree 
*/



#include "tree.h"
#include "queue.h"
#include "queue.cpp"
#include<iostream>

using namespace std;
template <typename T>
binaryTree<T>::~binaryTree(){
    clear();
}

template<typename T>
void binaryTree<T>::clear(binaryTree<T>::node*&t){
    if(t==nullptr){
        return;
    }
    clear(t->left );
    clear(t->right );
    delete root;
    root = nullptr;
}

template<typename T>
void binaryTree<T>::clear(){
    clear(r);
}

template<typename T>
bool binaryTree<T>::isEmpty()const{
    return r==nullptr;
}

template<typename T>
T binaryTree<T>::root(T flag )const{
    if(r==nullptr ){
        return flag;
    }
    return r->data;
}

template<typename T>
void binaryTree<T>::preOrder(binaryTree<T>::node*t)const{
    if(t==nullptr ){
        return;
    }
    cout<<t->data<<' ';
    preOrder(t->left);
    preOrder(t->right );
}

template<typename T>
void binaryTree<T>::preOrder()const{
    cout<<endl;
    cout<<"前序遍历:";
    preOrder(r);
}

template<typename T>
void binaryTree<T>::midOrder(binaryTree<T>::node *t)const{
    if(t==nullptr ){
        return;
    }
    midOrder(t->left );
    cout<<t->data<<' ';
    midOrder(t->right );
}

template<typename T>
void binaryTree<T>::midOrder()const{
    cout<<endl;
    cout<<"中序遍历:";
    midOrder(r);
}

template<typename T>
void binaryTree<T>::postOrder(binaryTree<T>::node*t)const{
    if(t==nullptr ){
        return;
    }
    postOrder(t->left );
    postOrder(t->right );
    cout<<t->data<<' ';
}

template<typename T>
void binaryTree<T>::postOrder()const{
    postOrder(r);
}

template<typename T>
void binaryTree<T>::levelOrder()const{
    linkQueue<T> q;
    node* temp;
    cout<<endl;
    cout<<"层次遍历:";
    q.enQueue(r);
    while(!q.isEmpty()){
        temp = q.deQueue();
        cout<<temp->data<<' ';
        if(temp->left ){
            q.enQueue(temp->left );
        }
        if(temp->right ){
            q.enQueue(temp->right );
        }
    }
}

template<typename T>
binaryTree<T>::node* binaryTree<T>::find(const T&x, binaryTree<T>::node*t)const{
   node * temp;
   if(t==nullptr ){
       return;
   }
   if(t->data==x)return t;
   if(temp=find(t->left, x)){
       return temp;
   }
   return find(t->right, x);
}


template<typename T>
T binaryTree<T>::lchild(const T&x, T flag )const{
    node* temp = find(x, r);
    if(temp==nullptr||temp->left==nullptr ){
        return flag;
    }
    return temp->left->data;
}

template<typename T>
T binaryTree<T>::rchild(const T&x, T flag )const{
    node* temp = find(x, r);
    if(temp==nullptr||temp->right==nullptr ){
        return flag;
    }
    return temp->right->data;
}

template<typename T>
void binaryTree<T>::delLeft(const &T x){
    node* temp = find(x, r);
    if(temp!=nullptr ){
        clear(temp->left);
    }
}

template<typename T>
void binaryTree<T>::delRight(const &T x){
    node* temp = find(x,r);
    if(temp!=nullptr ){
        clear(temp->right );
    }
}

template<typename T>
void binaryTree<T>::createTree(T flag ){
    // 根据输入创建树，用flag表示空节点
    linkQueue<node*> q;
    node* temp;
    T x, ldata, rdata;
    cout<<endl;
    cout<<"输入根结点:";
    cin>>x;
    r = new node(x);
    q.enQueue(r);
    while(!q.isEmpty()){
        temp = q.deQueue();
        cout<<"\n输入"<<temp->data<<" 的两个孩子("<<flag<<"表示空结点):";
        cin>>ldata>>rdata;
        if(ldata!=flag ){
            q.enQueue(temp->left = new node(ldata));
        }
        if(rdata!=flag ){
            q.enQueue(temp->right = new node(rdata));
        }
    }
    cout<<"completed!"<<endl;
}


template<typename T>
void printTree(const binaryTree<T>&t, T flag){
    linkQueue<T> q;
    q.enQueue(t.r->data );
    cout<<endl;
    while(!q.isEmpty()){
        T p,l,r;
        p = q.deQueue();
        l = t.lchild(p, flag );
        r = t.rchild(p, flag );
        cout<<p<<"  "<<l<<"  "<<r<<endl;
        if(l!=flag ){
            q.enQueue(l);
        }
        if(r!=flag ){
            q.enQueue(r);
        }
    }
}

template<typename T>
int binaryTree<T>::size(binaryTree<T>::node*t)const{
    if(t==nullptr )return 0;
    return 1+size(t->left )+size(t->right );
}

template<typename T>
int binaryTree<T>::size()const{
    return size(r);
}

template<typename T>
int binaryTree<T>::height(binaryTree<T>::node*t)const{
    if(t==nullptr ){
        return 0;
    }
    int lh, rh;
    lh = height(t->left );
    rh = height(t->right );
    return 1+(lh>rh?lh:rh);
}

template<typename T>
int binaryTree<T>::height()const{
    return height(r);
}

//TODO
//三种遍历的非递归实现

