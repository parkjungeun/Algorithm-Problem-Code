#include<iostream>
using namespace std;

int solution(int res) {
	int bar = 64, cnt = 1, x = 64;
	
	while (bar != res) {
		x /= 2;
		cnt++;

		if (bar - x >= res) {
			bar -= x;	cnt--;
		}
	}
	return cnt;
}

int main() {
	int a;
	cin >> a;
	cout << solution(a);
	return 0;
}