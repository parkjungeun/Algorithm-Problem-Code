#include<iostream>
#include<vector>

using namespace std;

int solution(int len, vector<vector<char> > ch) 
{
	int ans = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - len; j++) {
			int same = 0, idx = 0;
			
			while (1) {
				if (ch[i][j + idx] == ch[i][j + len - idx - 1])
					same++;
				else
					break;

				idx++;
				if (same == len / 2) {
					ans++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - len; j++) {
			int same = 0, idx = 0;

			while (1) {
				if (ch[j + idx][i] == ch[j + len - idx - 1][i])
					same++;
				else
					break;

				idx++;
				if (same == len / 2) {
					ans++;
					break;
				}
			}
		}
	}
	return ans;
}


int main() {
	int len = 0;
	vector<vector<char> > ch(8, vector<char>(8, ' '));

	for (int _test = 1; _test <= 10; _test++) {
		cin >> len;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				cin >> ch[i][j];
		}

		cout << '#' << _test << ' ' << solution(len, ch) << endl;
	}
	return 0;
}