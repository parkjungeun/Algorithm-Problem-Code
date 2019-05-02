//1249.[S / W 문제해결 응용] 4일차 - 보급로 D4
#pragma warning (disable:4996)
#include<stdio.h>
#include<queue>
#include<memory.h>
#define MAX_N 100

using namespace std;

int Graph[MAX_N][MAX_N], N;
int Dist[MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int solution()
{
	queue <pair<int, int>> Q;

	Q.push(make_pair(0, 0));	//시작점은 0
	Dist[0][0] = 0;		        //처음 위치이므로 복구 시간은 0

	while (!Q.empty()) {

		int _x = Q.front().first;	//현재의 위치 x,y값을 가져와 대입
		int _y = Q.front().second;
		Q.pop();

		//현재의 위치에서 상하좌우 갈 수 있는지 확인
		for (int i = 0; i < 4; i++) {
			int temp_x = _x + dx[i], temp_y = _y + dy[i];

			//범위를 벗어나면 지도를 벗어난 것이므로 넘김.
			if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N)
				continue;

			//만약, 상하좌우 중 범위 내에 포함된다면, 
			//현재 위치[_x][_y] 까지의 최단거리가 저장된 Dist[_x][_y]에서
			//[temp_x][temp_y]로 이동했을 때 추가되는 복구 시간을 구함.
			int distance = Dist[_x][_y] + Graph[temp_x][temp_y];

			//[_x][_y]을 거쳐 [temp_x][temp_y]로 이동했을 때의 복구 시간이
			//본래의 [temp_x][temp_y]의 값보다 작다면, 더 작은 값으로 갱신시키고,
			//새로운 위치 [temp_x][temp_y]를 큐에 저장. (이후, 여기서 부터 또 사방으로 이동할 것임)
			if (Dist[temp_x][temp_y] > distance) {
				Q.push(make_pair(temp_x, temp_y));
				Dist[temp_x][temp_y] = distance;
			}
		}
	}
	return Dist[N - 1][N - 1];;
}

void init() {
	for (int i = 0; i < MAX_N; i++) {
		memset(Dist[i], 999999, sizeof(int) * MAX_N);
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

int main()
{
	int test = 0;
	scanf("%d", &test);

	for (int i = 1; i <= test; i++) {
		init();
		printf("#%d %d\n", i, solution());
	}

	return 0;
}