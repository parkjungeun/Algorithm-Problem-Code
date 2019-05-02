#include<iostream>
#include<stdio.h>

#define MAX_N 2000
#define MAX_M 500

char data[MAX_N][MAX_M + 1];
char PW[8];
int num[5][5][5];

//��ȣ ��ĵ ��Ģ�� ���� ��ȣ�ڵ�� 0���� ������ �� ����!
void initData()
{
	num[2][1][1] = 0;
	num[2][2][1] = 1;
	num[1][2][2] = 2;
	num[4][1][1] = 3;
	num[1][3][2] = 4;
	num[2][3][1] = 5;
	num[1][1][4] = 6;
	num[3][1][2] = 7;
	num[2][1][3] = 8;
	num[1][1][2] = 9;
}

int conv(char val)
{
	int tmp = val >= 'A' ? val - 'A' + 10 : val - '0';
	return tmp;
}

int findMin(int a, int b, int c)
{
	int temp;
	temp = a < b ? a : b;
	temp = temp < c ? temp : c;
	return temp;
}

bool isValid()
{
	//PW[7]�� ù��° ��ȣ�ڵ� PW[0]�� ������ �����ڵ��̴�.
	int sum = (PW[7] + PW[5] + PW[3] + PW[1]) * 3
		+ (PW[6] + PW[4] + PW[2]) + PW[0];

	if (sum % 10 == 0)
		return true;
	else
		return false;
}

int solution(int n, int m)
{
	int val;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)	//�迭�� 0���� m-1������ idx.
		{
			if (data[i][j] == '0')	//'0'�϶��� ����� �ʿ�X
				continue;

			if (data[i - 1][j] == '0')	//ó������ ��ȣ�ڵ尡 �����ϴ� �κ�.
			{
				val = conv(data[i][j]);	//16������ ǥ�õ� ���ڸ� 10������ �ٲٴ� �κ�

				int cnt = 0;	//4bit�� ����ϱ� ����.
				for (int idx = 0; idx < 8; idx++) 
				{
					int check[4] = { 0, };

					//0�� 1�� ������ ���� �κ�.
					//0101�� ������� ���;���. �� �� �������� ��� X. ������.
					for (int k = 0; k < 4; k++)
					{
						while ((val & 1) == (k & 1))	//(������ ��Ʈ�� ����.)
						{
							check[k]++;
							cnt++;
							val = val >> 1;

							if (cnt == 4) {	//�� char�� �Ѿ ��.
								cnt = 0;
								j--;
								val = conv(data[i][j]);
							}
						}
					}

					//��ȣ��Ģ�� �°� 0 -> 1 -> 0 -> 1�� ������ ������, �ش��ϴ� ��ȣ(��)�� ã�� PW�� ����
					//PW[0]�� ������ ��ȣ�ڵ� (�������� ����ȴ�, �ڿ��� ���� ����� �����Ƿ�..)
					int min = findMin(check[1], check[2], check[3]);
					//�� ����� �÷� ��ȣ�� �ۼ��� ���� �ֱ⿡, �ּҰ����� ������ �ָ� ������ ��ȣ �ڵ带 ���� �� �ִ�.
					if (min != 0) {	//min���� ������ 1�̻��� ��������, Ȥ�� �� ��Ȳ�� �����...
						PW[idx] = num[check[3] / min][check[2] / min][check[1] / min];
					}
				}
				if (isValid()) {	//���� ��ȿ�Ѱ�?
					for (int p = 0; p < 8; p++)
						ans += PW[p];
				}
			}
		}
	}
	return ans;
}

int main()
{
	initData();

	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; test++)
	{
		int N, M, ans = 0;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%s", data[i]);
		}

		ans = solution(N, M);
		printf("#%d %d\n", test, ans);
	}
}