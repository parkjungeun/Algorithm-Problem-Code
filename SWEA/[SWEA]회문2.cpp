#include<iostream>
#include<vector>

using namespace std;

int check(vector<char> ch)
{
	int idx = 0, same = 0;
	int len = ch.size();	//체크해야할 회문 길이

	while (1) {
		if (len == 0)
			return len;

		for (int i = 0; i <= -1 * (len - ch.size()); i++)
		{
			same = 0;	idx = i + len;
			for (int j = i; j < (i + len); j++) {
				if (ch[j] == ch[--idx]) {
					same++; 
				}
				else
					break;

				if (same == len / 2)
					return len;
			}
		}
		len--;
	}
}

int solution(vector<vector<char> > ch)
{
	int len;
	int max_len = 0;

	//행에서의 최대길이 계산
	for (int i = 0; i < ch.size(); i++) {
		len = check(ch[i]);
		if (max_len < len)
				max_len = len;
	}

	//열에서의 최대길이 계산
	for (int i = 0; i < ch.size(); i++) {
		vector<char> temp(ch.size());
		for (int j = 0; j < ch.size(); j++)
			temp[j] = ch[j][i];

		len = check(temp);
		if (max_len < len)
			max_len = len;
	}
	return max_len;
}


int main() {
	int test = 0;
	vector<vector<char> > ch(100, vector<char>(100, ' '));
	
	for (int i = 1; i <= 10; i++) {
		cin >> test;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				cin >> ch[i][j];
		}

		cout << '#' << test << ' ' << solution(ch) << endl;
	}
	return 0;
}