#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> words) {
	int answer = 0, sz = words.size();

	sort(words.begin(), words.end());

	for (int i = 0; i < sz; ++i) {
		int cnt1 = 0, cnt2 = 0, len1 = words[i].length();
		//앞 확인
		if (i - 1 >= 0) {
			//더 짧은 길이 저장
			int len2 = words[i - 1].length();
			int len = len1 < len2 ? len1 : len2;

			for (int j = 0; j < len; ++j) {
				if (words[i][j] == words[i - 1][j])
					cnt1++;
			}
		}
		//뒤 확인
		if (i + 1 < sz) {
			//더 짧은 길이 저장
			int len2 = words[i + 1].length();
			int len = len1 < len2 ? len1 : len2;

			for (int j = 0; j < len; ++j) {
				if (words[i][j] == words[i + 1][j])
					cnt2++;
			}
		}

		int res = (cnt1 < cnt2) ? cnt2 : cnt1;
		if (res == 0)
			res = 1;
		else if (res < len1)
			res++;

		cout << words[i] << " : " << cnt1 << ", " << cnt2 << ", " << res << '\n';
		answer += res;
	}
	return answer;
}