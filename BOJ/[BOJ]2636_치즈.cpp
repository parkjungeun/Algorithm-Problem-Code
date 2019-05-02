#pragma warning(disable:4996)
#include<stdio.h>
#include<cstring>
#include<queue>
#define MAX_N 100

using namespace std;
int  map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int M, N;	//���� ���� ����
int time = 1;	//1�ð� �ں��� ��� �����ϹǷ� 1���� ����
int cheeseNum = 0;
queue<pair<int, int> > Q;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int solution() {
	while (cheeseNum != 0) {
		Q.push(make_pair(0, 0));
		int curCheese = cheeseNum;

		while (!Q.empty()) {
			int cur_r = Q.front().first;
			int cur_c = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; ++i) {
				int _y = cur_r + dy[i];
				int _x = cur_c + dx[i];

				if (_x >= M || _x < 0 || _y >= N || _y < 0)
					continue;

				//ġ� �ִ� ���ε� ���� �湮 ���� ��.
				if (map[_y][_x] && !visited[_y][_x]) {
					visited[_y][_x] = 1;
					map[_y][_x] = 0;	cheeseNum--; //ġ�� ���̱�!
				}
				else if (!map[_y][_x] && !visited[_y][_x]) {
					//ġ�� �κ��� �ƴ�, ���� �湮 ���� ���� �κе��� ��� Q
					visited[_y][_x] = 1;
					Q.push(make_pair(_y, _x));
				}
			}
		}

		if (!cheeseNum)
			return curCheese;	//��� ��� ��, ���� ġ�� �� ��ȯ
		time++;	// �ð� ����
		memset(visited, 0, sizeof(visited));
	}
}

int main()
{
	scanf("%d %d", &N, &M);	//����, ����

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			scanf("%d", &map[r][c]);
			if (map[r][c])
				cheeseNum++;
		}
	}

	int lastCheese = solution();
	printf("%d\n%d", time, lastCheese);
	return 0 ;
}