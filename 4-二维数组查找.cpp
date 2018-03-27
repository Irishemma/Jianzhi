#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	static bool Find (int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		int row = 0, col = cols - 1;
		while (row < rows && col >= 0) {
			if (array[row][col] > target)
				col--;
			else if (array[row][col] < target)
				row++;
			else
				return true;
		}
		return false;
	}
};

int main() {
	vector< vector<int > > a = { { 3, 4, 5 }, { 6, 7, 8 }, { 9, 10, 11 } };
	int d = 2;
	if (Solution::Find (d, a))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}