/*
南航计算机考研：
	https://gitee.com/wansho/awesome-nuaa-cs-kaoyan
*/

#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

/*
	孩子兄弟树 - 层次遍历
*/
void levelOrder(struct TreeNode* head) {
	if (head == NULL) {
		return;
	}
	struct TreeNode* queue[20] = { NULL };
	int rear = -1, front = -1, last = 0;
	queue[++rear] = head;
	struct TreeNode* node = NULL;
	while (front < rear) {
		node = queue[++front];
		printf(" %d \n", node->val);
		if (node->firstChild != NULL) {
			node = node->firstChild;
			queue[++rear] = node;
			while (node->nextSibling != NULL) {
				node = node->nextSibling;
				queue[++rear] = node;
			}
		}
		if (front == last) {
			last = rear;
		}
	}
}

/*
	求双亲节点
	算法思想：用队列孩子兄弟树进行层次遍历，对于每一个有左孩子的双亲节点，在将其孩子兄弟入队的时候，将入队节点与 p 进行匹配，匹配成功则返回该双亲节点。
	多说一句：当我刚看到这个题目的时候，我是没有思路的，我只是想到了这个类型的题目，以前考过，所以找来了之前考过的两个题目参考。后来结合 12 年我写的代码，和 17 年我画的图，我才想到解题方法，其实很简单，核心还是层次遍历。注意：在考场上没有思路的时候，建议大家画一个二叉树，画一个链表，画一个孩子兄弟树。华罗庚说过："数缺形时少直观,形少数时难入微"，这里的数可以理解成代码，而行可以理解成画图，画图是寻找灵感的一个很重要的途径。
*/
struct TreeNode* findParent(struct TreeNode* head, struct TreeNode* p) {
	if (head == NULL) {
		return NULL;
	}
	struct TreeNode* queue[20] = { NULL };
	int rear = -1, front = -1, last = 0;
	queue[++rear] = head;
	struct TreeNode* node = NULL;
	struct TreeNode* tmpParent = NULL;
	while (front < rear) {
		node = queue[++front];
		printf(" %d \n", node->val);
		if (node->firstChild != NULL) { 
			// 遍历所有的孩子兄弟节点，并和 p 进行匹配
			tmpParent = node; // 潜在的 parent 节点
			node = node->firstChild;
			if (node == p) {
				return tmpParent;
			}
			queue[++rear] = node;
			while (node->nextSibling != NULL) {
				node = node->nextSibling;
				if (node == p) {
					return tmpParent;
				}
				queue[++rear] = node;
			}
		}
		if (front == last) {
			last = rear;
		}
	}
}

int main(void){
	// Demo：孩子兄弟树Demo.png
	struct TreeNode* tree = initTree();
	levelOrder(tree);
	return 0;
}
