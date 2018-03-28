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
	ListNode* FindKthToTail (ListNode* pListHead, unsigned int k) {
		ListNode* pa, *pb;
		pa = pb = pListHead;
		if (pa == NULL || k == 0)
			return NULL;
		unsigned int i = 0;
		for (; pa != NULL && i < k; i++)
			pa = pa->next;
		if (i != k)
			return NULL;
		while (pa != NULL) {
			pa = pa->next;
			pb = pb->next;
		}
		return pb;
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
	ListNode* a = s1.FindKthToTail (pListHead, 3);
	return 0;
}