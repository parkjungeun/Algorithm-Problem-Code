#include<iostream>
#include<queue>
#include<string>

using namespace std;

int solution(int a, int b) {
	queue<pair<int, int> > Q;

	Q.push(make_pair(a, 0));

	while (!Q.empty()) {
		int curNum = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (curNum == b)
			return cnt + 1;

		if (curNum * 2 <= b)
			Q.push(make_pair(curNum * 2, cnt + 1));
		
		string str = to_string(curNum) + "1";
		long long n = stoll(str);
		if (n <= (long long)b)	Q.push(make_pair((int)n, cnt + 1));
	}
	return -1;
}

int main() {
	int A, B;
	cin >> A >> B;

	int res = solution(A, B);
	cout << res;
	return 0;
}