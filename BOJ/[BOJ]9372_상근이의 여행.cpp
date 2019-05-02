#include<iostream>
#include<cstring>
#include<queue>
#define MAX_N 1001

using namespace std;
int map[MAX_N][MAX_N], visit[MAX_N];
int N, M;

int solution(int idx) {
	memset(visit, 0, sizeof(visit));
	queue<int> Q;
	Q.push(idx);

	int ans = 0;
	while (!Q.empty()) {
		int curNum = Q.front();
		Q.pop();

		if (!visit[curNum]) {
			visit[curNum] = 1;
			ans++;

			for (int i = 1; i <= N; ++i) {
				if (map[curNum][i] && !visit[i])
					Q.push(i);
			}
		}
	}
	return ans - 1;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> N >> M;

		int a, b;
		for (int r = 0; r < M; ++r) {
			cin >> a >> b;
			map[a][b] = map[b][a] = 1;
		}
		cout << solution(1) << endl;
	}
	return 0;
}