#include<iostream>
#include<cstring>
#define MAX_N 11
using namespace std;

int N, W[MAX_N][MAX_N], visit[MAX_N];
int minDist = 99999999;

void solution(int idx, int depth, int dist) {
	if (depth == N - 1) {
		if (W[idx][1] != 0) {
			if (minDist > dist + W[idx][1])
				minDist = dist + W[idx][1];
		}
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (!visit[i] && W[idx][i]) {
			visit[i] = 1;
			solution(i, depth + 1, dist + W[idx][i]);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> W[i][j];
	}

	visit[1] = 1;
	solution(1, 0, 0);
	
	cout << minDist;
	return 0;
}