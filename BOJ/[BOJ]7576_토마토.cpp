#include<iostream>
#include<algorithm>
#include<queue>
#define MAX_N 1001

using namespace std;

int M, N;
int map[MAX_N][MAX_N], visit[MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int solution(vector<pair<int, int> > &point, int d) {
	queue<pair<pair<int, int>,int> > Q;
	
	for (int i = 0; i < point.size(); ++i) {
		Q.push(make_pair(make_pair(point[i].first, point[i].second), d));
		visit[point[i].first][point[i].second] = 1;
	}

	int day, maxDay = -1;
	while (!Q.empty()) {
		int y = Q.front().first.first;
		int x = Q.front().first.second;
		day = Q.front().second;
		Q.pop();

		if (maxDay < day)	maxDay = day;

		for (int i = 0; i < 4; ++i) {
			int temp_y = y + dy[i];
			int temp_x = x + dx[i];

			if (temp_y < 0 || temp_y >= N || temp_x < 0 || temp_x >= M ||
				visit[temp_y][temp_x] || map[temp_y][temp_x] == -1)
				continue;

			visit[temp_y][temp_x] = 1;
			Q.push(make_pair(make_pair(temp_y, temp_x), day + 1));
			//printf("day%d : %d %d %d\n", day, temp_x, temp_y, day + 1);
		}
	}
	return maxDay;
}

int main() {
	cin >> M >> N;
	
	vector<pair<int, int> > point;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 1)
				point.push_back(make_pair(r, c));
		}
	}

	int day = solution(point, 0);
	printf("\n\nDay : %d\n", day);
	
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			printf("%d ", visit[r][c]);
		}
		printf("\n");
	}

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] == 0 && !visit[r][c]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", day);
	return 0;
}