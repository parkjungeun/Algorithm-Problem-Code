#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#define MAX_N 20
using namespace std;

int map[MAX_N][MAX_N], dice[4][4] = { 0, };
int N, M, x, y, K;
//동 1, 서 2, 북 3, 남 4
int dy[5] = { 0,1,-1,0,0 }, dx[5] = { 0,0,0,-1,1 };
queue<int> Q;

void showDice()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%2d", dice[i][j]);
		}
		printf("\n");
	}
}

void moveDice(int dir) {
	vector<int> v;

	for (int i = 0; i < 4; ++i)
		v.push_back(dir <= 2 ? dice[1][i] : dice[i][1]);

	int cur = 0, sz = v.size(), idx;

	//방향이 동쪽, 남쪽이면,
	if (dir == 1 || dir == 4)
		idx = 1;
	else if (dir == 2 || dir == 3)
		idx = sz - 1;

	while (cur != sz) {
		if (dir == 1 || dir == 2)
			dice[1][idx] = v[cur];
		else
			dice[idx][1] = v[cur];

		idx = (idx+1) % sz;
		cur++;
	}

	if (dir <= 2)
		dice[3][1] = dice[1][3];
	else
		dice[1][3] = dice[3][1];
	return;
}

void solution() {
	//명령 다 수행할 때 까지
	while (!Q.empty()) {
		int dir = Q.front();
		Q.pop();

		if (y + dy[dir] < 0 || y + dy[dir] >= M || x + dx[dir] < 0 || x + dx[dir] >= N)
			continue;
	
		moveDice(dir);
		y += dy[dir]; x += dx[dir];
	
		if (map[x][y]) {
			dice[3][1] = dice[1][3] = map[x][y];
			map[x][y] = 0;
		}
		else	map[x][y] = dice[3][1];

		printf("%d\n", dice[1][1]);
	}
	return;
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c)
			scanf("%d", &map[r][c]);
	}

	int n;
	for (int i = 0; i < K; ++i) {
		scanf("%d", &n);	Q.push(n);
	}

	solution();
	return 0;
}