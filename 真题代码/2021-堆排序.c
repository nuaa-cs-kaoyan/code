/*
南航计算机考研：
	https://gitee.com/wansho/awesome-nuaa-cs-kaoyan
*/



#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>
#include <malloc.h>

int* adjust(int A[], int index, int value, int length) {
	if(A[index] == value){
		return A;
	} 
	A[index] = value;
	int parentIndex = index / 2;
	int leftChildIndex = index * 2;
    int rightChildIndex = leftChildIndex + 1;
    int minChildIndex;
    // 上溯
	while(index != 1 && A[parentIndex] > A[index]){
		A[0] = A[parentIndex];
		A[parentIndex] = A[index];
		A[index] = A[0];
		index = parentIndex;
		parentIndex = index / 2;
	}
    // 下溯
	while((leftChildIndex <= length && A[index] > A[leftChildIndex]) ||
          (leftChildIndex <= length && A[index] > A[rightChildIndex])){ // 存在子节点小于父节点
        if(rightChildIndex <= length && A[leftChildIndex] > A[rightChildIndex]){ // 取最小的子节点
        	minChildIndex = rightChildIndex;
        }  
		A[0] = A[minChildIndex];
		A[minChildIndex] = A[index];
		A[index] = A[0];
		index = minChildIndex;
		leftChildIndex = leftChildIndex * 2;
        rightChildIndex = leftChildIndex + 1;
	}
	return A;
}


int main(void){
	int A[11] = {0, 53, 87, 161, 108, 462, 503, 175, 170, 897, 512};
//	*A = adjust(A, 2, 1000, 10);
	*A = adjust(A, 3, 176, 10);	
	int i = 1;
	while(i < 11){
		printf("%d \n", A[i]);
		i += 1;
	}
	return 0;
}
