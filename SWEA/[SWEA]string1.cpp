#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string str, string find)
{
	int ans = 0;
	int str_len = str.length();
	int find_len = find.length();

	for (int i = 0; i < str_len - find_len + 1; i++) {
		int same = 0;
		for (int j = 0; j < find_len; j++) {
			if (find[j] == str[i + j])
				same++;
		}
		if (same == find_len) {
			ans++;
			i += find_len;
		}
	}

	return ans;
}

int main() {
	int test;

	for (int i = 0; i < 10; i++) {
		string str; string find;
		cin >> test;
		cin >> find;
		cin >> str;

		cout << '#' << test << ' ' << solution(str, find) << endl;
	}
	return 0;
}