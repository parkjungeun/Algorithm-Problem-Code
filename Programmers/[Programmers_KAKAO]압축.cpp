#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int countNum = 1;
unordered_map<string, int> map;

void init() {
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		string tmp = "";
		tmp += ch;
		map[tmp] = countNum++;
	}
	return;
}

vector<int> solution(string msg) {
	vector<int> answer;
	string tmp = "";
	init();

	int w = 0, len = msg.length();

	for (int i = 0; i < len; ++i) {
		tmp += msg[i];
		if (map[tmp] != 0) {
			w = map[tmp];
		}
		else if (map[tmp] == 0) {
			answer.push_back(w);
			map[tmp] = countNum++;
			tmp = "";	i--;
		}
	}

	if (tmp != "") {
		if (map[tmp] == 0)	answer.push_back(countNum);
		else	answer.push_back(map[tmp]);
	}

	return answer;
}

int main() {
	solution("KAKAO");
	return 0;
}