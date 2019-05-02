#pragma warning(disable:4996)
/*
�ذ��
1. ���� ������ 3���� �������� (3���� ���� �� �ִ� ��� ����� �� : ���� Ž��)
2. ���� 3�� �������� ��, ���� ���̷��� ���� ��� (DFS)
3. ���̷����� ���� ��, �������� ���� ���ϱ� (0�� ���� ����)
*/
#include<stdio.h>
#include<cstring>
#include<vector>
#define MAX_N 8

using namespace std;
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int virus;	//���̷��� ����
int M, N;	//����, ����
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

//wallCnt : ���� ���� 3������ ����
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
			if (map[row][col] == 2)	//���̷��� ��ġ
				virusPosition.push_back(make_pair(row, col));
		}
	}

	solution(0, 0, 0);

	printf("%d", result);
	return 0;
}