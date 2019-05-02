#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#define MAX_N 20
using namespace std;

int map[MAX_N][MAX_N], visit[MAX_N][MAX_N];
int N, maxAns = -1;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

//숫자 이동
void moveMap(int dir) {
	memset(visit, 0, sizeof(visit));
	int s1, s2, one1, one2;
	switch (dir) {
	case 0:	s1 = 0; one1 = 1; s2 = 0; one2 = 1;	break;
	case 1: s1 = N - 1; one1 = -1; s2 = 0; one2 = 1; break;
	case 2:	s1 = 0; one1 = 1; s2 = 0; one2 = 1; break;
	case 3: s1 = 0; one1 = 1; s2 = N - 1; one2 = -1; break;
	default:
		break;
	}

	for (int r = s1, i = 0; i < N; ++i, r += one1) {
		for (int c = s2, j = 0; j < N; ++j, c += one2) {
			if (map[r][c] == 0)	continue;

			int temp_y = r, temp_x = c, flag = 0;
			while (1) {
				temp_y += dy[dir];	temp_x += dx[dir];

				if (temp_y < 0 || temp_y >= N || temp_x < 0 || temp_x >= N) {
					flag = 1;	break;
				}

				if (map[temp_y][temp_x] > 0)	break;
			}

			if (flag == 0) {
				if (!visit[temp_y][temp_x] && !visit[r][c] && (map[temp_y][temp_x] == map[r][c])) {
					map[temp_y][temp_x] *= 2;	visit[temp_y][temp_x] = 1;
					map[r][c] = 0; visit[r][c] = 0;
				}
				else {
					map[temp_y - dy[dir]][temp_x - dx[dir]] = map[r][c];
					visit[temp_y - dy[dir]][temp_x - dx[dir]] = visit[r][c];
					if (((temp_y - dy[dir]) != r) || ((temp_x - dx[dir]) != c)) {
						map[r][c] = 0; visit[r][c] = 0;
					}
				}
			}
			else if (flag == 1) {
				map[temp_y - dy[dir]][temp_x - dx[dir]] = map[r][c];
				visit[temp_y - dy[dir]][temp_x - dx[dir]] = visit[r][c];
				if (((temp_y - dy[dir]) != r) || ((temp_x - dx[dir]) != c)) {
					map[r][c] = 0; visit[r][c] = 0;
				}
			}
		}
	}
}

void solution(int depth) {
	if (depth > 5)
		return;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (maxAns < map[i][j])
				maxAns = map[i][j];
		}
	}

	int _map[MAX_N][MAX_N];
	for (int i = 0; i < 4; ++i) {
		memcpy(_map, map, sizeof(map));
		moveMap(i);	solution(depth + 1);
		memcpy(map, _map, sizeof(_map));
	}
	return;
}

int main(){
	cin >> N;

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) 
			cin >> map[r][c];
	}

	solution(0);
	cout << maxAns;
	return 0;
}