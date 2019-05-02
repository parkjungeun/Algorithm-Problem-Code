#include<iostream>
#include<cstring>
#define MAX_N 101
using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int N;

int solution(int r, int c, int h) {
	int cnt = 1;
	visited[r][c] = 1;

	for (int i = 0; i < 4; ++i) {
		int y = r + dy[i];
		int x = c + dx[i];

		if (y < 0 || y >= N || x < 0 || x >= N ||
			visited[y][x] || map[y][x] <= h)
			continue;

		cnt+=solution(y, x, h);
	}
	return cnt;
}

int main() {
	cin >> N;

	int maxVal = 0;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> map[r][c];
			if (map[r][c] > maxVal)
				maxVal = map[r][c];
		}
	}

	int ans = 0;
	//물의 높이
	for (int i = 0; i <= maxVal; ++i) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				if (map[r][c] > i && !visited[r][c]) {
					if (solution(r, c, i))
						cnt++;
				}
			}
		}
		if (ans < cnt)
			ans = cnt;
	}
	printf("%d", ans);
	return 0;
}