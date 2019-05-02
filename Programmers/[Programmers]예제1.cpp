#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(string s) {
	vector<int> num;
	vector<char> c;
	char ch;

	int len = s.length();
	if (s[0] == '(')
		num.push_back(1);

	for (int i = 0; i < len; ++i) {
		string str = "";
		
		if (s[i] == '(' || s[i] == ')')
			continue;
		
		while (s[i] >= '0'&&s[i] <= '9' && i<len) {
			str += s[i];
			++i;
		}
		num.push_back(stoi(str));
		
		if (s[i] >= 'a'&&s[i] <= 'z' && i < len) {
			ch = s[i];
			c.push_back(ch);
		}
	}

	string ans = "";
	
	for (int i = 1; i < num.size(); ++i) {
		//ans += to_string(num[i]);
		for (int j = 0; j < num[i]; ++j)
			ans += c[i - 1];
	}

	for (int i = 0; i < num[0];++i) {
		cout << ans;
	}
}

int main()
{
	solution("(3a3b)");
	return 0;
}