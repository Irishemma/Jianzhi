#include <iostream>
#include <vector>
#include "string.h"
using namespace std; class Solution {
public:
	static void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int len = 0, cnt = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			len++;
			if (str[i] == ' ')
				cnt++;
		}
		int len2 = len + 2 * cnt + 1;
		if (len2 >¡¡length)
			return;
		str[len2 - 1] = '\0';
		for (int i = len - 1; i >= 0; i--) {
			if (str[i] != ' ') {
				str[i + 2 * cnt] = str[i];
			}
			else {
				str[i + 2 * cnt] = '0';
				str[i + 2 * cnt - 1] = '2';
				str[i + 2 * cnt - 2] = '\%';
				cnt--;
			}
		}
	}
};
int main() {
	char str[] = "hello word";
	cout << str << endl;
	int len = 10;
	Solution::replaceSpace(str,len);
	cout << str;
	return 0;
}