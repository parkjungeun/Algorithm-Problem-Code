#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int Nums[6];
int check[11][1000000];
int convertNum, maxNum, arrIdx;	//��ȯ Ƚ��, �ִ밪

int numToArr(int num)
{
	int idx = 0;
	int n = num;
	while (n != 0) {
		idx++;
		n /= 10;
	}


	int i = idx;
	while (num != 0) {
		Nums[i - 1] = (num % 10);
		num /= 10;
		i--;
	}
	return idx - 1;
}

int arrToNum(int idx)
{
	int ans = 0;
	for (int i = 0; i <= idx; i++)
		ans = (ans * 10) + Nums[i];
	return ans;
}

void swap(int idx1, int idx2)
{
	int n = Nums[idx1];
	Nums[idx1] = Nums[idx2];
	Nums[idx2] = n;
}

//num : �Է¹��� ����
//cnt : ���� �� �� ��ȯ �ߴ��� ��Ÿ���� ����
void solve(int _num, int cnt)
{
	if (convertNum <= cnt) {
		if (maxNum < _num)
			maxNum = _num;
		return;
	}

	int res;
	for (int i = 0; i < arrIdx; i++)
	{
		for (int j = i + 1; j <= arrIdx; j++)
		{
			swap(i, j);
			res = arrToNum(arrIdx);

			//���� Ƚ�� ��ȯ ���� ���� ��� ���̸�,
			//���� ��� ���鵵 �����Ƿ� ����� �ʿ䰡 ����.
			//�ߺ� ���� �κ�!
			if (!check[cnt][res])
			{
				check[cnt][res] = 1;
				solve(res, cnt + 1);
			}
			swap(j, i);
		}
	}
	return;
}

void init(int num)
{
	maxNum = 0;
	arrIdx = numToArr(num);

	for (int i = 0; i < 11; i++) {
		memset(check[i], 0, sizeof(int) * 1000000);
	}
}

int main()
{
	int N;

	cin >> N;
	for (int tc = 1; tc <= N; tc++)
	{
		int num;
		cin >> num >> convertNum;
		init(num);
		solve(num, 0);
		cout << "#" << tc << " " << maxNum << endl;
	}
	return 0;
}