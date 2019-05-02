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
		int x = Q.front().first;	//세로, x값
		int y = Q.front().second; //가로, y값

		Q.pop();

		if (map[x][y] == 3)	//도착지 도착하면 끝.
		{
			cout << " 1";
			return;
		}

		for (int i = 0; i < 4; i++)	//사방에 갈길이 있나 검사 후, 큐에 삽입
		{
			int temp_x = x + offset_x[i];
			int temp_y = y + offset_y[i];
			if (temp_x < 0 || temp_x > SZ || temp_y < 0 || temp_y > SZ)
				continue;
			if (map[temp_x][temp_y] == 1 || visited[temp_x][temp_y] == 1)	//벽이거나, 이미 들른 곳이면 넘어감.
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