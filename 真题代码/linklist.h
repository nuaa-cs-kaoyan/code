#include <malloc.h>

/*
链表 - 数据结构
*/

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* initNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->val = val;
    return node;
}

// 初始化一个带头节点的链表
struct ListNode* initLinkList() {
	struct ListNode* head = initNode(0);
	
	struct ListNode* node1 = initNode(1);
	struct ListNode* node2 = initNode(2);
	struct ListNode* node3 = initNode(3);
	struct ListNode* node4 = initNode(4);
	struct ListNode* node5 = initNode(5);
	struct ListNode* node6 = initNode(6);
	
	node6->next = NULL;
	node5->next = node6;
	node4->next = node5;
	node3->next = node4;
	node2->next = node3;
	node1->next = node2;
	head->next = node1;
}

// 初始化一个带头节点的链表 递增 2，4，6，8，10 
struct ListNode* initLinkListASC() {
	struct ListNode* head = initNode(0);
	
	struct ListNode* node1 = initNode(2);
	struct ListNode* node2 = initNode(4);
	struct ListNode* node3 = initNode(6);
	struct ListNode* node4 = initNode(8);
	struct ListNode* node5 = initNode(10);
	
	node5->next = NULL;
	node4->next = node5;
	node3->next = node4;
	node2->next = node3;
	node1->next = node2;
	head->next = node1;
}

// 初始化一个带头节点的链表 递减 100，99，98，97，96
struct ListNode* initLinkListDESC() {
	struct ListNode* head = initNode(0);
	
	struct ListNode* node1 = initNode(100);
	struct ListNode* node2 = initNode(99);
	struct ListNode* node3 = initNode(98);
	struct ListNode* node4 = initNode(97);
	struct ListNode* node5 = initNode(96);
	
	node5->next = NULL;
	node4->next = node5;
	node3->next = node4;
	node2->next = node3;
	node1->next = node2;
	head->next = node1;
}



void printList(struct ListNode* head) {
	if (head == NULL)
		return;

	struct ListNode* p = head->next;
	while (p != NULL) {
		printf(" %d \n", p->val);
		p = p->next;
	}
}
