#include <iostream>
#include <vector>
using namespace std;
//����vector���swap������Ҳ������ͳ������������ֱ�Ӱ�ż���ŵ����ڵ�λ��
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		vector<int> b(len);
		int cntJ = 0;
		for (int i = 0; i < len; i++)
			if (array[i] % 2 != 0)
				b[cntJ++] = array[i];
		for (int i = 0; i < len; i++)
			if (array[i] % 2 == 0)
				b[cntJ++] = array[i];
		array.swap(b);
	}
};

int main() {
	Solution S1;
	vector<int> a = { 1,2,3,4,5 };
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	S1.reOrderArray(a);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}