//https://www.acmicpc.net/problem/3055
#include<iostream>
#include<queue>
#include<cstring>
#define MAX_N 51
using namespace std;

struct INFO {
	int y, x, time;
};

char map[MAX_N][MAX_N];
int water_map[MAX_N][MAX_N], visited[MAX_N][MAX_N], R, C;
int dy[4] = { 0,0,-1,1 }, dx[4] = { -1,1,0,0 };

//물이 차는 시간을 저장한 맵보기
void showMap() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cout << water_map[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

//물이 찰 수 있는 모든 공간에 차는 시간 저장
//단, 돌로 막혀있거나 이런 부분은 -1 초기값을 유지하게 됨.
void waterBFS(queue<INFO>& water) {
	while (!water.empty()) {
		//매 분마다 물의 이동
		int w_y = water.front().y;
		int w_x = water.front().x;
		int w_time = water.front().time;
		water.pop();

		for (int i = 0; i < 4; ++i) {
			int y = w_y + dy[i];
			int x = w_x + dx[i];

			if (y < 0 || y >= R || x < 0 || x >= C)
				continue;
			if (map[y][x] == '.' && water_map[y][x] == -1) {
				water_map[y][x] = w_time + 1;
				water.push({ y, x, w_time + 1 });
			}
		}
	}
	return;
}

int solution(int _r, int _c) {
	queue<INFO> Hedgehog;	//고슴도치 정보
	Hedgehog.push({ _r,_c, 0 });

	while (!Hedgehog.empty()) {
		int Hedgehog_y = Hedgehog.front().y;
		int Hedgehog_x = Hedgehog.front().x;
		int Hedgehog_time = Hedgehog.front().time;
		Hedgehog.pop();

		for (int i = 0; i < 4; ++i) {
			int H_y = Hedgehog_y + dy[i];
			int H_x = Hedgehog_x + dx[i];

			if (H_y < 0 || H_y >= R || H_x < 0 || H_x >= C ||
				map[H_y][H_x] == 'X' || map[H_y][H_x] == '*' || visited[H_y][H_x])
				continue;

			//기준점에서 1분 뒤의 위치가 D인 것이므로 지금 시간에서 +1분해서 반환
			if (map[H_y][H_x] == 'D')
				return Hedgehog_time + 1;

			//물이 차는 시간과 1분 이상 차이나거나,
			//물이 차지 않는 공간이면 고슴도치가 갈 수 있는 위치
			if (water_map[H_y][H_x] > (Hedgehog_time + 1) || water_map[H_y][H_x] == -1) {
				visited[H_y][H_x] = 1;
				Hedgehog.push({ H_y,H_x,Hedgehog_time + 1 });
			}
		}
	}
	return -1;
}


int main() {
	cin >> R >> C;

	queue<INFO> water;
	int s_x, s_y;

	memset(water_map, -1, sizeof(water_map));
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> map[r][c];
			if (map[r][c] == '*') {
				water_map[r][c] = 0;
				water.push({ r,c,0 });
			}
			else if (map[r][c] == 'S') {
				water_map[r][c] = 0;
				visited[r][c] = 1;
				s_y = r; s_x = c;
			}
		}
	}

	waterBFS(water);

	int res = solution(s_y, s_x);
	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res;
	return 0;
}