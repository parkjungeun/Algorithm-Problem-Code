#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define MAX_N 500

using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N, M;
int maxAns = 0;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

//ㅜ모양 정보
vector<vector<pair<int, int> >> shape = { { { 0,1 },{ 0,2 },{ 1,1 } } ,	
										  { { -1,1 },{ 0,1 },{ 1,1 } } ,
										  { { 0,1 },{ -1, 1},{ 0,2 } } ,
										  { { -1,0 },{ 1,0 },{ 0,1 } } };

void solution(int r, int c, int depth, int sum) {
	if (depth == 4) {
		if (maxAns < sum)
			maxAns = sum;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int _c = c + dx[i];
		int _r = r + dy[i];

		if (_c >= M || _c < 0 || _r >= N || _r < 0 || visited[_r][_c])
			continue;

		visited[_r][_c] = 1;
		solution(_r, _c, depth + 1, sum + map[_r][_c]);
		visited[_r][_c] = 0;
	}
	return;
}

void otherSolution(int r, int c) {
	int sz = shape.size();

	for (int i = 0; i < sz; ++i) {
		int sum = 0, cnt = 0;;
		for (int j = 0; j < 3; ++j) {
			int _c = c + shape[i][j].second;
			int _r = r + shape[i][j].first;

			if (_c >= M || _c < 0 || _r >= N || _r < 0)
				continue;

			cnt++;
		}
		if (cnt == 3) {
			sum = map[r][c] + 
				map[r + shape[i][0].first][c + shape[i][0].second] +
				map[r + shape[i][1].first][c + shape[i][1].second] +
				map[r + shape[i][2].first][c + shape[i][2].second];

			//printf("(r,c) : (%d, %d) sum : %d, \t", r, c, sum);
			//printf("%d : %d %d %d %d\n", i, map[r][c], map[r + shape[i][0].first][c + shape[i][0].second],
			//	map[r + shape[i][1].first][c + shape[i][1].second], map[r + shape[i][2].first][c + shape[i][2].second]);
			if (maxAns < sum)
				maxAns = sum;
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);	//세로 가로

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			scanf("%d", &map[r][c]);
		}
	}

	//ㅜ를 제외한 나머지 모든 모양을 검사함.
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			visited[r][c] = 1;
			solution(r, c, 1, map[r][c]);
			visited[r][c] = 0;
		}
	}

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c)
			otherSolution(r, c);
	}

	printf("%d", maxAns);
	return 0;
}