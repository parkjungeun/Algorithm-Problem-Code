#include<iostream>
#include<algorithm>
using namespace std;

int solution(int N) {
	int five = 0, three = 0;

	if (N % 5 == 0)
		return N / 5;

	five = N / 5; N %= 5;
	while (five >= 0) {
		if (N % 3 == 0) {
			three = N / 3;
			N %= 3;
			break;
		}
		five--; N += 5;
	}
	return (N == 0) ? five + three : -1;
}

int main() {
	int N;
	cin >> N;
	cout << solution(N);
	return 0;
}