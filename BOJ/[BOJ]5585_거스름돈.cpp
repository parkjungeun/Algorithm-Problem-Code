//https://www.acmicpc.net/problem/5585
#include<iostream>
using namespace std;

//500엔, 100엔, 50엔, 10엔, 5엔, 1엔의 개수
int Money[6] = { 500,100,50,10,5,1 };
int ans = 0;

void solution(int last, int cnt) {
	if (last < 0)
		return;
	if (last == 0) {
		ans = cnt;
		return;
	}

	for (int i = 0; i < 6; ++i) {
		solution(last - Money[i], cnt + 1);
		if (ans)
			return;
	}
}

int main() {
	int N;
	cin >> N;

	solution(1000 - N, 0);
	cout << ans;
	return 0;
}