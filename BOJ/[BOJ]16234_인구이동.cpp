#include<stdio.h>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX_N 50
using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N], N;	//1 ≤ N ≤ 50
int L, R, ans = 0;					//1 ≤ L ≤ R ≤ 100
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
bool change = 0;

void showMap() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}printf("\n");
}

void solution(int r, int c) {
	vector<pair<int, int> > v;
	queue<pair<int, int> > Q;
	Q.push(make_pair(r, c));

	while (!Q.empty()) {
		int ny = Q.front().first;
		int nx = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int y = ny + dy[i];
			int x = nx + dx[i];

			if (x < 0 || x >= N || y < 0 || y >= N || visited[y][x])
				continue;
			if (abs(map[y][x] - map[ny][nx]) < L || abs(map[y][x] - map[ny][nx]) > R)
				continue;

			//인구이동 가능한 공간
			visited[y][x] = 1;
			v.push_back(make_pair(y, x));
			Q.push(make_pair(y, x));
		}
	}

	int sz = v.size(), sum = 0;
	if (sz == 0) return;

	for (int i = 0; i < sz; ++i)
		sum += map[v[i].first][v[i].second];

	for (int i = 0; i < sz; ++i)
		map[v[i].first][v[i].second] = (sum / sz);
	change = 1;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			scanf("%d", &map[i][j]);
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		//한 번에 이동가능한 영역 모두 찾기
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if(!visited[i][j])	solution(i, j);
			}
		}
		//1번이라도 이동했으면, 다음 찾아보기
		if (change) { ans++; change = 0; }
		else	break;
	}

	printf("%d", ans);
	return 0;
}