#include<iostream>
#include<string.h>
#include<queue>

#define SZ 16
using namespace std;

int offset_x[4] = { 0,0,-1,1 };
int offset_y[4] = { 1,-1,0,0, };
int map[SZ][SZ];
int visited[SZ][SZ];

queue<pair<int, int> > Q;

void solution()
{
	visited[1][1] = 1;
	Q.push(make_pair(1, 1));

	while (!Q.empty())
	{
		int x = Q.front().first;	//����, x��
		int y = Q.front().second; //����, y��

		Q.pop();

		if (map[x][y] == 3)	//������ �����ϸ� ��.
		{
			cout << " 1";
			return;
		}

		for (int i = 0; i < 4; i++)	//��濡 ������ �ֳ� �˻� ��, ť�� ����
		{
			int temp_x = x + offset_x[i];
			int temp_y = y + offset_y[i];
			if (temp_x < 0 || temp_x > SZ || temp_y < 0 || temp_y > SZ)
				continue;
			if (map[temp_x][temp_y] == 1 || visited[temp_x][temp_y] == 1)	//���̰ų�, �̹� �鸥 ���̸� �Ѿ.
				continue;

			Q.push(make_pair(temp_x, temp_y));
			visited[temp_x][temp_y] = 1;
		}
	}
	cout << " 0";
	return;
}

void init()
{
	for (int i = 0; i < SZ; i++)
	{
		memset(map[i], -1, sizeof(int)*SZ);
		memset(visited[i], 0, sizeof(int)*SZ);
		while (!Q.empty())
			Q.pop();
	}
	return;
}

int main()
{
	int n;
	for (int test = 0; test < 10; test++)
	{
		init();
		cin >> n;
		for (int i = 0; i < SZ; i++) {
			for (int j = 0; j < SZ; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		cout << "#" << n;
		solution();
		cout<< endl;
	}
}