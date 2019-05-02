#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

string num[10] = { "0001101","0011001","0010011","0111101","0100011",
				 "0110001","0101111","0111011","0110111","0001011" };

int solution(vector<char> str,int size)
{
	int idx = 7;
	int password[8] = { 0, };

	for (int i = size - 7; i >= 0; i--)
	{
		string s = "";
		for (int j = i; j < i + 7; j++) {
			s += str[j];
		}

		for (int j = 0; j < 10; j++) {
 			if (s == num[j]) {
				password[idx] = j;
				idx--;
				i -= 6;
				break;
			}
		}

		if (idx == -1)
			break;
	}

	int even_sum = password[0] + password[2] + password[4] + password[6];
	int odd_sum = password[1] + password[3] + password[5];
	
	int res = even_sum * 3 + odd_sum + password[7];
	if (res % 10 == 0) {
		return even_sum + odd_sum + password[7];
	}
	else
		return 0;
}

int main()
{
	int N, M;	//N : 배열의 세로크기, M : 배열의 가로크기

	int test, res = 0;
	cin >> test;
	for (int testcase = 1; testcase <= test; testcase++)
	{
		cin >> N >> M;
		int ans = 0;
		res = 0;

		for (int j = 0; j < N; j++)
		{
			vector<char> str(M);


			for (int i = 0; i < M; i++) {
				cin >> str[i];
			}

			res = solution(str, M);
			if (res != 0) {
				ans = res;
			}
			str.clear();
		}
		cout << '#' << testcase << ' ' << ans << endl;
	}
}