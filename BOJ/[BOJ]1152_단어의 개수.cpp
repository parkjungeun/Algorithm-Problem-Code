#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//规过 1. 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str;
	getline(cin, str);

	int cnt = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ')	continue;

		bool flag = 0;
		while (str[i] != ' ') {
			if(!flag)
				flag = 1;
			if (i + 1 > str.size())
				break;
			++i;
		}

		if (flag)	cnt++;
	}
	cout << cnt;
	return 0;
}

//规过2
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	string str, tmp;
//	int cnt = 0;
//	getline(cin, str);
//	stringstream ss(str);
//	while (ss >> tmp)	cnt++;
//	cout << cnt;
//	return 0;
//}

