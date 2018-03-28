#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class Solution {
  public:
	Solution() {
		for (int i = 2; i < 40; i++)
			a[i] = a[i - 1] + a[i - 2];
	}
	int a[40] = { 0, 1 };

	int Fibonacci (int n) {
		return a[n];
	}
};

int main() {
	Solution S1;
	cout << S1.Fibonacci (4) << endl;
	return 0;
}