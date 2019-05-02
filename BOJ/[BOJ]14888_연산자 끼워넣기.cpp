#include <iostream>
#define MAX_N 11

using namespace std;
int minAns = 2e9, maxAns = -2e9;
int N, num[MAX_N], op[4];
int arr[MAX_N - 1];	//사용된 연산자의 순서를 담는 배열

void solution(int depth) {
	if (depth == N - 1) {
		int sum = num[0];

		for (int i = 1; i < N; ++i) {
			switch (arr[i - 1]) {
			case 0: sum += num[i];		break;
			case 1: sum -= num[i];		break;
			case 2: sum *= num[i];		break;
			case 3: sum /= num[i];		break;
			}
		}
		if (minAns > sum)	minAns = sum;
		if (maxAns < sum)	maxAns = sum;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int n = op[i];
		for (int j = 0; j < n; ++j) {
			arr[depth] = i;
			op[i]--;
			solution(depth + 1);
			op[i]++;
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];

	for (int i = 0; i < 4; ++i)
		cin >> op[i];

	solution(0);	cout << maxAns << '\n' << minAns;
	return 0;
}