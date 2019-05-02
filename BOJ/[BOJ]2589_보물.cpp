#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<cstring>
#define MAX_N 51
using namespace std;
struct INFO {
	int r, c, time;
};

char map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N], R, C;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int solution(int r, int c, int time) {
	memset(visited, 0, sizeof(visited));

	queue<INFO> Q;
	Q.push({ r,c,time });	visited[r][c] = 1;

	int ans = 0;
	while (!Q.empty()) {
		int y = Q.front().r;
		int x = Q.front().c;
		int h = Q.front().time;
		Q.pop();

		ans = max(ans, h);
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C ||
				visited[ny][nx] || map[ny][nx] == 'W')
				continue;

			visited[ny][nx] = 1;
			Q.push({ ny,nx,h + 1 });
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &R, &C);

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c)
			scanf(" %c", &map[r][c]);
	}

	int ans = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (map[r][c] == 'L')
				ans = max(ans, solution(r, c, 0));
		}
	}

	printf("%d", ans);
	return 0;
}