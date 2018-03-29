#include <iostream>
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode*p1 = pHead1, *p2 = pHead2;
		ListNode* ptr = new ListNode(0);
		ListNode* pH = ptr;
		while (!p1 == NULL && !p2 == NULL) {
			if (p1->val > p2->val) {
				ptr->next = p2;
				p2 = p2->next;
			}
			else {
				ptr->next = p1;
				p1 = p1->next;
			}
			ptr = ptr->next;
		}
		if (!p1 == NULL)
			ptr->next = p1;
		if (!p2 == NULL)
			ptr->next = p2;

		ptr = pH->next;
		delete pH;
		return ptr;
	}
};
int main() {
	Solution s1;
	ListNode* pListHead = new ListNode (0);
	ListNode *p2=NULL;
	ListNode* pCur = pListHead;
	for (int i = 1; i < 10; i+=2) {
		pCur->next = new ListNode (i);
		pCur = pCur->next;
	}
	ListNode* a = s1.Merge(pListHead, p2);
	return 0;
}