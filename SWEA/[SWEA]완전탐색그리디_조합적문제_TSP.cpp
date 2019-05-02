#include<iostream>

using namespace std;

#define INF 987654321
#define MAX_N 6
int N;
int map[MAX_N][MAX_N];

int solve(int position, int visited)
{
	if (visited == (1 << N) - 1)	//��� ���� �� �鸰 ��
	{
		return 0;
	}

	int res = INF;
	for (int next = 0; next < N; next++)
	{
		if (!(visited & (1 << next)) && map[position][next])	//���� �ȵ鸰 ���̰�, ���� �ִٸ�
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
		int tmp = solve(i, 1 << i);	//i��° ������ ������. i��° ���� �鷶�ٰ� ǥ��

		if (tmp < res) {
			res = tmp;
		}
	}
	cout << "res : " << res;
	return 0;
}
