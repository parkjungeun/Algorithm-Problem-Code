#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	int ans = 0, N, visit[26];
	cin >> N;

	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;

		memset(visit, 0, sizeof(visit));
		visit[str[0] - 'a'] = 1;
		
		bool flag = 0;
		for (int j = 1; j < str.size(); ++j) {
			if (str[j - 1] != str[j] && visit[str[j] - 'a']) {
				flag = 1; break;
			}
			if(!visit[str[j] - 'a'])
				visit[str[j] - 'a'] = 1;
		}
		if(!flag)	ans++;
	}
	cout << ans;
	return 0;
}