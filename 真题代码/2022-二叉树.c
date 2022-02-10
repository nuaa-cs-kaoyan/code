#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

/**
 * @brief 层次遍历二叉树，并统计度为 2 的节点
 * 
 * @param head 
 * @return int 
 */
int count2DegreeNode(struct BiTreeNode* head){
  if(head == NULL){
    return 0;
  }
  int count = 0;
  int front = -1, rear = -1;
  int last = 0;
  struct BiTreeNode* queue[100] = {NULL};
  queue[++rear] = head;
  struct BiTreeNode* p = NULL;
  while(front < rear){
    p = queue[++front];
    if(p->left != NULL && p->right != NULL){
      count++;
    }
    if(p->left != NULL){
      queue[++rear] = p->left;
    }
    if(p->right != NULL){
      queue[++rear] = p->right;
    }
    if(front == last){
      last = rear;
    }
  }
  return count;
}

int main(){
  struct BiTreeNode* biTree = initBiTree();
  printf("%d", count2DegreeNode(biTree));
  return 0;
}