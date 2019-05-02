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
	//2. ���� ������� ���ʴ�� Ž���� ����
	for (int i = 0; i < 4; i ++) {
		dir = (dir + 3) % 4;
		int temp_y = r + dy[dir], temp_x = c + dx[dir];

		if (temp_y <= 0 || temp_y >= N || temp_x <= 0 || temp_x >= M)
			continue;

		//2. ���ʿ� ���� û������ ���� ������ ���� ��,
		if (!map[temp_y][temp_x] && !visited[temp_y][temp_x]) {
			//1. ���� ��ġ û��
			visited[temp_y][temp_x] = 1;	ans++;
			solution(temp_y, temp_x, dir);

			//return�� �ǹ�?
			//��� ������ ���� ���� �ƴ� ���ʸ� ���� ������ �������� ������ ���� ������ �����Ѵ�.
			return;
		}
	}

	//����� ������ ��, ���������ϸ� ����. �Ұ����ϸ� ��.
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