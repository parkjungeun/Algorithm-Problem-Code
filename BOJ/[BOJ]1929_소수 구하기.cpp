#include<iostream>
#define MAX_N 1000000
using namespace std;

int map[MAX_N];
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int N, M;
	cin >> M >> N;
	map[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = i * 2; j <= N; j += i)
			map[j] = 1;
	}

	for (int i = M; i <= N; ++i) {
		if (!map[i])	cout << i << '\n';
	}
	return 0;
}