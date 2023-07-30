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

// 快速排序 (Hoare法，基本思想是定好 i和j 的位，再交换二者
//需要注意的点是，pivot应记录下标，而不是第一个位置的复制，因为最后i,j相遇处要和第一个位置交换)
void quick_sort(int* arr, int len)
{
    if (len < 2)return;
    int low = 0, high = len - 1;
    int pivot = low;
    while (low < high) {
        while (low < high && arr[high] >= arr[pivot]) high--;
        while (low < high && arr[low] <= arr[pivot]) low++;
        swap(&arr[high], &arr[low]);
    }
    swap(&arr[pivot], &arr[low]);
    quick_sort(arr, low);
    quick_sort(arr + low + 1, len - low - 1);
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
