#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

void* My_memcpy(void* dest,const void* src, size_t num)
{
	assert(dest && src); //断言一下，就像倒水一样，看看有没有存水空间
	void* ret = dest; //把目标首地址记下来，最后return的就是它
	while (num--)
	{	//这个操作就是一个一个复制
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret; //返回目标首地址
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	My_memcpy(arr1 + 2, arr1, sizeof(int) * 3);
	for(int i = 0; i < (sizeof(arr1) / sizeof(*arr1)); i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
	return 0;
}


