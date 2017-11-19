#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void freeList(ListNode *);

class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode * Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry = 0, num = 0;
	ListNode *p1, *p2, *p3, *result = NULL;
	
	for(p1 = l1, p2 = l2; p1 != NULL || p2 != NULL || carry != 0;){
		num = 0;
		
		if(p1 != NULL){
			num += p1->val;
			p1 = p1->next;
		}
		
		if(p2 != NULL){
			num += p2->val;
			p2 = p2->next;
		}
		
		
		num += carry;
		carry = num / 10;
		num   = num % 10;

		if(result == NULL){
			p3 = result = new ListNode(num);
		}else{
			p3->next = new ListNode(num);
			p3 = p3->next;
		}
	}
	
	return result;	
}

int main(void){
	ListNode *l1, *l2, *l3;
	Solution s1;
	
	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	
	l3 = s1.addTwoNumbers(l1, l2);
	
	assert(l3->val == 7);
	assert(l3->next->val == 0);
	assert(l3->next->next->val == 8);
	
	freeList(l3);
	
	l2->next->next->next = new ListNode(4);
	
	l3 = s1.addTwoNumbers(l1, l2);
	
	assert(l3->val == 7);
	assert(l3->next->val == 0);
	assert(l3->next->next->val == 8);
	assert(l3->next->next->next->val == 4);
	
	freeList(l1);
	freeList(l2);
	freeList(l3);
	
	cout << "测试通过" << endl;
	
	l1 = new ListNode(5);
	l2 = new ListNode(5);
	l3 = s1.addTwoNumbers(l1, l2);
	
	assert(l3->val == 0);
	assert(l3->next->val == 1);
	
	freeList(l1);
	freeList(l2);
	freeList(l3);
	
	return 0;
}

void freeList(ListNode *l){
	ListNode * curr;
	while(l != NULL){
		cout << "free " << l->val << endl;
		curr = l;
		l = l->next;
		delete curr;
	}
}
