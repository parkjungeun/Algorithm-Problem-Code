#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX_N 51
using namespace std;
int map[MAX_N][MAX_N], visit[MAX_N][MAX_N], w, h;
int dx[8] = { 0,0,-1,1,-1,1,-1,1 }, dy[8] = { -1,1,0,0,-1,-1,1,1 };

int solution(int r, int c) {
	int cnt = 0;
	queue<pair<int, int> > Q;
	Q.push({ r,c });	visit[r][c] = 1;

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; ++i) {
			int y = r + dy[i];
			int x = c + dx[i];

			if (y < 0 || y >= h || x < 0 || x >= w || visit[y][x] || !map[y][x])
				continue;

			Q.push({ y,x }); visit[y][x] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)	return 0;

		memset(visit, 0, sizeof(visit));

		//map 정보 입력
		for (int r = 0; r < h; ++r) {
			for (int c = 0; c < w; ++c)
				cin >> map[r][c];
		}

		vector<int> v;
		for (int r = 0; r < h; ++r) {
			for (int c = 0; c < w; ++c) {
				if (!visit[r][c] && map[r][c])
					v.push_back(solution(r, c));
			}
		}

		cout << v.size() << '\n';
	}
}