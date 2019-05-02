#include<iostream>
#include<cstring>
#define MAX_N 1000001
using namespace std;
bool map[MAX_N];

void init() {
	memset(map, true, sizeof(map));
	for (int i = 2; i < MAX_N; ++i) {
		if (map[i] == false)	continue;

		for (int j = i * i; j < MAX_N; j += i) {
			if (map[j] == false)	continue;
			else map[j] = false;
		}
	}
}

void solution(int N) {
	//홀수들의 합이므로 +2씩 해주기!
	for (int i = 3; i <= N; i += 2) {
		if (map[i] && map[N - i]) {
			cout << N << " = " << i << " + " << N - i << '\n';
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; init();
	while (1) {
		cin >> N;
		if (N == 0)		return 0;
		solution(N);
	}
}