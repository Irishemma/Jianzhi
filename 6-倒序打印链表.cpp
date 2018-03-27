#include <iostream>
#include <vector>
#include "string.h"
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode (int x) :
		val (x), next (NULL) {
	}
};

void AddtoTail (ListNode** pHead, int val) {
	ListNode* newNode =  new ListNode (val);
	if (*pHead == NULL)
		*pHead = newNode;
	else {
		ListNode* ptr = (*pHead);
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newNode;
	}
}
void RemoveNode (ListNode** pHead, int val) {
	if (*pHead == NULL || pHead == NULL)
		return;
	ListNode* tmp = NULL;
	if ((*pHead)->val == val) {
		tmp = *pHead;
		(*pHead) = (*pHead)->next;
		delete tmp;
		return;
	}
	while ((*pHead)->next != NULL) {
		if ((*pHead)->next->val == val) {
			tmp = (*pHead)->next;
			(*pHead)->next = (*pHead)->next->next;
			delete tmp;
		}
	}
}
class Solution {
  public:
	static vector<int> printListFromTailToHead (ListNode* head) {
		vector<int> array;
		stack<int> st;
		if (head == NULL)
			return array;
		ListNode* a = head;
		while (a != NULL) {
			st.push (a->val);
			a = a->next;
		}
		while (!st.empty()) {
			array.push_back (st.top());
			st.pop();
		}
		return array;
	}
};
int main() {
	ListNode* head = new ListNode (1);
	for (int i = 2; i <= 5; i++)
		AddtoTail (&head, i);
	ListNode* b = head;
	while (b != NULL) {
		cout << b->val << ' ';
		b = b->next;
	}
	cout << endl;
	vector<int> a = Solution::printListFromTailToHead (head);
	for (int i = 1; i <= 5; i++)
		RemoveNode (&head, i);
	return 0;
}