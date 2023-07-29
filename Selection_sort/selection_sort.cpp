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

int main()
{               
    int arr[] = {1  ,3,  5  ,7,  9  ,6,  3  ,2,  8  ,0,};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    selection_sort(arr,len);
    print(arr,len);
    return 0;
}
