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
	ListNode* ReverseList (ListNode* pHead) {
		ListNode* PM, *PR, *PL;
		PM = PR = pHead;
		PL = NULL;
		while (PR != NULL) {
			PR = PR->next;
			PM->next = PL;
			PL = PM;
			PM = PR;
		}
		return PL;
	}
};
int main() {
	Solution s1;
	ListNode* pListHead = new ListNode (0);
	ListNode* pCur = pListHead;
	for (int i = 1; i < 10; i++) {
		pCur->next = new ListNode (i);
		pCur = pCur->next;
	}
	ListNode* a = s1.ReverseList (pListHead);
	return 0;
}