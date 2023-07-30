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

// 快速排序 (前后指针法，左指针确保左边全是小于基准值的，右指针遍历寻找小于基准值的数，交换到前面去)
int partition(int *arr, int low, int high){
    int pivot = arr[high]; //划分的标准
    int i = low;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            swap(&arr[j], &arr[i++]);
        }
    }
    //因为小于pivot的元素已经被换到前面了，所以现在i指的元素一定不小于pivot
    swap(&arr[i], &arr[high]); 
    return i;
}

void qsort(int *arr, int low, int high){
    if(low < high){
        int mid = partition(arr, low, high);
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

void quick_sort(int *arr, int len){
    if(len < 2) return;
    qsort(arr, 0, len - 1);
}

int main()
{               
    int arr[] = {1, 3, 5, 7, 9, 8, 3, 2, 6};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    quick_sort(arr,len);
    print(arr,len);
    return 0;
}
