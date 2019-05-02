#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 8
using namespace std;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N;	//������ �� ���� ���� N�� 3 �� N �� 8
int K;	//�ִ� ���� ���� ���� K�� 1 �� K �� 5
int maxH; //���� ���� ���츮�� ����
int ans = 0;	//��
bool flag = false;	//K�� ����ߴ��� ���ߴ��� �˱� ����.
vector<pair<int, int> > v;	//���� ���� ���츮 ����

//K��ŭ ��Ƽ� �� �� �ִ��� üũ
int isOK(int y, int x, int dir) {
	int diff = map[y + dy[dir]][x + dx[dir]] - map[y][x];

	//���� ���̸� �ȵǹǷ�, 1 �� �������.
	if (abs(diff) + 1 <= K)	return abs(diff) + 1;
	else	return -999;
}

void solution(int y, int x, int depth) {

	visited[y][x] = 1;

	if (depth > ans)	ans = depth;

	for (int i = 0; i < 4; ++i) {
		int _x = x + dx[i], _y = y + dy[i];

		if (_x < 0 || _x >= N || _y < 0 || _y >= N || visited[_y][_x])
			continue;

		if (map[_y][_x] >= map[y][x]) {
			int diff = isOK(y, x, i);
			if (!flag && diff > 0 && map[_y][_x] - diff >= 0) {
				flag = true;	map[_y][_x] -= diff;
				solution(_y, _x, depth + 1);
				flag = false;	map[_y][_x] += diff;
			}
		}
		else
			solution(_y, _x, depth + 1);
	}
	visited[y][x] = 0;
	return;
}

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	maxH = 0; N = 0; K = 0;	ans = 0; flag = false;
	v.clear();
	return;
}

int main() {
	int testCase, max = 0, result = 0;
	cin >> testCase;

	for (int i = 1; i <= testCase; ++i) {
		init();
		cin >> N >> K;

		//map �Է¹ޱ�
		max = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				cin >> map[j][k];
				if (max < map[j][k])	max = map[j][k];
			}
		}

		//���� ���� ���츮 ���� ���ϱ�
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (max == map[j][k])
					v.push_back(make_pair(j, k));
			}
		}

		//�� ���������� ���� ���� ���ϱ�
		for (int j = 0; j < v.size(); ++j) {
			int y = v[j].first, x = v[j].second;

			solution(y, x, 1);

			if (result < ans)	result = ans;
			ans = 0;
		}

		cout << '#' << i << ' ' << result << '\n';
		result = 0;
	}
	return 0;
}