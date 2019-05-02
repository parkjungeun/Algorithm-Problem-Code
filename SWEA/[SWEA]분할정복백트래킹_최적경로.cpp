#include<stdio.h>
#include<memory.h>
#include<algorithm>

struct node {
	int x;
	int y;
};

struct node map[12];
int visit[12];
int N, dist, minDist = INT_MAX;

int calc(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

//��� �ŷ�ó�� �� ������� True
bool finish()
{
	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == 0)
			return false;
	}
	return true;
}

void solution(int cur_idx) {
	if (finish()) {
		//��� �� �� ������� ��. (������ �ŷ�ó -> ��) �Ÿ� ����ؼ� �ּ� �Ÿ����� Ȯ��
		int _dist = calc(map[cur_idx].x, map[cur_idx].y, map[N + 1].x, map[N + 1].y);

		if (dist + _dist < minDist) {
			minDist = dist + _dist;
		}
		return;
	}

	//�ŷ�ó���� ��� ����� ���� ������ �ٴϸ� �Ÿ� ���
	//�ε��� 1���� ����ϴ� ������? ó���Ÿ��� (ȸ�� --> ù ��° �ŷ�ó)�� ����!�̱� ���� 
	for (int i = 1; i < N + 1; i++) 
	{
		//���� �湮���� ���� �ŷ�ó�̰�, ���� �ִ� ��ġ�� �ƴϸ�!
		if (!visit[i] && cur_idx != i) 
		{
			int _dist = calc(map[cur_idx].x, map[cur_idx].y, map[i].x, map[i].y);

			//����� ���� �ٿ��ֱ� ���� �κ�
			//��� �ŷ�ó�� ��ģ �ּ� �Ÿ����� �Ÿ��� ���� ũ�� �� �ڴ� ������� �ʾƵ� ��.
			if (dist + _dist > minDist) {
				continue;
			}

			visit[i] = 1;	dist += _dist;
			solution(i);
			visit[i] = 0;	dist -= _dist;
		}
	}
	return;
}

void init()
{
	int x, y;
	dist = 0; 	minDist = INT_MAX;
	memset(map, 0, sizeof(struct node) * 12);
	memset(visit, 0, sizeof(int) * 12);

	//�ŷ�ó ����
	scanf("%d", &N);

	//ȸ��
	scanf("%d %d", &x, &y);
	map[0].x = x; map[0].y = y;

	//��
	scanf("%d %d", &x, &y);
	map[N + 1].x = x; map[N + 1].y = y;

	//�ŷ�ó��
	for (int i = 1; i < N + 1; i++) {
		scanf("%d %d", &x, &y);
		map[i].x = x; map[i].y = y;
	}
	return;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		init();
		solution(0);	//ù �������� ȸ�����!
		printf("#%d %d\n", test, minDist);
	}

	return 0;
}