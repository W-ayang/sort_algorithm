#include<iostream>
#include <algorithm>
#include<vector>
#include<windows.h>
using namespace std;

void print(int *a,int len){
    for(int i = 0;i < len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
        int left(0),right(i - 1),mid(0);
        while(left <= right){
            mid = left + (right - left) / 2;
            if(key < arr[mid]){
                right = mid - 1;
            }else if(key > arr[mid]){
                left = mid + 1;
            }else{
                break;
            }
        }
        int idx = (key == arr[mid])? mid + 1 : left;
        for(j = i;j >= idx;j--){
            arr[j] = arr[j - 1];
        }
        arr[idx] = key;
    }
}

int main()
{               
    int arr[] = {1  ,3,  5  ,7,  9  ,6,  3  ,2,  8  ,0,};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    insertion_sort(arr,len);
    print(arr,len);
    return 0;
}
