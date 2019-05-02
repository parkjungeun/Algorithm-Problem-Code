#include<iostream>
#include<stdio.h>

#define MAX_N 2000
#define MAX_M 500

char data[MAX_N][MAX_M + 1];
char PW[8];
int num[5][5][5];

//암호 스캔 규칙을 보면 암호코드는 0으로 시작할 수 없음!
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
	//PW[7]이 첫번째 암호코드 PW[0]이 마지막 검증코드이다.
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
		for (int j = m - 1; j >= 0; j--)	//배열은 0부터 m-1까지의 idx.
		{
			if (data[i][j] == '0')	//'0'일때는 계산할 필요X
				continue;

			if (data[i - 1][j] == '0')	//처음으로 암호코드가 등장하는 부분.
			{
				val = conv(data[i][j]);	//16진수로 표시된 문자를 10진수로 바꾸는 부분

				int cnt = 0;	//4bit씩 계산하기 위함.
				for (int idx = 0; idx < 8; idx++) 
				{
					int check[4] = { 0, };

					//0과 1의 개수를 세는 부분.
					//0101이 순서대로 나와야함. 몇 개 나올지는 상관 X. 세야함.
					for (int k = 0; k < 4; k++)
					{
						while ((val & 1) == (k & 1))	//(마지막 비트를 비교함.)
						{
							check[k]++;
							cnt++;
							val = val >> 1;

							if (cnt == 4) {	//한 char가 넘어간 것.
								cnt = 0;
								j--;
								val = conv(data[i][j]);
							}
						}
					}

					//암호규칙에 맞게 0 -> 1 -> 0 -> 1의 개수를 셌으면, 해당하는 암호(수)를 찾아 PW에 저장
					//PW[0]은 마지막 암호코드 (역순으로 저장된다, 뒤에서 부터 계산해 나가므로..)
					int min = findMin(check[1], check[2], check[3]);
					//몇 배수로 늘려 암호를 작성할 수도 있기에, 최소값으로 나누어 주면 최적의 암호 코드를 얻을 수 있다.
					if (min != 0) {	//min값은 무조건 1이상이 나오지만, 혹시 모를 상황을 대비해...
						PW[idx] = num[check[3] / min][check[2] / min][check[1] / min];
					}
				}
				if (isValid()) {	//값이 유효한가?
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