#include<iostream>
#include<queue>

#define MAX_N 101
using namespace std;
int map[MAX_N][MAX_N], visrus[MAX_N];
int N, M;

int solution(int idx) {
	int cnt = 0;
	queue<int> Q;
	visrus[idx] = 1;
	Q.push(idx);

	while (!Q.empty()) {
		int curIdx = Q.front();
		Q.pop();

		for (int i = 1; i <= N; ++i) {
			if (map[curIdx][i] && !visrus[i]) {
				Q.push(i);
				visrus[i] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	cout << solution(1);
	return 0;
}