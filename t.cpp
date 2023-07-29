#include<iostream>
#include <algorithm>
#include<vector>
#include<windows.h>
using namespace std;

void swap(int *a,int *b){
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

//选择排序    记录下表，遍历找极端数据，最后交换
void selection_sort(int *arr, int len){
    int i,j,min(0);
    for(i = 0;i < len - 1;i++){
        min = i;
        for(j = i + 1;j < len;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

//插入排序  扑克排序
void insertion_sort(int *arr,int len){
    int i,j,key(0);
    for(i = 1;i < len;i++){
        key = arr[i];j = i - 1;
        while((j >= 0) && (key < arr[j])){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 插入排序（二分优化）
void insertion_sortPro(int *arr,int len){
    int i,j,key(0);
    for(i = 1;i < len;i++){
        key = arr[i];
        int left = 0,right = i - 1,mid = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(key < arr[mid]){
                right = mid - 1;
            }else if(key > arr[mid]){
                left = mid + 1;
            }
        }
        for(j = i - 1;j >= left;j--){
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

//希尔排序，分组的插入排序，“缩小增量排序”，“熵减扑克排序”
void shell_sort(int *arr,int len){
    int i,j,inc,key;
    for(inc = len / 2; inc > 0; inc /= 2){
        for(i = inc; i < len; i++){
            key = arr[i];
            for(j = i - inc; (j > -1) && (key < arr[j]); j -= inc)
                arr[j + inc] = arr[j];
            arr[j + inc] = key;
        }
    }
} 

//归并排序
void Merge_sort(int *arr,int len){

} 

int main()
{
    int arr[] = {1,3,5,7,9,6,2,8,0,};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    //selection_sort(arr,len);
    //insertion_sort(arr,len);
    //shell_sort(arr,len);
    //Merge_sort(arr,len);
    insertion_sortPro(arr,len);
    print(arr,len);
    return 0;
}
