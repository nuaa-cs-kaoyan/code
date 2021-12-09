/*
�Ϻ���������У�
	https://gitee.com/wansho/awesome-nuaa-cs-kaoyan

2021 ����-����
	a ���������b ����ݼ����ϲ�����������ͬ�ڵ㱣��һ�����ϲ������������
*/

#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>
#include <malloc.h>

struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
	// �ȶ� b ���ã�ͷ�巨 
	struct ListNode* node = b->next;
	b->next = NULL;
	struct ListNode* tmp = NULL;
	struct ListNode* maxNode = a->next;
	struct ListNode* maxPrevNode = a;
	while(node != NULL){
		tmp = node;
		node = node->next;
		tmp->next = b->next;
		b->next = tmp; 
	} 
	// �� b ���� a
	node = b->next;
	while(node != NULL){
		tmp = node;
		node = node->next;
		while((maxNode != NULL) && (maxNode->val < tmp->val)){
			maxPrevNode = maxNode;
			maxNode = maxNode->next;
		}
		if(maxNode == NULL){
			maxPrevNode->next = tmp;
			break;
		}
		if(maxNode->val == tmp->val){
			continue;
		}
		tmp->next = maxPrevNode->next;
		maxPrevNode->next = tmp; 
	}
	return a;	
}


int main(void){
	struct ListNode* a = initLinkListASC();
	struct ListNode* b = initLinkListDESC();
	b = merge(a, b);
	printList(b);
	return 0;
}
