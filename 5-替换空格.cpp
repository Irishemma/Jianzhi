#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	char str[10000] = { '\0' };
	char str2[10000] = { '\0' };
	cin.getline (str, 10000);
	int len = strlen (str);
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')
			cnt++;
	}
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] != ' ')
			str2[i + cnt * 2] = str[i];
		else {
			str2[i + cnt * 2] = '0';
			str2[i + cnt * 2 - 1] = '2';
			str2[i + cnt * 2 - 2] = '\%';
			cnt--;
		}
	}
	cout << str2;
	return 0;
}