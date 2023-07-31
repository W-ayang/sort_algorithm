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

//希尔排序
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

//挖坑填数
int DigHoleSort(int* arr, int low, int high){
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) high--;//在右边找最小值
        arr[low] = arr[high];//填坑
        while (low < high && arr[low] <= pivot) low++;//在左边找最小值
        arr[high] = arr[low];//填坑
    }
    arr[low] = pivot;
    return low;
}

void quick_sort(int* arr, int low, int high)
{
	if (low >= high) return;
    if((high - low) > 20){ //小区间优化法 当数据量比较大的时候可以通过调整参数(20),来减小递归次数，提高性能
        int mid = DigHoleSort(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }else{
        shell_sort(arr, high + 1); //数量比较少的时候使用希尔排序
    }
	
}


int main()
{               
    int arr[] = {1, 3, 5, 7, 9, 8, 3, 2, 6};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    quick_sort(arr, 0, len - 1);
    print(arr,len);
    return 0;
}



