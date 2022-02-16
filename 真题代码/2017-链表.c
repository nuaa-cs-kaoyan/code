#define ElemType int
typedef struct ListNode{
	ElemType data;
	struct ListNode* next;
}ListNode, *Linklist;

ListNode* function(Linklist A, Linklist B){
	
	if(A==NULL || A->next==NULL || B==NULL || B->next==NULL){
		return 0;
	}
	
	ListNode *p = A->next;
	ListNode *q = B->next;
	A->next = NULL;
	B->next = NULL;
	ListNode *temp = NULL;
	
	while(p!=NULL || q!=NULL){
		if(p==NULL || (q!=NULL && p->data <= q->data)){
			temp = q;
			q = q->next;
		}else if(q==NULL || (p!=NULL && p->data > q->data)){
			temp = p;
			p = p->next;
		}
		if(A->next != NULL && temp->data == A->next->data){
			// 相等的两个元素的插入位置一定相邻
			free(temp);
		}else{
			temp->next = A->next;
			A->next = temp;
		}
	}
	free(B);
	return A;
	
}