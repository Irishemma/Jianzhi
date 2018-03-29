#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode (int x) :
		val (x), left (NULL), right (NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == NULL || pRoot2 == NULL) return false;
		if (pRoot1->val != pRoot2->val)
			return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
		if (!(Contain(pRoot1->left, pRoot2->left) && Contain(pRoot1->right, pRoot2->right)))
			return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
		return true;
	}
	bool Contain(TreeNode* p1, TreeNode* p2) {
		if (p2 == NULL) return true;
		if (p1 == NULL || p1->val != p2->val) return false;
		return (Contain(p1->left, p2->left) && Contain(p1->right, p2->right));
	}
};
int main() {
	Solution s1;
	return 0;
}