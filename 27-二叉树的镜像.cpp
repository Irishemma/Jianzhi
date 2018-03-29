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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		TreeNode * t = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = t;
		return;
	}
};
int main() {
	Solution s1;
	return 0;
}