#include<iostream>
#include<cstring>
#define MAX_N 13

int num[MAX_N], visit[MAX_N], tmp[MAX_N];
int N;
using namespace std;

void solution(int idx, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; ++i)
			cout << tmp[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; ++i) {
		if (!visit[i]) {
			visit[i] = 1;	tmp[depth] = num[i];
			solution(i + 1, depth + 1);
			visit[i] = 0;	tmp[depth] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (1) {
		cin >> N;
		if (N == 0)
			return 0;

		for (int i = 0; i < N; ++i)
			cin >> num[i];

		memset(tmp, 0, sizeof(tmp));
		solution(0, 0);		cout << '\n';
	}
}