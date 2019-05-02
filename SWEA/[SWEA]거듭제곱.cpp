#include<iostream>

using namespace std;

int exp(int n, int cnt)
{
	if (cnt <= 0)
		return 1;

	return n*exp(n, cnt - 1);
}

int main()
{
	int n, cnt, temp;

	for (int i = 1; i <= 10; i++)
	{
		//cin >> temp;
		cin >> n >> cnt;
		cout << "#" << i << " " << exp(n, cnt) << endl;
	}
	return 0;
}