/*
南航计算机考研：
	https://gitee.com/wansho/awesome-nuaa-cs-kaoyan
*/



#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>
#include <malloc.h>

int* adjust(int A[], int index, int value) {
	A[index] = value;
	while(1){
		int parentIndex = index / 2;
		if(A[parentIndex] > A[index]){
			A[0] = A[parentIndex];
			A[parentIndex] = A[index];
			A[index] = A[0];
			index = parentIndex;
		}else{
			break;
		}
		if(index == 1){
			break;
		}
	}
	return A;
}


int main(void){
	int A[11] = {0, 53, 87, 161, 108, 462, 503, 175, 170, 897, 512};
	*A = adjust(A, 10, 85);
	int i = 1;
	while(i < 11){
		printf("%d \n", A[i]);
		i += 1;
	}
	return 0;
}
