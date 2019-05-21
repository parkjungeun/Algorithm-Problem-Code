//[Programmers_KAKAO]파일명 정렬
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct INFO {
	string realHead, head;
	string realNum;
	int number;
	string tail;
	int turn;
};

vector<INFO> v;
int cur = 0;

void doParsing(string file) {
	int sz = file.size(), numFlag = 0;
	INFO info;
	string tmp = "";
	for (int i = 0; i<sz; ++i) {
		if (numFlag == 0) {
			tmp += file[i];

			if (file[i + 1] >= '0' && file[i + 1] <= '9') {
				info.realHead = tmp;
				string s = "";

				for (int j = 0; j<tmp.size(); ++j)
					s += (tmp[j] >= 'a'&&tmp[j] <= 'z') ? tmp[j] - 'a' + 'A' : tmp[j];

				info.head = s;
				numFlag++; tmp = "";
			}
		}
		else if (numFlag == 1 && (file[i] >= '0' && file[i] <= '9')) {
			tmp += file[i];
			if (i + 1 >= sz || file[i + 1]<'0' || file[i + 1]>'9') {
				info.realNum = tmp;
				info.number = stoi(tmp);
				numFlag++;    tmp = "";
			}
		}
		else    tmp += file[i];
	}

	info.tail = tmp;
	info.turn = cur++;
	v.push_back(info);
	return;
}

//처음에 head순 -> 숫자
void doSort() {
	int sz = v.size();
	for (int i = 0; i<sz - 1; ++i) {
		for (int j = i + 1; j<sz; ++j) {
			int res = v[i].head.compare(v[j].head);
			if (res > 0 || (res == 0 && (v[i].number > v[j].number)) ||
				(res == 0 && (v[i].number == v[j].number) && (v[i].turn > v[j].turn))) {
				INFO tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	int sz = files.size();

	for (int i = 0; i < sz; ++i)
		doParsing(files[i]);

	doSort();

	for (int i = 0; i<v.size(); ++i) {
		string s = (v[i].realHead + v[i].realNum + v[i].tail);
		cout << s << '\n';
		answer.push_back(s);
	}
	return answer;
}