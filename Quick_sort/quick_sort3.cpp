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
	int mid = DigHoleSort(arr, low, high);
	quick_sort(arr, low, mid - 1);
	quick_sort(arr, mid + 1, high);
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



