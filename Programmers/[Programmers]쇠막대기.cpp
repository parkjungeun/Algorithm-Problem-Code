#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string str) {
	int answer = 0;
	int len = str.length();
	stack<char> s;

	for (int i = 0; i < len; ++i) {
		if (str[i] == '(' && (i + 1 < len) && str[i + 1] == ')'){
			answer += s.size();
			++i;
		}
		else if (str[i] == '(')	s.push(str[i]);
		else if (str[i] == ')') { s.pop(); answer++; }
	}
	return answer;
}

int main() {
	cout << solution("(())(()()()()()())");
	return 0;
}