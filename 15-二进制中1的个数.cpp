class Solution {
public:
	int  NumberOf1(int n) {
		unsigned int d = n;
		int cnt = 0;
		while (d != 0) {
			if (d % 2 != 0)
				cnt++;
			d = d >> 1;
		}
		return cnt;
	}
};
//库函数
int  NumberOf2(int n) {
	return Interger.bitCount(n);
}
//O(logM) M为1的数量，每次&操作去掉最低位的1
int  NumberOf3(int n) {
	int cnt = 0;
	while (n != 0) {
		cnt++;
		n &= (n - 1);
	}
	return cnt;
}