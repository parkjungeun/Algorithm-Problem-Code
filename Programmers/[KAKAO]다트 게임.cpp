#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string dartResult) {
	int answer = 0, len = dartResult.size(), num = 0;

	stack<int> s;
	for (int i = 0; i < len; ++i) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			num = dartResult[i] - '0';
			if (dartResult[i + 1] == '0') {
				s.push(num * 10); ++i;
			}
			else	s.push(num);
			continue;
		}

		num = s.top(); s.pop();
		switch (dartResult[i]) {	
		case 'S': s.push(num); break;
		case 'D': s.push(num*num);	break;
		case 'T': s.push(num*num*num);	break;
		}
		
		int n1 = 0, n2 = 0;
		if (dartResult[i + 1] == '*' || dartResult[i + 1] == '#') {
			n1 = s.top(); s.pop();
			switch (dartResult[++i]) {
			case '*':
				if (s.empty()) {
					s.push(n1 * 2);
				}
				else {
					n2 = s.top(); s.pop();
					s.push(n2 * 2); s.push(n1 * 2);
				}
				break;
			case '#':	s.push(-n1);
				break;
			}
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
	return sum;
}

int main() {
	solution("1D2S#10S");
}