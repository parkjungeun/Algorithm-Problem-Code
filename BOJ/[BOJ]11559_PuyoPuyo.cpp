//https://www.acmicpc.net/problem/11559
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct INFO { int r, c; };
char map[12][6];
int visit[12][6];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int boom(int r, int c, char ch) {
	vector<pair<int, int> > v;
	queue<INFO> Q;
	visit[r][c] = 1;	v.push_back(make_pair(r, c));
	Q.push({ r,c });

	while (!Q.empty()) {
		int r = Q.front().r, c = Q.front().c;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int y = r + dy[i], x = c + dx[i];

			if (y < 0 || y >= 12 || x < 0 || x >= 6 || visit[y][x] || map[y][x] != ch)
				continue;

			visit[y][x] = 1;	v.push_back(make_pair(y, x));
			Q.push({ y,x });
		}
	}

	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); ++i)
			map[v[i].first][v[i].second] = '.';
		return 1;
	}
	return 0;
}

void moveMap(int r, int c) {
	vector<char> v;

	for (int i = 11; i >= 0; --i) {
		if (map[i][c] != '.')
			v.push_back(map[i][c]);
	}
	int sz = v.size();
	for (int i = 0; i < (12 - sz); ++i)
		v.push_back('.');

	int idx = 0;
	for (int i = 11; i >= 0; --i) {
		map[i][c] = v[idx++];
	}
}

int solution() {
	int ans = 0;

	while (1) {
		int cnt = 0;	memset(visit, 0, sizeof(visit));
		//맨 아래부터 올라가면서 BFS로 4개 이상 연결되어있는 부분 .으로 만들기 (터뜨리기)
		for (int r = 11; r >= 0; --r) {
			for (int c = 0; c < 6; ++c) {
				if (!visit[r][c] && map[r][c] != '.')
					cnt += boom(r, c, map[r][c]);
			}
		}

		//바뀐게 없으면 끝
		if (cnt == 0)	return ans;

		//아래부터 검사하여 .이 있으면 그 위에있는 것들 아래로 내리기
		for (int r = 10; r >= 0; --r) {
			for (int c = 0; c < 6; ++c) {
				if (map[r][c] != '.' && map[r + 1][c] == '.')
					moveMap(r, c);
			}
		}

		ans++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	for (int r = 0; r < 12; ++r) {
		for (int c = 0; c < 6; ++c)
			cin >> map[r][c];
	}

	cout << solution();
	return 0;
}