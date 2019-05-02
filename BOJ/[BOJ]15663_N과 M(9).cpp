#include<iostream>
#include<algorithm>
#define MAX_N 9
using namespace std;

// check[MAX_N] : ���� depth���� �� ���ڸ� ����ߴ��� ���ߴ��� check
int arr[MAX_N], check[MAX_N], ans[MAX_N], N, M;

void solution(int idx, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int tmp = -1;	//���� depth�ȿ� ���̻� arr[i]�� ���� ���� ������ �ʵ��� �����ϴ� ����

	for (int i = 1; i <= N; ++i) {
		if (!check[i] && tmp != arr[i]) {
			tmp = arr[i]; 
			ans[depth] = arr[i];	check[i] = 1;
			solution(i, depth + 1); check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N + 1);	solution(1, 0);
	return 0;
}