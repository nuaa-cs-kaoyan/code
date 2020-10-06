/*
�Ϻ���������У�
	https://gitee.com/wansho/awesome-nuaa-cs-kaoyan
*/

#include <stdio.h>
#include "tree.h"
#include <malloc.h>

/*
	�����ֵ��� - ��α���
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
	��˫�׽ڵ�
	�㷨˼�룺�ö��к����ֵ������в�α���������ÿһ�������ӵ�˫�׽ڵ㣬�ڽ��亢���ֵ���ӵ�ʱ�򣬽���ӽڵ��� p ����ƥ�䣬ƥ��ɹ��򷵻ظ�˫�׽ڵ㡣
	��˵һ�䣺���Ҹտ��������Ŀ��ʱ������û��˼·�ģ���ֻ���뵽��������͵���Ŀ����ǰ����������������֮ǰ������������Ŀ�ο���������� 12 ����д�Ĵ��룬�� 17 ���һ���ͼ���Ҳ��뵽���ⷽ������ʵ�ܼ򵥣����Ļ��ǲ�α�����ע�⣺�ڿ�����û��˼·��ʱ�򣬽����һ�һ������������һ��������һ�������ֵ��������޸�˵����"��ȱ��ʱ��ֱ��,������ʱ����΢"����������������ɴ��룬���п������ɻ�ͼ����ͼ��Ѱ����е�һ������Ҫ��;����
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
			// �������еĺ����ֵܽڵ㣬���� p ����ƥ��
			tmpParent = node; // Ǳ�ڵ� parent �ڵ�
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
	// Demo�������ֵ���Demo.png
	struct TreeNode* tree = initTree();
	levelOrder(tree);
	return 0;
}
