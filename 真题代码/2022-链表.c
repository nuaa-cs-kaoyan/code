#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>

/**
 * @brief 简单选择排序（封装成一个函数，简洁易读，方便老师给分）
 * 
 * @param L 
 */
void selectSort(struct ListNode* L){
  struct ListNode* p = L->next;
  struct ListNode* tmpNode;
  struct ListNode* max;
  struct ListNode* tmpMax;
  tmpMax = p;
  while(p != NULL){
    if(p->val > tmpMax->val){
      tmpMax = p;
    }
    p = p->next;
  }
  int tmp = tmpMax->val;
  tmpMax->val = L->next->val;
  L->next->val = tmp;
  max = L->next;
  while(max->next != NULL){
    tmpMax = max->next;
    p = tmpMax->next;
    while(p != NULL){
      if(p->val > tmpMax->val){
        tmpMax = p;
      }
      p = p->next;
    }
    tmp = tmpMax->val;
    tmpMax->val = max->next->val;
    max->next->val = tmp;
    tmpNode = max->next;
    max->next = tmpNode->next;
    tmpNode->next = L->next;
    L->next = tmpNode;
  }
  return;
}

/**
 * @brief 合并 A，B 排序
 * 
 * @param A 
 * @param B 
 * @return struct ListNode* 
 */
struct ListNode* mergeSort(struct ListNode* A, struct ListNode* B) {
	selectSort(B);
  struct ListNode* p = B->next;
  struct ListNode* tmpNode;
  struct ListNode* maxNode = A->next;
  struct ListNode* prev = A;
  while(p != NULL){
    tmpNode = p;
    p = p->next;
    while(tmpNode->val >= maxNode->val){
      prev = maxNode;
      maxNode = maxNode->next;
      if(maxNode == NULL){
        prev->next = tmpNode;
        return A;
      }
    }
    tmpNode->next = prev->next;
    prev->next = tmpNode;
    maxNode = tmpNode;
  }
	return A;
}

int main(void){
  struct ListNode* A = initLinkListASC();
	struct ListNode* B = initLinkList();
  A = mergeSort(A, B);
  printList(A);
  // selectSort(B);
  // printList(B);
	return 0;
}