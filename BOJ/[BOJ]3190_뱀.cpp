#include<iostream>
#include<queue>
#include<deque>
#define MAX_N 101
using namespace std;

queue<pair<int, char> > time;
int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N, appleNum, endTime = 0;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

void solution(int r, int c) {
	deque<pair<int, int> > Q;
	
	visited[r][c] = 1;
	Q.push_back(make_pair(r, c));
	
	int idx = 0;
	while (!Q.empty()) {
		//�ð��� ���� ����ٲ��ִ� �κ�
		if (!time.empty() && endTime == time.front().first) {
			char cur_dir = time.front().second;
			time.pop();

			if (cur_dir == 'D')	idx = (idx + 1) % 4;
			else	idx = (idx + 3) % 4;
		}

		int tail_x = Q.back().second, tail_y = Q.back().first;
		int head_x = Q.front().second, head_y = Q.front().first;
		int temp_x = head_x + dx[idx], temp_y = head_y + dy[idx];
		endTime++;

		//���� �ε����ų�, �ڽ��� ���� �ε����� �κ� (����)
		if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N ||
			visited[temp_y][temp_x]) {
			cout << endTime;
			return;
		}

		//������� ��, ���� �κ� �������
		if (!map[temp_y][temp_x]) {
			visited[tail_y][tail_x] = 0;
			Q.pop_back();
		}
		else //��� �Ծ����Ƿ�, 0�����
			map[temp_y][temp_x] = 0;

		//���� ��ġ�� �Ӹ��� �Ű���
		visited[temp_y][temp_x] = 1;
		Q.push_front(make_pair(temp_y, temp_x));
	}
}

int main() {
	cin >> N >> appleNum;

	int r, c;
	for (int i = 0; i < appleNum; ++i) {
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}

	int L,s;	char dir;
	
	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> s >> dir;
		time.push(make_pair(s, dir));
	}

	solution(0, 0);
	return 0;
}