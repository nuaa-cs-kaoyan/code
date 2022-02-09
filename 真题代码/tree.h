#include <stdlib.h>

/*
孩子兄弟树 - 数据结构
*/

struct TreeNode {
  int val;
	struct TreeNode* firstChild;
	struct TreeNode* nextSibling;
};

struct TreeNode* initNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
    return node;
}

struct TreeNode* initTree() {
	struct TreeNode* a = initNode(1);
	struct TreeNode* a1 = initNode(2);
	struct TreeNode* a2 = initNode(3);
	struct TreeNode* a3 = initNode(4);
	struct TreeNode* a11 = initNode(5);
	struct TreeNode* a12 = initNode(6);
	struct TreeNode* a31 = initNode(7);
	struct TreeNode* a32 = initNode(8);
	struct TreeNode* a33 = initNode(9);
	struct TreeNode* a111 = initNode(10);
	struct TreeNode* a321 = initNode(11);

	a->firstChild = a1;
	a->nextSibling = NULL;
	a1->firstChild = a11;
	a1->nextSibling = a2;
	a2->firstChild = NULL;
	a2->nextSibling = a3;
	a3->firstChild = a31;
	a3->nextSibling = NULL;
	a11->firstChild = a111;
	a11->nextSibling = a12;
	a12->firstChild = NULL;
	a12->nextSibling = NULL;
	a111->firstChild = NULL;
	a111->nextSibling = NULL;
	a31->firstChild = NULL;
	a31->nextSibling = a32;
	a32->firstChild = a321;
	a32->nextSibling = a33;
	a321->firstChild = NULL;
	a321->nextSibling = NULL;
	a33->firstChild = NULL;
	a33->nextSibling = NULL;

	return a;
}


