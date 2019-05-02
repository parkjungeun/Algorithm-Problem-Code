#include<iostream>
#define MAX_N 10

using namespace std;
int Nums[MAX_N];
int N;

int solve(int cnt, int used, int val)
{
	if (cnt == 2)
		return val;

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		if (used & (1 << i))
			continue;

		int tmp = solve(cnt + 1, used | (1 << i), val * 10 + Nums[i]);

		if (res < tmp)
			res = tmp;
	}
	return res;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> Nums[j];

		cout << '#' << i + 1 << ' ' << solve(0, 0, 0) << endl;
	}
	return 0;
}