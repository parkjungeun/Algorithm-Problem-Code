#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX_N 20
using namespace std;

struct Info {
	int y;
	int x;
	int sz;
	int eat; // �� ������ �Ծ�����
	int sec; // �̵��� �ð�
};

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N, ans = 0;
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };

bool cmp(Info& a, Info& b) {
	if (a.sec <= b.sec) {
		if (a.sec == b.sec) {		// �ð��� ���� ���
			if (a.y <= b.y) {		// y���� ���� ��
				if (a.y == b.y) {	// y���� ������
					if (a.x < b.x)	return true;	//	x���� �� ���� ��
					else	return false;
				}
				return true;
			}
			else	return false;
		}
		else	return true;
	}
	return false;
}

void solution(int shark_y, int shark_x) {
	queue<Info> Q;	//����� �湮 ���� ��ġ
	vector<Info> v;	//���� �� �ִ� ����� ����
	Info info = { shark_y, shark_x, 2, 0 ,0 };

	while (1) {
		v.clear();	memset(visited, 0, sizeof(visited));
		visited[info.y][info.x] = 1;	Q.push(info);

		while (!Q.empty()) {
			int y = Q.front().y;
			int x = Q.front().x;
			int sz = Q.front().sz;
			int eat = Q.front().eat;
			int time = Q.front().sec;
			Q.pop();

			//��,��,��,�� �˻�
			for (int i = 0; i < 4; ++i) {
				int temp_x = x + dx[i];
				int temp_y = y + dy[i];

				if (temp_x < 0 || temp_x >= N || temp_y<0 || temp_y >= N ||
					map[temp_y][temp_x]>sz || visited[temp_y][temp_x])
					continue;

				//���� ���� �� ���� ������ �� �ִ� ���
				visited[temp_y][temp_x] = 1;

				if (map[temp_y][temp_x] == 0 || map[temp_y][temp_x] == sz)	//�׳� �������� ��
					Q.push({ temp_y, temp_x, sz, eat, time + 1 });
				else if (map[temp_y][temp_x] < sz)	//�Ʊ� �� ���� �� �ִ� ������� ���,
					v.push_back({ temp_y, temp_x, sz, eat + 1, time + 1 });	//���� �� �ִ� ������� ������ �����ϴ� ���Ϳ� ����
			}
		}

		//���� �� �ִ� ����Ⱑ ����	(������ �κ�)
		if (v.size() == 0)	break;

		//���� �� �ִ� ����Ⱑ �ִ� ���� ���� �ð��� ª��(������), ���ʿ� ������, ���ʿ� �ִ� �� -> �̷��� ����
		sort(v.begin(), v.end(), cmp);
		
		//���� ���� ����� ������ ����� ũ��� ������, ����� ũ�� +1, ���� ������ �ʱ�ȭ
		if (v[0].sz == v[0].eat) {
			v[0].sz++;	v[0].eat = 0;
		}

		//�� ���� ����� ����.
		map[v[0].y][v[0].x] = 0;
		//�� ���������� ���µ� �ɸ� �ð�
		ans += v[0].sec;
		//�� ����� ���� �ٽ� ���� (�ݺ�)
		info = { v[0].y,v[0].x,v[0].sz,v[0].eat,0 };
	}
	return;
}

int main() {
	scanf("%d", &N);

	int shark_x, shark_y;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			scanf("%d", &map[r][c]);
			
			if (map[r][c] == 9) {	//ó�� ����� ��ġ
				shark_x = c; shark_y = r;
				map[r][c] = 0;
			}
		}
	}
	solution(shark_y, shark_x);	printf("%d", ans);
	return 0;
}