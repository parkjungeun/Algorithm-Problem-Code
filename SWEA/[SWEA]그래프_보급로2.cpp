#pragma warning(disable:4996)
#include<stdio.h>
#include<queue>
#include<memory.h>
#define MAX_N 100
#define INT_MAX 999999

using namespace std;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int Graph[MAX_N][MAX_N], Dist[MAX_N][MAX_N], N;

int solution() {
	int minTime = INT_MAX;
	queue<pair<int, int>> Q;
	Q.push(make_pair(0, 0));
	Dist[0][0] = 0;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];
			if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N)
				continue;

			int d = Dist[x][y] + Graph[temp_x][temp_y];
			if (d < Dist[temp_x][temp_y]) {
				Dist[temp_x][temp_y] = d;
				Q.push(make_pair(temp_x, temp_y));
			}
		}
	}
	return Dist[N - 1][N - 1];
}

void init() {
	for (int i = 0; i < MAX_N; i++) {
		memset(Dist[i], INT_MAX, sizeof(int) * MAX_N);
		memset(Graph[i], 0, sizeof(int) * MAX_N);
	}

	scanf("%d", &N);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			scanf("%1d", &Graph[x][y]);
		}
	}
	return;
}

void printDist() {
	printf("\nDist : \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j)
			printf("%2d", Dist[i][j]);
		printf("\n");
	}
}

int main()
{
	int test = 0;
	scanf("%d", &test);

	for (int i = 1; i <= test; i++) {
		init();
		printf("#%d %d\n", i, solution());
		//printDist();
	}

	return 0;
}