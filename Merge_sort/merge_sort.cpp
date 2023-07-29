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

//归并排序
void Merge(int *arr, int *tempArr, int left, int mid, int right){
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while(l_pos <= mid && r_pos <= right){     
        arr[l_pos] < arr[r_pos] ? tempArr[pos++] = arr[l_pos++] : tempArr[pos++] = arr[r_pos++];
    }
    while(l_pos <= mid) tempArr[pos++] = arr[l_pos++];
    while(r_pos <= right) tempArr[pos++] = arr[r_pos++];
    while(left <= right){
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int *arr,int *tempArr,int left,int right){
    //如果只有一个元素就不需要划分了
    if(left < right){
        int mid = left + (right - left) / 2;
        msort(arr, tempArr, left ,mid);
        msort(arr, tempArr, mid + 1, right);
        Merge(arr, tempArr, left, mid, right);
    }
} 

void Merge_sort(int *arr, int len){
    int *tempArr = (int*)malloc(len * sizeof(int));
    if(tempArr){
        msort(arr, tempArr, 0, len - 1);
        free(tempArr);
    }
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
