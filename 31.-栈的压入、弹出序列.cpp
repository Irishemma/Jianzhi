#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
	bool IsPopOrder (vector<int> pushV, vector<int> popV) {
		int len = pushV.size();
		int c1 = 0, c2 = 0;
		stack<int> s;
		for (; c1 < len; c1++) {
			s.push (pushV[c1]);
			while (!s.empty() && s.top() == popV[c2]) {
				c2++;
				s.pop();
			}
		}
		return s.empty();
	}
};
int main() {
	Solution s1;
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = { 4, 3, 5, 1, 2 };
	vector<int> v3 = { 4, 5, 3, 2, 1 };
	cout << s1.IsPopOrder (v1, v2) << endl;
	return 0;
}