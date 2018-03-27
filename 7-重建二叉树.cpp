#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode (int x) : val (x), left (NULL), right (NULL) {}
};

class Solution {
  public:
	static TreeNode* reConstructBinaryTree (vector<int> pre, vector<int> vin) {
		int len = pre.size();
		if (len == 0)
			return NULL;
		if (len == 1)
			return (new TreeNode (pre[0]));
		//定位根节点在中序遍历中的位置
		int i = 0;
		for (; i < len; i++) {
			if (vin[i] == pre[0])
				break;
		}
		TreeNode* Up = new TreeNode (pre[0]);
		vector<int> sPre (i), sIn (i);
		if (i != 0) {
			for (int j = 0; j < i; j++) {
				sPre[j] = pre[j + 1];
				sIn[j] = vin[j];
			}
			Up->left = reConstructBinaryTree (sPre, sIn);
		}
		int lenR = len - i - 1;
		if (lenR != 0) {
			sPre.resize (lenR);
			sIn.resize (lenR);
			for (int j = 0; j < lenR; j++) {
				sPre[j] = pre[i + j + 1];
				sIn[j] = vin[i + j + 1];
			}
			Up->right = reConstructBinaryTree (sPre, sIn);
		}
		return Up;
	}

};
int main() {
	vector<int > pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int > vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = Solution::reConstructBinaryTree (pre, vin);
	return 0;
}