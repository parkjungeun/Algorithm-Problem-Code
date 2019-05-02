//조합 : 2개의 값을 더해 만들 수 있는 최대값 - Bit 부분집합예제

#include<iostream>
#define MAX_N 10

using namespace std;

int Nums[MAX_N];
int N;

int countBit(int n)
{
	int cnt = 0;

	while (n > 0)
	{
		if (n & 1)
			cnt++;
		n = n >> 1;
	}
	return cnt;
}

int solve()
{
	int res = 0;
	for (int i = 0; i < (1 << N); i++)
	{
		if (countBit(i) == 2)
		{
			int sum = 0;
			for (int j = 0; j < N; j++)
			{
				if (i & (1 << j))
					sum += Nums[j];
			}
			if (res < sum)
				res = sum;
		}
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

		cout << '#' << i + 1 << solve() << endl;
	}
	return 0;
}