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
	ListNode* deleteDuplication (ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return pHead;
		ListNode* pNext = pHead->next;
		ListNode* tmp;
		if (pHead->val == pNext->val) {
			while (pNext != NULL && pHead->val == pNext->val) {
				tmp = pNext;
				pNext = pNext->next;
				delete tmp;
			}
			return deleteDuplication (pNext);
		}
		pHead->next = deleteDuplication (pNext);
		return pHead;
	}
};
int main() {
	return 0;
}