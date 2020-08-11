/*
���⣺
	�赥���� L ��Ԫ��ֵΪ��������д��Ч���������������е���λ�ڵ㣨���������У��ýڵ�֮ǰ�Ľڵ�Ԫ��ֵ֮�ͣ���ýڵ�֮��Ľڵ�Ԫ��ֵ֮�ͣ���ֵ��С������ɾ���ýڵ㡣��д���㷨˼�룬�ٸ������룬������ʱ�临�Ӷȡ�
*/

#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>
#include <malloc.h>

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
struct ListNode* findMedian(struct ListNode* head) {
	int leftSum = 0, rightSum = 0;
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

/*
O(n) �ķ�����
	��ˢ�������⣬��һ�����㷨���ۣ���������������⣬�����������ȱĳ��Ľ��ⷽ�����ǽ�����ת��˳���Ȼ����ʹ�ô�ǰ����ɨ��ķ��������Ǹ÷�����Ҫ�Ȼ�ȡ����ĳ��ȣ�Ȼ���ٽ�����ת��˳��������ʵ�ֵĸ��Ӷȣ�Ҫ���� O(n^2) �ķ��������Բ�����ʹ�ø÷�����
*/

int main(void){
	// Demo��1 2 3 4 5 6
	struct ListNode* lst = initLinkList();
	printList(lst);
	struct ListNode* median = findMedian(lst);
	printf("%d \t", median->val); // 5
	return 0;
}
