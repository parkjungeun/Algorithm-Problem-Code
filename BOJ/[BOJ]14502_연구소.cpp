#pragma warning(disable:4996)
/*
해결법
1. 벽은 무조건 3개를 세워야함 (3개가 놓일 수 있는 모든 경우의 수 : 완전 탐색)
2. 벽이 3개 놓아졌을 때, 퍼진 바이러스 영역 계산 (DFS)
3. 바이러스가 퍼진 후, 안전영역 개수 구하기 (0의 개수 세기)
*/
#include<stdio.h>
#include<cstring>
#include<vector>
#define MAX_N 8

using namespace std;
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int virus;	//바이러스 개수
int M, N;	//가로, 세로
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int result = -1;
vector<pair<int, int> > virusPosition;

void checkSafeZone() {
	int ans = 0;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			if (!visited[row][col])
				ans++;
		}
	}
	if (ans > result)
		result = ans;
	return;
}

void fillVirus(int r, int c) {
	visited[r][c] = 1;

	for (int i = 0; i < 4; ++i) {
		int y = r + dy[i];
		int x = c + dx[i];

		if (x >= M || x < 0 || y >= N || y < 0 || visited[y][x] || map[y][x] == 1)
			continue;

		fillVirus(y, x);
	}
}

//wallCnt : 벽의 개수 3개까지 가능
void solution(int r, int c, int wallCnt) {
	if (wallCnt == 3) {
		int sz = virusPosition.size();

		memcpy(visited, map, sizeof(map));
		for (int i = 0; i < sz; ++i)
			fillVirus(virusPosition[i].first , virusPosition[i].second);
		checkSafeZone();

		//memcpy(visited, 0, sizeof(visited));
		return;
	}

	for (int i = r; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!map[i][j]) {
				map[i][j] = 1;
				solution(i, j, wallCnt + 1);
				map[i][j] = 0;
			}
		}
	}

	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			scanf("%d", &map[row][col]);
			if (map[row][col] == 2)	//바이러스 위치
				virusPosition.push_back(make_pair(row, col));
		}
	}

	solution(0, 0, 0);

	printf("%d", result);
	return 0;
}