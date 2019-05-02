#include<iostream>
#include<string>
#define MAX_N 1000001
using namespace std;

void solution(string str, string bomb) {
	int strLen = str.size(), bombLen = bomb.size(), idx = 0;

	char ans[MAX_N];
	for (int i = 0; i < strLen; ++i) {
		ans[idx++] = str[i];

		if (str[i] == bomb[bombLen - 1] && idx - bombLen >= 0) {
			bool flag = 0;
			for (int j = 1; j < bombLen; ++j) {
				if (ans[idx -1 - j] != bomb[bombLen - 1 - j]) {
					flag = 1;
					break;
				}
			}
			if (!flag)
				idx -= bombLen;
		}
	}
	ans[idx] = '\0';
	if (idx == 0)	cout << "FRULA";
	else cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str, tmp;
	cin >> str >> tmp;

	solution(str, tmp);
	return 0;
}