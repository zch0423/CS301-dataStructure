/*
    Filename   : lookUpTable.h
    Author     : @zch0423
    Date       : Nov 28, 2020
    Description:

*/

#ifndef HEADlookUpTable
#define HEADlookUpTable
template<typename KEY, typename OTHER>
struct SET{
    KEY key;
    OTHER other;
};

// 无序表查询
template<typename KEY, typename OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY&x){
    data[0].key = x;
    int i;
    for(i=size;x!=data[i].key;--i);
    return i;
}

// 有序表查询 假设递增
template<typename KEY, typename OTHER>
int orderSeqSearch(SET<KEY, OTHER> data[], int size, const KEY&x){
    data[0].key = x;
    int i;
    for(i=size;x<data[i].key;--i);
    if(x==data[i].key)return i;
    else return 0;
}


template<typename KEY, typename OTHER>
int binarySearch(SET<KEY, OTHER>data [], int size, const KEY&x){
    // 二分查找
    int low=1, high=size;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(x==data[mid].key)return mid;
        if(x<data[mid].key)high = mid-1;
        else low = mid+1;
    }
    return 0;
}


template<typename KEY, typename OTHER>
int insertSearch(SET<KEY, OTHER> data[], int size, const KEY&x){
    // 插值查找
    int low = 1, high=size;
    int next;
    while(low<=high){
        next = low+(x-data[low].key)/(data[high].key-data[low].key)*(high-low-1);
        if(data[next].key==x){
            return next;
        }
        if(data[next].key<x)high = next-1;
        else low = next+1;
    }
    return 0;
}

// 动态查找表
template<typename KEY, typename OTHER>
class dynamicSearchTable {
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable() = default;
};

// 二叉查找树
template<typename KEY, typename OTHER>
class BinarySearchTree:public dynamicSearchTable<KEY, OTHER>{
private:
    struct BinaryNode{
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const SET<KEY, OTHER>&d, BinaryNode*l= nullptr, BinaryNode*r= nullptr):data(d),left(l),right(r){}
    };
    BinaryNode*root;

    void insert(const SET<KEY, OTHER>&x, BinaryNode* &t);
    void remove(const KEY&x, BinaryNode* &t);
    SET<KEY,OTHER> * find(const KEY&x, BinaryNode*t)const;
    void makeEmpty(BinaryNode*t);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    SET<KEY,OTHER>*find(const KEY&x)const;
    void insert(const SET<KEY,OTHER>&x);
    void remove(const KEY&x);

};

// AVL树
// 左右子树高度相差不超过1
template<typename KEY, typename OTHER>
class AvlTree:public dynamicSearchTable<KEY,OTHER>{
private:
    struct AvlNode{
        SET<KEY,OTHER>data;
        AvlNode* left;
        AvlNode* right;
        int height;
        AvlNode(const SET<KEY,OTHER> & element, AvlNode*l= nullptr, AvlNode*r= nullptr, int h=1):data(element),left(l),right(r),height(h){}
    };
    AvlNode* root;

    void insert(const SET<KEY,OTHER>&x, AvlNode*&t);
    bool remove(const KEY&x, AvlNode*&t);
    void makeEmpty(AvlNode*t);
    int height(AvlNode* t)const {return t== nullptr?0:t->height;}
    void LL(AvlNode*&t);
    void LR(AvlNode*&t);
    void RL(AvlNode*&t);
    void RR(AvlNode*&t);
    int max(int a, int b){return (a>b)?a:b;}
    bool adjust(AvlNode*&t, int subTree);

public:
    AvlTree();
    ~AvlTree();
    SET<KEY,OTHER>* find(const KEY&x)const;
    void insert(const SET<KEY,OTHER>&x);
    void remove(const KEY&x);
};


#endif // HEADlookUpTable
