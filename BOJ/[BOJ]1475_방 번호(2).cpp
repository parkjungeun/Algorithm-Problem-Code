#include<iostream>
#include<string>
using namespace std;
int num[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		num[str[i] - '0']++;

	num[6] += num[9];	num[9] = 0;
	if (num[6] > 1) {
		if (num[6] % 2) num[6]++;
		num[6] /= 2;
	}

	int cnt = 0;
	for (int i = 0; i < 10; ++i) {
		if (cnt < num[i])	cnt = num[i];
	}
	cout << cnt;
	return 0;
}