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
void hah(){
    
}
//归并排序
void msort(int *arr, int *tmp, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    int left1 = left, right1 = mid;
    int left2 = mid + 1, right2 = right;
    msort(arr, tmp, left1, right1);
    msort(arr, tmp, left2, right2);
    //已经把原序列二分彻底，下面就开始合并。
    while(left1 <= right1 &&left2 <= right2){
        arr[left1] < arr[left2] ? tmp[left++] = arr[left1++] : tmp[left++] = arr[left2++]; 
    }
    while(left1 <= right1) tmp[left++] = arr[left1++];
    while(left2 <= right2) tmp[left++] = arr[left2++]; 
    memcpy(arr, tmp, sizeof(int) * (right + 1));//这里right + 1，是因为right是下标，元素个数实际上是right + 1.
}

void Merge_sort(int *arr, int len){
    if(len < 2) return;
    int *tmp = (int*)malloc(sizeof(int) * len);
    msort(arr, tmp, 0, len - 1);
    free(tmp);
}

int main()
{               
    int arr[] = {1  ,3,  5  ,7,  9  ,6,  3  ,2,  8  ,0,};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    Merge_sort(arr,len);
    print(arr,len);
    return 0;
}
