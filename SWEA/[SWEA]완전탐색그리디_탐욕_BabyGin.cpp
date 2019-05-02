#include<iostream>
#define N 6

using namespace std;
int Nums[N];

int solve()
{
	int countNum[10] = { 0, };

	for (int i = 0; i < N; i++)
		countNum[Nums[i]]++;

	int res = 0;

	for (int i = 0; i < 10;)
	{
		if (countNum[i] >= 3) {
			countNum[i] -= 3;
			res++;
		}
		else if (countNum[i] == 1 && i <= 7) {
			if ((countNum[i + 1] == 1) && (countNum[i + 2] == 1))
			{
				countNum[i]--;
				countNum[i + 1]--;
				countNum[i + 2]--;
				res++;
			}
		}
		i++;
	}

	if (res == 2)
		return 1;
	return 0;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Nums[j];

		cout << '#' << i + 1;

		if (solve())
			cout << " : Baby-Gin" << endl;
		else
			cout << " : Non Baby-Gin" << endl;
	}
	return 0;
}