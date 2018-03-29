#include <iostream>
#include <stack>
using namespace std;
class Solution {
  public:
	Solution (int n = 0, int m = 0) {
		minS.push (100000000);
	}
	void push (int value) {
		s.push (value);
		if (value <= min())
			minS.push (value);
	}
	void pop() {
		if (s.top() == min())
			minS.pop();
		s.pop();
	}
	int top() {
		return s.top();
	}
	int min() {
		return minS.top();
	}
  private:
	stack<int> s;
	stack<int> minS;
};
int main() {
	Solution s1;
	for (int i = 0; i < 10; i++)
		s1.push (i);
	cout << s1.min() << endl;
	return 0;
}