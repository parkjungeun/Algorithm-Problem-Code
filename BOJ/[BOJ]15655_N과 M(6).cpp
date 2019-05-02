#include<iostream>
#include<algorithm>
#define MAX_N 9

using namespace std;

int arr[MAX_N], visit[MAX_N], ans[MAX_N], N, M;

void solution(int idx, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; ++i) {
		if (!visit[i]) {
			ans[depth] = arr[i];
			visit[i] = 1;
			solution(i + 1, depth + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + N + 1);
	solution(1,0);
	return 0;
}