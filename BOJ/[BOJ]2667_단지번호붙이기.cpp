#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX_N 26

using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int N;

int solution(int r, int c) {
	int cnt = 1;

	visited[r][c] = 1;
	for (int i = 0; i < 4; ++i) {
		int _r = r + dy[i], _c = c + dx[i];

		if (_r < 0 || _r >= N || _c < 0 || _c >= N || visited[_r][_c])
			continue;

		if(map[_r][_c] && !visited[_r][_c])
			cnt += solution(_r, _c);
	}
	return cnt;
}

int main() {
	scanf("%d", &N);

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			scanf("%1d", &map[r][c]);
		}
	}

	vector<int> v;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (!visited[r][c] && map[r][c])
				v.push_back(solution(r, c));
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); ++i)
		printf("%d\n", v[i]);

	return 0;
}
