#include<iostream>
#include<algorithm>
#define MAX_N 100001
using namespace std;
int A[MAX_N], B, N, M;

//이분 탐색은 정렬된 데이터에서만 가능!
int solution(int B, int left, int right) {
	int r = right;
	int l = left;
	int mid;

	while (l <= r) {
		mid = (l + r) / 2;

		if (B == A[mid])
			return 1;
		else if (B > A[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> B;

		if (solution(B, 0, N - 1))
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}
	return 0;
}