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

//三数取中法进行优化   (理想情况下我们每回选的key位置值都近似为数组中位数，这样每回递归都为二分。
//但当数据出现极端情况时，会使我们的快速排序效率大打折扣)
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[mid] > a[left]){
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}else{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

// 快速排序 (Hoare法，基本思想是定好 i和j 的位，再交换二者
//需要注意的点是，pivot应记录下标，而不是第一个位置的复制，因为最后i,j相遇处要和第一个位置交换)
void quick_sort(int* arr, int len){
    if (len < 2)return;
    int low = 0, high = len - 1;
    int mid = GetMidIndex(arr, low, high);
    swap(&arr[mid], &arr[low]);
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
