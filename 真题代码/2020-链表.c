/*
�赥���� L ��Ԫ��ֵΪ��������д��Ч���������������е���λ�ڵ㣨���������У��ýڵ�֮ǰ�Ľڵ�Ԫ��ֵ֮�ͣ���ýڵ�֮��Ľڵ�Ԫ��ֵ֮�ͣ���ֵ��С������ɾ���ýڵ㡣��д���㷨˼�룬�ٸ������룬������ʱ�临�Ӷȡ�
*/

#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>

/*
O(n) �ķ���
	ǰ�ԣ�
		��ˢ�������⣬��һ�����㷨���ۣ���������������⣬�����������ȱĳ��Ľ��ⷽ�����ǽ�����ת��˳���Ȼ���˳��������������ɨ�裬�ƽ����Ľڵ�
	�㷨˼�룺
		������ת��˳���Ȼ���˳��������������ɨ�裬�ƽ����Ľڵ㡣
*/ 
void goodJob(struct ListNode* head) {
	// ��ȡ������
	int length = 0;
	struct ListNode* p = head->next;
	while (p != NULL) {
		length += 1;
		p = p->next;
	}
	struct ListNode* nodes[] = (struct ListNode*)malloc(sizeof(struct ListNode) * length);
	int front = 0, rear = length - 1;

}

/*
O(n^2) �ķ��� (�����صķ�����ÿ���˶�Ӧ�û�ķ������ڿ������ܹ�����д�����ķ���)
	�㷨˼�룺
		���������������������ڵ㣻
		��ָ�� p ��������ĵڶ����ڵ㵽�����ڶ����ڵ㣬��ָ�� q ���� p ��ߵ�������͵õ� leftSum����ָ�� r ���� p �ұ�������͵õ� rightSum;
		������߲�ֵ���� minDiff �洢��С��ֵ���ڱȽϣ��� minDiff_p ָ����С��ֵ�ڵ㣻
		���� minDiff_p;
	
	�ʣ�����û�п��Ǳ߽����������ڵ��� <= 2 ��ô�죿
	�𣺿�������Ҫ���Ǵ���Ľ�׳�ԣ�����ɻ������ܼ��ɣ�ʱ������Ļ��������ơ�

	�ʣ���λ����ֹһ��զ�죬���磺1 2 2 1 ?
	�𣺾ͷ��ص�һ���£������ϲ��ÿ�����ô�࣬��ɱ���������Ҫ���ص����㷨˼�롣�㷨˼��û��Ȼ�������û����ô����𰸾�˵�ù�ȥ������㷨˼����ˣ�������������ʦէһ�����������������ߴ���Ϊ��äĿ׷��׳�ԣ�д�˺ܶ�߽�����룬ʹ�ô���Ĳ�����࣬��ʦ��������������ô�ͼ���֥�飬�������ϣ��ò���ʧ�ˡ�
*/
struct ListNode* badJob(struct ListNode* head) {
	int leftSum = 0;
	int rightSum = 0;
	int minDiff = INT_MAX;
	struct ListNode* q = head->next;
	struct ListNode* p = q->next;
	struct ListNode* r = p->next;
	struct ListNode* median = p;
	while (p->next != NULL) {
		while (q != p) {
			leftSum += q->val;
			q = q->next;
		}
		while (r != NULL) {
			rightSum += r->val;
			r = r->next;
		}
		int diff = abs(rightSum - leftSum);
		if (diff < minDiff) {
			minDiff = diff;
			median = p;
		}
		p = p->next;
		// ��λ
		q = head->next;
		r = p->next;
		leftSum = 0;
		rightSum = 0;
	}
	return median;
}

int main(void){
	// Demo��8 4 2 3 6 5
	struct ListNode* lst = initLinkList();
	printList(lst);
	struct ListNode* median = badJob(lst);
	printf("%d", median->val); // 2
	return 0;
}
