#include<iostream>
#include<vector>

using namespace std;

int map[100][2] = { 0, };
int visit[100][2] = { 0, };
int flag = 0;

int dfs(int n)
{
	if (map[n][0] == 99 || map[n][1] == 99) {
		flag = 1;
	}

	if (map[n][0] && !visit[n][0]) {
		visit[n][0] = 1;

		if (map[n][0] == 99)
			return 1;

		dfs(map[n][0]);
	}
	if (map[n][1] && !visit[n][1]) {
		visit[n][1] = 1;

		if (map[n][1] == 99)
			return 1;

		dfs(map[n][1]);
	}

	return flag;
}

void init()
{
	for (int i = 0; i < 100; i++) {
		memset(map[i], 0, sizeof(int) * 2);
		memset(visit[i], 0, sizeof(int) * 2);
	}
	flag = 0;
	return;
}

int main()
{
	int test, path;
	int x, y;

	for (int i = 0; i < 10; i++)
	{
		init();
		scanf("%d %d", &test, &path);
		for (int j = 0; j < path; j++) {
			scanf("%d %d", &x, &y);
			if (map[x][0] == 0)
				map[x][0] = y;
			else
				map[x][1] = y;
		}
		cout << "#" << test << " " << dfs(0) << endl;
	}
	return 0;
}