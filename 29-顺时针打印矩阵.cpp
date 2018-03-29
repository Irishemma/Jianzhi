#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<int> printMatrix (vector<vector<int> > matrix) {
		int r1 = 0, r2 = matrix.size() - 1;
		int c1 = 0, c2 = matrix[0].size() - 1;
		vector<int> a;
		while (c1 <= c2 && r1 <= r2) {
			for (int i = c1; i <= c2; i++)
				a.push_back (matrix[r1][i]);
			if (r1 == r2)
				break;
			for (int i = r1 + 1; i <= r2; i++)
				a.push_back (matrix[i][c2]);
			if (c1 == c2)
				break;
			for (int i = c2 - 1; i >= c1; i--)
				a.push_back (matrix[r2][i]);
			for (int i = r2 - 1; i >= r1 + 1; i--)
				a.push_back (matrix[i][c1]);
			r1++;
			r2--;
			c1++;
			c2--;
		}
		return a;
	}

};
int main() {
	Solution s1;
	vector < vector<int> > mm (4);
	for (int i = 0; i < 4; i++)
		mm[i].resize (4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			mm[i][j] = i * 4 + j + 1;
	}
	vector<int > c = s1.printMatrix (mm);
	return 0;
}