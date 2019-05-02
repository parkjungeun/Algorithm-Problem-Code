//https://www.acmicpc.net/problem/15685
#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define MAX_SIZE 101

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
/*
0: x좌표가 증가하는 방향(→)
1 : y좌표가 감소하는 방향(↑)
2 : x좌표가 감소하는 방향(←)
3 : y좌표가 증가하는 방향(↓)
*/

void solution(int x, int y, int d, int g) {
	vector<pair<int, int> > v;
	vector<int> events;

	//0세대
	v.push_back(make_pair(y, x));	map[y][x] = 1;
	v.push_back(make_pair(y + dy[d], x + dx[d]));	map[y + dy[d]][x + dx[d]] = 1;
	events.push_back(d);

	for (int i = 0; i < g; i++) {
		int sz = events.size();
		
		for (int j = sz - 1; j >= 0; --j) {
			int _y = v[v.size() - 1].first, _x = v[v.size() - 1].second;
			int dir = (events[j] + 1) % 4;
			int temp_y = _y + dy[dir], temp_x = _x + dx[dir];

			if (temp_y < 0 || temp_y >= MAX_SIZE ||	temp_x  < 0 || temp_x >= MAX_SIZE)
				continue;

			map[temp_y][temp_x] = 1;
			v.push_back(make_pair(temp_y, temp_x));
			events.push_back(dir);
		}
	}
}

int checkRect() {
	int cnt = 0;
	for (int r = 0; r < MAX_SIZE-1; ++r) {
		for (int c = 0; c < MAX_SIZE-1; ++c) {
			if (map[r][c] && map[r + 1][c] && map[r][c + 1] && map[r + 1][c + 1])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	int N;
	scanf("%d", &N);

	int x, y, d, g;
	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		solution(x, y, d, g);
	}

	printf("%d", checkRect());
	return 0;
}