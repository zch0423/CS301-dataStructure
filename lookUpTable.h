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
    for(int i=size;x!=data[i].key;--i);
    return i;
}

// 有序表查询 假设递增
template<typename KEY, typename OTHER>
int orderSeqSearch(SET<KEY, OTHER> data[], int size, const KEY&x){
    data[0].key = x;
    for(int i=size;x<data[i].key;--i);
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
int insertSearch(SET<KEY, OTHER> datap[], int size, const KEY&x){
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


#endif // HEADlookUpTable
