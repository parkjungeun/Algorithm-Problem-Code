#include<iostream>
#include<queue>
#define MAX_N 1000001
using namespace std;

int solution(int X) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(X, 0));

	while (!Q.empty()) {
		int n = Q.front().first;
		int cnt = Q.front().second;
		
		Q.pop();

		if (n == 1)
			return cnt;
		if (n % 3 == 0)
			Q.push(make_pair(n / 3, cnt + 1));
		if (n % 2 == 0)
			Q.push(make_pair(n / 2, cnt + 1));
		if (n - 1 > 0)
			Q.push(make_pair(n - 1, cnt + 1));
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int X;
	
	cin >> X;
	cout << solution(X);
	return 0;
}