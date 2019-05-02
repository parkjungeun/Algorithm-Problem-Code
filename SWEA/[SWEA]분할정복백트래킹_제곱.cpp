//�������� ����� �˰���
#include<stdio.h>
#include<iostream>

using namespace std;

//�ð����⵵ : O(n)
int iterativePower(int x, int n)
{
	int ans = 1;

	for (int i = 0; i < n; i++)
		ans *= x;
	
	return ans;
}

//�ð����⵵ : O(n)
int recursivePower(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	return x*recursivePower(x, n - 1);
}

//�ð����⵵ : O(log n)
int dcPower(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	if (n % 2 == 0) {	//even
		int ans = dcPower(x, n / 2);
		return ans*ans;
	}
	else {	//odd
		int ans = dcPower(x, (n - 1) / 2);
		return ans*ans*x;
	}
}

int main()
{
	int C, n;
	cin >> C >> n;

	cout << "iterativePower : " << iterativePower(C, n) << endl;
	cout << "recursivePower : " << recursivePower(C, n) << endl;
	cout << "dcPower : " << dcPower(C, n) << endl;
}