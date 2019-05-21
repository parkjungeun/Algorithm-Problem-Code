//[Programmers_KAKAO]n진수 게임
#include <string>
#include <algorithm>
using namespace std;
char ch[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string changenum(int num, int n) {
	string tmp = "";

	if (num == 0)
		return "0";

	while (num != 0) {
		tmp += ch[num % n];
		num /= n;
	}
	reverse(tmp.begin(), tmp.end());
	return tmp;
}

string solution(int n, int t, int m, int p) {
	string answer = "", s = "";
	int i = 0;

	p--;
	while (answer.size() != t) {
		s += changenum(i, n);
		++i;

		if (s.size() > p) {
			answer += s[p];   p += m;
		}
	}
	return answer;
}