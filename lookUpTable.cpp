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

