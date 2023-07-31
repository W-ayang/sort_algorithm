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

//维护堆的性质（循环实现）
//可以理解为，元素下沉，如果不是大顶锥了，可以将最上面的元素下沉到合适的位置
void heapify(int* a, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && a[son] < a[son + 1]) {
            son++;
        }
        if (a[dad] > a[son])//看看是否满足大顶椎的性质，满足就没必要继续比较了，直接return
            return;
        swap(&a[dad], &a[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}
void heap_sort(int* a, int n)
{
    int i;
    //建堆，第一次建堆比较麻烦
    for (i = (n - 2) / 2; i >= 0; i--)
        heapify(a, i, n - 1);
    //维护堆的性质，建完堆之后，维护就很容易了
    for (i = n - 1; i > 0; i--) {
        swap(&a[i], &a[0]);
        heapify(a, 0, i - 1);
    }
}

int main()
{               
    int arr[] = {1, 3, 5, 7, 9, 8, 3, 2, 6};
    int len = sizeof(arr)/sizeof(*arr);
    print(arr,len);
    heap_sort(arr, len);
    print(arr,len);
    return 0;
}