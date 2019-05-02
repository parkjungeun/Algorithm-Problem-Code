//�簢������� ���� �ٽ�. dx,dy�� �� �������θ� �� �� �ֵ���!!!!!!
#include<iostream>
#include<stdio.h>
#include<cstring>
#define MAX_N 20

using namespace std;

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int Disert[101];
int N; //N�� 4 �̻� 20 ����
int start_x, start_y;
int result;
//���� -> ���� -> ��� -> �»�
int dx[4] = { -1,1,1,-1 }, dy[4] = { 1,1,-1,-1 };

void solution(int y, int x, int depth, int dir) {

	visited[y][x] = 1;	Disert[map[y][x]]++;

	/*
	�簢���� ����� ���ؼ��� 2���� �������θ� �̵� ����.
	1. ���� �������� ��� �̵�
	2. �ݽð�������� 90�� ȸ��
	*/
	for (int i = dir; i <= dir + 1; ++i) {	
		int _y = y + dy[i], _x = x + dx[i];

		//�簢���� ���� �� (�������� �ٽ� �ǵ��� �� ��.)
		if (_y == start_y && _x == start_x) {
			if (result < depth)	//���� �� ��Ʈ�� ���� ����.
				result = depth;
			break;
		}

		if (_x < 0 || _x >= N || _y < 0 || _y >= N || Disert[map[_y][_x]] || visited[_y][_x])
			continue;

		solution(_y, _x, depth + 1, i);
	}

	visited[y][x] = 0;	Disert[map[y][x]]--;
	return;
}

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(Disert, 0, sizeof(Disert));
	result = -1;
	return;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%d", &N);
		init();
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k)
				scanf("%d", &map[j][k]);
		}

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				//map�� �� �������� �鸱 �� ����. (�밢�� �������θ� ������ �簢���� ����⿡..)
				if ((y == 0 && x == 0) || (y == 0 && x == N - 1) ||
					(y == N - 1 && x == 0) || (y == N - 1 && x == N - 1))
					continue;
				start_x = x; start_y = y;
				solution(y, x, 1, 0);	//���� ��ǥ(y,x), �鸰 ����Ʈ���� ��, ���� direction
			}
		}
		printf("#%d %d\n", i, result);
	}
	return 0;
}