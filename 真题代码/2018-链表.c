/*
上面提供的答案有问题，大家可以看看，问题出在哪里。
这里有一个反例：4，3，-1，-3，5
经过两次头插后，4 就丢失了，pre 一开始是头节点时，且出现连续正数时需要特殊处理。

要考虑特殊情况的话，我原来的算法就太麻烦了，不适合考场，下面给出另一种直观的方法。
另外 12 年第六题，也是这个解法，也错了。

将链表从头节点处断开，重新构造链表，对剩下的链表进行遍历，正数节点取下来进行头插，负数节点取下来进行尾插。第一个负数节点的位置就是头插的次数 + 1。
*/

int foo(Linklist* L){
	
	//断链
	LNode* p = L->next;
	L->next = NULL;
	LNode* rear = L;
	LNode* tmp = NULL;
	int negative_count = 0;
	int count = 0;
	while(p!=NULL){
		//取下来
		count = count + 1;
		tmp = p;
		p = p->next;
		if(tmp->data >= 0){
			//头插
			tmp->next = L->next;
			L->next = tmp;
			negative_count = negative_count + 1;
			if(count == 1){
				// 第一个节点是正数的特殊情况处理
				rear = tmp;
			}
		}else{
			//尾插
			tmp->next = NULL;
			rear->next = tmp;
			rear = tmp;
		}
	}
	return negative_count + 1;
}