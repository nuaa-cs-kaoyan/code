/*
问题：
	设单链表 L 的元素值为整数。编写高效函数，查找链表中的中位节点（即在链表中，该节点之前的节点元素值之和，与该节点之后的节点元素值之和，差值最小），并删除该节点。先写出算法思想，再给出代码，并分析时间复杂度。
*/

#include <stdio.h>
#include "linklist.h"
#include <limits.h>
#include <math.h>
#include <malloc.h>

/*
O(n^2) 的方案 (最朴素的方法，每个人都应该会的方法，在考场上能够快速写出来的方法)
	算法思想：
		不妨设链表至少有三个节点；
		用指针 p 遍历链表的第二个节点到倒数第二个节点，用指针 q 遍历 p 左边的链表求和得到 leftSum，用指针 r 遍历 p 右边链表求和得到 rightSum;
		求得两边差值，用 minDiff 存储最小差值用于比较，用 minDiff_p 指向最小差值节点；
		返回 minDiff_p;
	
	问：代码没有考虑边界情况，链表节点数 <= 2 怎么办？
	答：考场不需要考虑代码的健壮性，能完成基本功能即可，时间允许的话，再完善。

	问：中位数不止一个咋办，例如：1 2 2 1 ?
	答：就返回第一个呗，考场上不用考虑那么多，完成比完美更重要。重点是算法思想。算法思想没错，然后代码框架没错，那么这个答案就说得过去，如果算法思想错了（不够清晰，老师乍一看，看不懂），或者代码为了盲目追求健壮性，写了很多边界检测代码，使得代码的不够简洁，老师看起来吃力，那么就捡了芝麻，丢了西瓜，得不偿失了。
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
		// 复位
		q = head->next;
		r = p->next;
		leftSum = 0;
		rightSum = 0;
	}
	return median;
}

/*
O(n) 的方法：
	我刷过几道题，有一定的算法积累，当我碰到这个问题，我脑子里最先蹦出的解题方法，是将链表转成顺序表，然后再使用从前往后扫描的方法。但是该方法需要先获取链表的长度，然后再将链表转成顺序表，其代码实现的复杂度，要高于 O(n^2) 的方法，所以不建议使用该方法。
*/

int main(void){
	// Demo：1 2 3 4 5 6
	struct ListNode* lst = initLinkList();
	printList(lst);
	struct ListNode* median = findMedian(lst);
	printf("%d \t", median->val); // 5
	return 0;
}
