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
#include <queue>
class Solution {
  public:
	vector<int> PrintFromTopToBottom (TreeNode* root) {
		vector<int> out;
		if (root == NULL)
			return out;
		TreeNode* c = root;
		queue<TreeNode*> q;
		q.push (c);
		while (!q.empty()) {
			c = q.front();
			out.push_back (c->val);
			q.pop();
			if (c->left != NULL)    q.push (c->left);
			if (c->right != NULL)    q.push (c->right);
		}
		return out;
	}
};
int main() {
	Solution s1;
	return 0;
}