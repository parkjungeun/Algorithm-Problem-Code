//사각형만드는 것이 핵심. dx,dy가 한 방향으로만 돌 수 있도록!!!!!!
#include<iostream>
#include<stdio.h>
#include<cstring>
#define MAX_N 20

using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int Disert[101];
int N; //N은 4 이상 20 이하
int start_x, start_y;
int result;
//좌하 -> 우하 -> 우상 -> 좌상
int dx[4] = { -1,1,1,-1 }, dy[4] = { 1,1,-1,-1 };

void solution(int y, int x, int depth, int dir) {

	visited[y][x] = 1;	Disert[map[y][x]]++;

	/*
	사각형을 만들기 위해서는 2가진 방향으로만 이동 가능.
	1. 진행 방향으로 계속 이동
	2. 반시계방향으로 90도 회전
	*/
	for (int i = dir; i <= dir + 1; ++i) {	
		int _y = y + dy[i], _x = x + dx[i];

		//사각형을 만든 것 (시작점에 다시 되돌아 온 것.)
		if (_y == start_y && _x == start_x) {
			if (result < depth)	//가장 긴 루트의 길이 저장.
				result = depth;
			break;
		}

		if (_x < 0 || _x >= N || _y < 0 || _y >= N || Disert[map[_y][_x]] || visited[_y][_x])
			continue;

		solution(_y, _x, depth + 1, i);
	}

	visited[y][x] = 0;	Disert[map[y][x]]--;
	return;
}

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(Disert, 0, sizeof(Disert));
	result = -1;
	return;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%d", &N);
		init();
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k)
				scanf("%d", &map[j][k]);
		}

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				//map의 각 꼭지점은 들릴 수 없다. (대각선 방향으로만 움직여 사각형을 만들기에..)
				if ((y == 0 && x == 0) || (y == 0 && x == N - 1) ||
					(y == N - 1 && x == 0) || (y == N - 1 && x == N - 1))
					continue;
				start_x = x; start_y = y;
				solution(y, x, 1, 0);	//시작 좌표(y,x), 들린 디저트가게 수, 시작 direction
			}
		}
		printf("#%d %d\n", i, result);
	}
	return 0;
}