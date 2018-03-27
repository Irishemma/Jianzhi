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
	ListNode* b = head;
	for (int i = 2; i <= 5; i++) {
		ListNode* a = new ListNode (i);
		b->next = a;
		b = b->next;
	}
	b = head;
	while (b != NULL) {
		cout << b->val << ' ';
		b = b->next;
	}
	cout << endl;
	vector<int> a = Solution::printListFromTailToHead (head);
	b = head;
	while (head != NULL) {
		head = b->next;
		delete b;
		b = head;
	}
	return 0;
}