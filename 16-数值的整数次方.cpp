#include <iostream>
#include <stack>
#include <exception>
using namespace std;
class Solution {
  public:
	void push (int node) {
		stack1.push (node);
	}
	int pop() {
		int tmp;
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push (stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty())
			throw exception ("queue is empty");
		tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
  private:
	stack<int> stack1;
	stack<int> stack2;
};

int main() {
	Solution S1;
	for (int i = 0; i < 10; i++)
		S1.push (i);
	try {
		for (int i = 0; i < 11; i++)
			cout << S1.pop() << ' ';
	} catch (exception& e) {
		cerr << e.what() << endl;
	}
	return 0;
}