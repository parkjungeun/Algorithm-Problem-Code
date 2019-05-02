#include <string>
#include <vector>
#include<sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	stringstream ss(s);

	string temp ;
	vector<int> num;
	while (ss >> temp)
		num.push_back(stoi(temp));
	
	sort(num.begin(), num.end());

	answer += (to_string(num[0]) + ' ' + to_string(num[num.size() - 1]));
	return answer;
}

string solution(string s) {
	string answer = "";
	string min = "", max = "";

	int minNum = 2e9, maxNum = -2e9, i = 0;
	int len = s.length();
	while (i < len) {
		int flag = 0, ans = 0;
		string temp = "";

		if (s[i] == ' ') {
			++i;
			continue;
		}

		while (s[i] != ' ' && i < len) {
			if (s[i] == '-')
				flag = 1;
			else {
				if (ans != 0)
					ans *= 10;
				ans += (s[i] - '0');
			}
			temp += s[i];
			++i;
		}

		if (flag == 1)
			ans *= -1;

		if (minNum >= ans) {
			minNum = ans;
			min = temp;
		}
		if (maxNum <= ans) {
			maxNum = ans;
			max = temp;
		}
	}
	answer += (min + ' ' + max);
	return answer;
}