#include<iostream>
#include <algorithm>
#include<vector>
#include<windows.h>
#include<stack>
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

void quick_sortNonR(int *arr, int len){
    stack<int>s;
    int left(0), right(len - 1);
    s.push(right);//入栈，先右后左，取出来的时候就是先左后右了
    s.push(left);

    while(!s.empty()){ //说白了就是使用栈来管理递归层数
        left = s.top();//先获取边界
        s.pop();
        right = s.top();
        s.pop();
        int mid = DigHoleSort(arr, left, right);//获取基准值的位置，然后分界
        // if (right - left <= 16) {//子序列达到阈值
		// 	shell_sort(arr + left, right - left + 1);//进行希尔排序
		// }else{
        //     s.push(right);
        //     s.push(mid + 1);

        //     s.push(mid - 1);
        //     s.push(left);
        // }

        //如果一直进行快排的话，不要忘记加上判断，左边界是否小于右边界
        if(mid + 1 < right){
            s.push(right);
            s.push(mid + 1);
        }
        if(left < mid - 1){
            s.push(mid - 1);
            s.push(left);
        }
    }
}

int main()
{               
    int arr[] = {1, 3, 5, 7, 9, 8, 3, 2, 6};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    quick_sortNonR(arr, len);
    print(arr,len);
    return 0;
}



