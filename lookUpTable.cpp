/*
    Filename   : lookUpTable.cpp
    Author     : @zch0423
    Date       : Nov 28, 2020
    Description:

*/

#include "lookUpTable.h"
#include <iostream>
using namespace std;

template<typename KEY, typename OTHER>
SET<KEY,OTHER> * BinarySearchTree<KEY,OTHER>::find(const KEY &x) const {
    return find(x, root);
}

template<typename KEY, typename OTHER>
SET<KEY,OTHER>* BinarySearchTree<KEY,OTHER>::find(const KEY &x,BinarySearchTree<KEY, OTHER>::BinaryNode *t) const {
   if(t==nullptr||x==t->data.key){
       return (SET<KEY,OTHER>*)t;
   }
   if(x<t->data.key){
       return find(x, t->left);
   }else{
       return find(x, t->right);
   }
}

template<typename KEY, typename OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY, OTHER> &x) {
    insert(x, root);
}

template<typename KEY, typename OTHER>
void BinarySearchTree<KEY,OTHER>::insert(const SET<KEY, OTHER> &x, BinarySearchTree<KEY, OTHER>::BinaryNode *&t) {
    if(t==nullptr){
        t = new BinaryNode(x);
    }else if(x.key<t->data.key){
        insert(x, t->left);
    }else{
        insert(x, t->right);
    }
}

template<typename KEY, typename OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x) {
    remove(x, root);
}

template<typename KEY, typename OTHER>
void BinarySearchTree<KEY,OTHER>::remove(const KEY &x, BinarySearchTree<KEY, OTHER>::BinaryNode *&t) {
    if(t== nullptr){
        return;
    }
    if(x<t->data.key){
        remove(x, t->left);
    } else if(x>t->data.key){
        remove(x, t->right);
    }else if(t->left!=nullptr && t->right!=nullptr){
        //两个孩子
        // 删除的位置用右子树最左的子孙替代，然后把该节点的右孩子移到该节点原来的位置
        BinaryNode* temp = t->right;
        while(temp->left!=nullptr){
            temp = temp->left;
        }
        t->data = temp->data;
        remove(temp->key, temp->right); //递归 再用自己的右子树左孩子替上
    }else{
        //只有一个孩子或者是叶节点
        BinaryNode* temp = t;
        if(t->left!=nullptr){
            t = t->left;
        }else{
            t = t->right;
        }
        delete temp;
    }
}

template<typename KEY, typename OTHER>
BinarySearchTree<KEY,OTHER>::BinarySearchTree(){
    root=nullptr;
}

template<typename KEY, typename OTHER>
BinarySearchTree<KEY,OTHER>::~BinarySearchTree() {
    makeEmpty(root);
}

template<typename KEY, typename OTHER>
void BinarySearchTree<KEY,OTHER>::makeEmpty(BinarySearchTree<KEY, OTHER>::BinaryNode *t) {
    if(t==nullptr){
        return;
    }
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

// AVL 树
template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::LL(AvlTree<KEY, OTHER>::AvlNode *&t) {
    // 左孩子的左子树上，单旋转，危机节点左孩子替代危机节点位置，危机节点变成左孩子的右孩子
    // 原左孩子的右孩子变成危机节点的左孩子
    AvlNode* tleft = t->left; // 旋转上去的左孩子
    t->left = tleft->right; //原左孩子的右孩子变成危机节点的左孩子
    tleft->right = t;
    t->height = max(height(t->left), height(t->right))+1;
    t = tleft;
    tleft->height = max(height(tleft->left), height((tleft->right)))+1;
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::RR(AvlTree<KEY, OTHER>::AvlNode *&t) {
    AvlNode* tright = t->right;
    t->right = tright->left;
    tright->left = t;
    t->height = max(height(t->right), height(t->left))+1;
    t = tright;
    tright->height = max(height(tright->left), height(tright->right));
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::LR(AvlTree<KEY, OTHER>::AvlNode *&t) {
    RR(t->left);
    LL(t);
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::RL(AvlTree<KEY, OTHER>::AvlNode *&t) {
    LL(t->right);
    RR(t);
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) {
    insert(x, root);
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, AvlTree<KEY, OTHER>::AvlNode *&t) {
    if(t==nullptr){
        t = new AvlNode(x);
    }else if(x<t->data.key){
        insert(x, t->left);
        if(height(t->left)-height(t->right)==2){
            if(x.key<t->left->data.key){
                LL(t);
            }else{
                LR(t);
            }
        }
    } else if (x>t->data.key){
        insert(x, t->right);
        if(height(t->right)-height(t->left)==2){
            if(t->right->data.key<x.key)RR(t);
            else RL(t);
        }
    }
    t->height = max(height(t->right), height(t->left))+1;
}

template<typename KEY, typename OTHER>
AvlTree<KEY, OTHER>::~AvlTree(){
    makeEmpty(root);
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::makeEmpty(AvlTree<KEY, OTHER>::AvlNode *t) {
    if(t== nullptr){
        return;
    }
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template<typename KEY, typename OTHER>
AvlTree<KEY, OTHER>::AvlTree(){
    root= nullptr;
}

template<typename KEY, typename OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY &x) {
    remove(x, root);
}

template<typename KEY, typename OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY &x, AvlTree<KEY, OTHER>::AvlNode *&t) {
    // 返回true表示高度不变不用检查平衡
    if(t== nullptr){
        return true;
    }
    if(t->data.key==x){
        if(t->left==nullptr||t->right==nullptr){
            // 叶子节点或者只有一个孩子
            AvlNode* temp = t;
            if(t->left!=nullptr){
                t = t->left;
            }else{
                t = t->right;
            }
            delete temp;
            return false;
        }else{
            // 两个孩子的情况
            AvlNode* temp = t->right;
            // 找右子树的最左节点
            while(temp->left!=nullptr){
                temp = temp->left;
            }
            t->data =temp->data;
            if(remove(temp->data.key, t->right))return true;// 右子树没变矮
            return adjust(t, 1); // 1 表示右子树上删除使右子树变矮
        }
    }else if(t->data.key>x){
        if(remove(x, t->left))return true; // 左子树删除没有变矮
        return adjust(t, 0);
    }else if(t->data.key<x){
        if(remove(x, t->right))return true; // 右子树删除没有变矮
        return adjust(t, 1);
    }
}

template<typename KEY, typename OTHER>
bool AvlTree<KEY, OTHER>::adjust(AvlTree<KEY, OTHER>::AvlNode *&t, int subTree) {
    if(subTree){ // 右子树删除变矮
        if(height(t->left)-height(t->right)==1){
            // 删除后左比右高一，t的高度不变仍为左子树的高度
            return true;
        }
        if(height(t->left)==height(t->right)){
            // 删除后左和右相等，原来右比左高，所以t高度减少1
            --t->height;
            return false;
        }
        // 原本左子树减右子树=1，删除后变成2了
        if(height(t->left->right)>height(t->left->left)){
            // 相当于在左子树右子树插入
            LR(t);
            return false;
        }
        LL(t); // 左子树左子树高度大于左子树右子树，相当于LL
        // 原本应该左子树高于右子树，相等说明调整后高度变化了
        return height(t->right) != height(t->left);
    }else{
        // 左子树删除变矮
        if(height(t->left)-height(t->right)==-1){
            return true;
        }
        if(height(t->left)==height(t->right)){
            --t->height;
            return false;
        }
        if(height(t->left->right)<height(t->left->left)){
            RL(t);
            return false;
        }
        RR(t);
        // 原本应该右子树高于左子树，相等说明调整后高度变化了
        return height(t->right) != height(t->left);
    }
}

template<typename KEY, typename OTHER>
SET<KEY,OTHER>* AvlTree<KEY,OTHER>::find(const KEY &x) const {
    AvlNode* temp=root;
    while(temp!=nullptr && temp->data.key!=x){
        if(temp->data.key>x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
        if(temp==nullptr)return nullptr;
        return (SET<KEY,OTHER>*) temp;
    }
}
