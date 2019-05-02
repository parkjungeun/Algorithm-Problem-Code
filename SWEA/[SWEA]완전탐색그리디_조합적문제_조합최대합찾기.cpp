#include<iostream>
#define MAX_N 10

using namespace std;
int Nums[MAX_N];
int N, number=1;

int solve(int pos, int cnt, int val)
{
	if (cnt == 2)
	{
		return val;
	}
	if (pos == N)
		return -1;

	int res = 0, tmp;

	tmp = solve(pos + 1, cnt + 1, val + Nums[pos]);
	if (res < tmp)
		res = tmp;

	tmp = solve(pos + 1, cnt, val);
	if (res < tmp)
		res = tmp;

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