class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int l = 0, r = rotateArray.size() - 1, m;
		while (1) {
			if (r - l <= 1)
				return (rotateArray[r] > rotateArray[l]) ? rotateArray[l] : rotateArray[r];
			m = (l + r) / 2;
			if (rotateArray[l] <= rotateArray[m])
				l = m;
			else
				r = m;
		}
	}
};