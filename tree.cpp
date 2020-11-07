/*
Created by @zch0423 on 2020/10/20.
Filename: tree.cpp
Content: implementation of tree especially binaryTree 
*/



#include "tree.h"
#include<iostream>
#include<string>

using namespace std;
// 队列 遍历用
template<typename T>
class linkQueue{
private:
    struct node{
        T data;
        node* next;
        node(const T& d, node* n=nullptr){
            data = d;
            next = n;
        }
        node(){
            next = nullptr;
        }
        ~node()= default;
    };
    node* front;
    node* rear;
public:
    linkQueue(){
        front=rear=nullptr;
    }
    ~linkQueue(){
        node* temp;
        while(!isEmpty()){
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty()const{
        return front==nullptr;
    }
    void enQueue(const T&d){
        if(rear==nullptr ){
            rear = new node(d);
            front = rear;
        } else{
            rear = rear->next = new node(d);
        }
    }
    T deQueue(){
        node * temp = front;
        T d = temp->data;
        front = front->next;
        if(front==nullptr ){
            rear = nullptr;
        }
        delete temp;
        return d;
    }
};

// 栈 遍历用
template<typename T>
class linkStack{
    private:
        struct node{
            T data;
            node* next;
            node(const T&d, node*n=nullptr ){
                data=d;
                next = n;
            }
            node(){
                next=nullptr;
            }
            ~node()=default;
        }
        node* topP;
    public:
        linkStack(){
            topP = nullptr;
        }
        ~linkStack(){
            node* temp;
            while(!isEmpty()){
                temp = topP;
                topP = topP->next;
                delete temp;
            }
        }
        bool isEmpty()const{
            return topP == nullptr;
        }
        T pop(){
            node* temp = topP;
            T result = temp->data;
            topP = topP->next;
            delete temp;
            return result;
        }
        void push(const T& d){
            topP = new node(d, topP);
        }
};


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
    delete t;
    t = nullptr;
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

//三种遍历的非递归实现
template<typename T>
void binaryTree<T>::preOrderNRecur()const{
    linkStack<node*> stack;
    node * temp;
    stack.push(r);
    while(!stack.isEmpty()){
        temp = stack.pop();
        cout<<temp->data<<' ';
        if(temp->left){
            stack.push(temp->left );
        }
        if(temp->right ){
            stack.push(temp->right );
        }
    }
}

template<typename T>
void binaryTree<T>::midOrderNRecur()const{
    linkStack<StNode*> stack;
    StNode temp(r);
    stack.push(r);
    while(!stack.isEmpty()){
        temp = stack.pop();
        if(++temp->timesPop==2){ // 第二次出栈
            cout<<temp->data<<' ';
            if(temp->right!=nullptr ){
                stack.push(temp->right );
            }
        }else{
            stack.push(temp);
            if(temp->left!=nullptr ){
                stack.push(temp->left );
            }
        }
    }
}

template<typename T>
void binaryTree<T>::postOrderNRecur()const{
    linkStack<StNode*> stack;
    StNode temp(r);
    stack.push(r);
    while(!stack.isEmpty()){
        temp = stack.pop();
        if(++temp->timesPop==3){
            cout<<temp->data<<' ';
            continue;
        }
        stack.push(temp);
        if(temp->timesPop==1){ // 第一次出栈
            if(temp->left!=nullptr ){
                stack.push(temp->left );
            }
        }else{ // 第二次
            if(temp->right!=nullptr ){
                stack.push(temp->right );
            }
        }
    }
}

template<typename T>
hfTree<T>::hfTree(const T*x, const int *w, int size ){
    const int MAX_INT = 32767;
    int min1, min2; //最小、次小树的权值
    int x, y; //最小、次小树下标
    
    // initialize
    length = size*2; //2n-1
    elem = new node[length];
    for(int i=size;i<length;++i){
        elem[i].weight = w[i-size];
        elem[i].data = v[i-size ];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }
    //merge
    for(i=size-1;i>0;--i){
        min1 = min2 = MAX_INT;
        x = y = 0;
        for(int j=i+1;j<length;++j){
            if(elem[j].parent==0){//没被合并过
                if(elem[j].weight<min1 ){
                    min2 = min1;
                    min1 = elem[j].weight;
                    x = y;
                    y = j;
                }else if(elem[j].weight<min2 ){
                    // 次小
                    min2 = elem[j].weight;
                    x = j;
                }
            }
        }
        elem[i].weight = min1+min2;
        elem[i].left = x;
        elem[i].right = y;
        elem[i].parent = 0;
        elem[x].parent = i;
        elem[y].parent = i;
    }
}

template<typename T>
void hfTree<T>::getCode(hfCode result[]){
    int size = length/2;
    int p,s; // p refers to parent node
    for(int i=size;i<length;++i){// 每个待编码符号
        result[i-size].data = elem[i].data;
        result[i-size].code = "";
        p = elem[i].parent;
        s = i;
        while(p){//从根出发，左边为0，右边为1
            if(elem[p].left==s){
                result[i-size].code = '0'+result[i-size].code;
            }else{
                result[i-size].code = '1'+result[i-size].code;
            }
            s = p;
            p = elem[p].parent;
        }
    }
}

