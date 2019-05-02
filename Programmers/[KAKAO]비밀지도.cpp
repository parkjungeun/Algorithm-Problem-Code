#include <string>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	vector<int> tmp(n);
	for (int i = 0; i < n; ++i)
		tmp[i] = arr1[i] | arr2[i];

	string ans = "";	int maxLen = 0;
	for (int i = 0; i < n; ++i) {
		ans = "";
		while (tmp[i] != 0) {
			if (tmp[i] & 1)	ans += "#";
			else	ans += " ";
			tmp[i] = tmp[i] >> 1;
		}
		if (ans.size() != n) {
			int sz = ans.size();
			for (int j = 0; j < n - sz; ++j)
				ans += " ";
		}
		reverse(ans.begin(), ans.end());
		answer.push_back(ans);
	}

	for (int i = 0; i < n; ++i)
		cout << answer[i] << '\n';
	cout<< '\n';
	return answer;
}

void main() {
	solution(6, { 1, 1, 1, 1, 1, 11 }, { 1, 1, 1, 1, 1, 50 });
	solution(6, { 27 ,56, 19, 14, 14, 10 }, { 46, 33, 33 ,22, 31, 50 });
}