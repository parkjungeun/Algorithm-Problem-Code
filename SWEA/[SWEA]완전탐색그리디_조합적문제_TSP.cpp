#include<iostream>

using namespace std;

#define INF 987654321
#define MAX_N 6
int N;
int map[MAX_N][MAX_N];

int solve(int position, int visited)
{
	if (visited == (1 << N) - 1)	//모든 마을 다 들린 것
	{
		return 0;
	}

	int res = INF;
	for (int next = 0; next < N; next++)
	{
		if (!(visited & (1 << next)) && map[position][next])	//아직 안들린 곳이고, 길이 있다면
		{
			int tmp = map[position][next] + solve(next, (visited | (1 << next)));

			if (tmp < res) {
				res = tmp;
			}
		}
	}
	return res;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	int res = INF;
	for (int i = 0; i < N; i++)
	{
		int tmp = solve(i, 1 << i);	//i번째 마을이 시작점. i번째 마을 들렀다고 표시

		if (tmp < res) {
			res = tmp;
		}
	}
	cout << "res : " << res;
	return 0;
}
