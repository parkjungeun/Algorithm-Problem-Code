#include<iostream>
#include<string>
#define MAX_N 21
using namespace std;
string map[MAX_N];
int visit[MAX_N][MAX_N], alpha[26] = {};
int R, C, ans = 0;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void solution(int r, int c,int depth) {
	for (int i = 0; i < 4; ++i) {
		int y = r + dy[i], x = c + dx[i];

		if (y >= R || y < 0 || x >= C || x < 0 || visit[y][x] || alpha[map[y][x] - 'A'])
			continue;

		visit[y][x] = 1; alpha[map[y][x] - 'A'] = 1;
		solution(y, x, depth + 1);
		visit[y][x] = 0; alpha[map[y][x] - 'A'] = 0;
	}
	if (depth > ans)
		ans = depth;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	cin.ignore();
	for (int r = 0; r < R; ++r) {
		getline(cin, map[r]);
	}

	visit[0][0] = 1; alpha[map[0][0] - 'A'] = 1;
	solution(0, 0, 1);
	cout << ans;
	return 0;
}