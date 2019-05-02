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

//���� ���� �ð��� ������ �ʺ���
void showMap() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cout << water_map[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

//���� �� �� �ִ� ��� ������ ���� �ð� ����
//��, ���� �����ְų� �̷� �κ��� -1 �ʱⰪ�� �����ϰ� ��.
void waterBFS(queue<INFO>& water) {
	while (!water.empty()) {
		//�� �и��� ���� �̵�
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
	queue<INFO> Hedgehog;	//����ġ ����
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

			//���������� 1�� ���� ��ġ�� D�� ���̹Ƿ� ���� �ð����� +1���ؼ� ��ȯ
			if (map[H_y][H_x] == 'D')
				return Hedgehog_time + 1;

			//���� ���� �ð��� 1�� �̻� ���̳��ų�,
			//���� ���� �ʴ� �����̸� ����ġ�� �� �� �ִ� ��ġ
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