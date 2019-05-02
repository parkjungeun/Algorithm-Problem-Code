#include<stdio.h>

#define MAX_N 51
using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int N, M, ans = 0;

void solution(int r, int c, int idx) {
	if (map[r][c])
		return;

	int dir = idx;
	//2. 왼쪽 방향부터 차례대로 탐색을 진행
	for (int i = 0; i < 4; i ++) {
		dir = (dir + 3) % 4;
		int temp_y = r + dy[dir], temp_x = c + dx[dir];

		if (temp_y <= 0 || temp_y >= N || temp_x <= 0 || temp_x >= M)
			continue;

		//2. 왼쪽에 아직 청소하지 않은 공간이 있을 때,
		if (!map[temp_y][temp_x] && !visited[temp_y][temp_x]) {
			//1. 현재 위치 청소
			visited[temp_y][temp_x] = 1;	ans++;
			solution(temp_y, temp_x, dir);

			//return의 의미?
			//모든 방향을 가는 것이 아닌 왼쪽만 가기 때문에 왼쪽으로 갔으면 다음 방향은 종료한다.
			return;
		}
	}

	//사방이 막혔을 때, 후진가능하면 후진. 불가능하면 끝.
	if (map[r + dy[(dir + 2) % 4]][c + dx[(dir + 2) % 4]])
		return;
	solution(r + dy[(dir + 2) % 4], c + dx[(dir + 2) % 4], dir);
}

int main() {
	scanf("%d %d", &N, &M);

	int y, x, d;
	scanf("%d %d %d", &y, &x, &d);
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			scanf("%d", &map[r][c]);
		}
	}
	visited[y][x] = 1;	ans++;
	solution(y, x, d);
	printf("%d", ans);
	return 0;
}