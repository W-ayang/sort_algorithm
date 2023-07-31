#include<iostream>
#include <algorithm>
#include<vector>
#include<windows.h>
using namespace std;

void swap(int *a, int *b){
    int tmp(0);
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int *a,int len){
    for(int i = 0;i < len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//维护堆的性质 (递归实现)
void heapify(int *arr, int i, int len){
    int dad = i;
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;
    if(lson < len && arr[dad] < arr[lson])
        dad = lson;
    if(rson < len && arr[dad] < arr[rson])
        dad = rson;
    if(dad != i){
        swap(&arr[dad], &arr[i]);
        heapify(arr, dad, len);
    }
}
//堆排序
void heap_sort(int *arr, int len){
    int i;
    for(i = len / 2 - 1; i >= 0; i--){//建堆的过程比较麻烦，需要迭代着建，所以是i--
        heapify(arr, i, len);
    }
    for(i = len - 1; i > 0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
    }
}

int main()
{               
    int arr[] = {1, 3, 5, 7, 9, 8, 3, 2, 6};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    heap_sort(arr, len);
    print(arr,len);
    return 0;
}