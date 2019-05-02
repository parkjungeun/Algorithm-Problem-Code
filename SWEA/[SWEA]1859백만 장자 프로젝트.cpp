#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

int N;	//일 수 2 ≤ N ≤ 1,000,000
stack<int> s;

long solution() {
	long curGain = 0;	//최대 이익(1,000,000 * 10,000) - 999,999
	int buyNum = 0;		//산 물건 개수
	int curPrice = 0;	//현재 기준 가격

	while(!s.empty()) {
		curPrice = s.top();
		s.pop();

		if (s.empty())	return curGain;
		
		if (curPrice < s.top())	continue;

		int temp = 0; buyNum = 0;
		while (!s.empty() && s.top() < curPrice) {
			buyNum++;
			temp += s.top();
			s.pop();
		}
		curGain += (buyNum*curPrice - temp);
	}

	return curGain;
}
	
int main() {
	int test, price;
	cin >> test;

	for (int i = 1; i <= test; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> price;
			s.push(price);
		}
		cout << '#' << i << ' ' << solution() << '\n';
	}
	return 0;
}