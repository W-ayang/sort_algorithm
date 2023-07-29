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
/*
//二分优化希尔排序（目前还没成功实现，主要卡在当增量不是1是，二分时的下标出了问题，目前还没搞懂）
void shell_sortPro(int *arr,int len){
    int i,j,inc,key;
    for(inc = len >> 1; inc > 0; inc /= 2){
        for(i = inc; i < len; i++){
            key = arr[i];
            int left(i % inc),right(i - inc),mid(0);
            //二分查找
            while(left <= right){
                mid = left + (right - left) / 2;
                if(key < arr[mid]){
                    right = mid - inc;
                }else if(key > arr[mid]){
                    left = mid + inc;
                }else{
                    break;
                }
            }
            int idx = (key == arr[mid]) ? mid + inc : left;
            for(j = i; j >= idx; j -= inc){
                arr[j] = arr[j - inc];
            }
            arr[idx] = key;
            // for(j = i - inc; (j > -1) && (key < arr[j]); j -= inc)
            //     arr[j + inc] = arr[j];
            // arr[j + inc] = key;
        }
    }
}
*/
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


int main()
{               
    int arr[] = {1  ,3,  5  ,7,  9  ,6,  3  ,2,  8  ,0,};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    shell_sort(arr,len);
    print(arr,len);
    return 0;
}
