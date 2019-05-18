#include<iostream>
#define MAX_N 31
using namespace std;

int N;
long long map[MAX_N][MAX_N];

long long solution(int W,int H) {
	if (map[W][H])
		return map[W][H];

	if (W == 0)
		return 1;

	if (W > 0)
		map[W][H] = solution(W - 1, H + 1);
	if (H > 0)
		map[W][H] += solution(W, H - 1);

	return map[W][H];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		cin >> N;
		if (N == 0)
			return 0;

		cout << solution(N, 0) << '\n';
	}
}