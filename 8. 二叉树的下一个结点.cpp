#include <iostream>
#include <vector>
using namespace std;
struct TreeLinkNode {
	int val;
	struct TreeLinkNode* left;
	struct TreeLinkNode* right;
	struct TreeLinkNode* next;
	TreeLinkNode (int x) : val (x), left (NULL), right (NULL), next (NULL) {
	}
};
class Solution {
  public:
	TreeLinkNode* GetNext (TreeLinkNode* pNode) {
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* c = pNode;
		TreeLinkNode* parent = NULL;
		if (c->right != NULL) {
			c = c->right;
			while (c->left != NULL)
				c = c->left;
			return c;
		} else {
			while (c->next != NULL) {
				parent = c->next;
				if (parent->left == c)
					return parent;
				else {
					c = parent;
					parent = parent->next;
				}
			}
		}
		return parent;
	}
};
int main() {
	return 0;
}