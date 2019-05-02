#include<iostream>
#include<algorithm>
#define MAX_N 50
using namespace std;

char map[MAX_N][MAX_N];
int M, N;

int solution(int r, int c) {
	char ch = map[r][c];
	int tmp1 = 0, tmp2 = 0;

	for (int i = r; i < r + 8; i += 2) {
		for (int j = c; j < c + 8; j += 2) {
			if (ch != map[i][j])	tmp1++;
		}
	}
	for (int i = r + 1; i < r + 8; i += 2) {
		for (int j = c + 1; j < c + 8; j += 2) {
			if (ch != map[i][j])	tmp1++;
		}
	}

	ch = (map[r][c] == 'B') ? 'W' : 'B';

	for (int i = r; i < r + 8; i += 2) {
		for (int j = c + 1; j < c + 8; j += 2) {
			if (ch != map[i][j])	tmp2++;
		}
	}
	for (int i = r + 1; i < r + 8; i += 2) {
		for (int j = c; j < c + 8; j += 2) {
			if (ch != map[i][j])	tmp2++;
		}
	}

	//����, ó�� �����ڸ��� �ٲٸ� �Ǵ� ��쿡��
	//�� ó�� 1���� �ٲٸ� �Ǵµ� ���� 63�� ����...
	//����, ���� �ٲ���ϴ� ������ (��ü - ���� �ٲ���ϴ� ����)��
	//���ؼ� �� ���� ���� ������ �� ��ȯ�ϸ� ��.
	return min(tmp1 + tmp2, 64 - (tmp1 + tmp2));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;

	for (int r = 0; r < M; ++r) {
		for (int c = 0; c < N; ++c)
			cin >> map[r][c];
	}

	int ans = 999999;
	for (int r = 0; r <= M - 8; ++r) {
		for (int c = 0; c <= N - 8; ++c) {
			ans = min(ans, solution(r, c));
		}
	}
	cout << ans;
	return 0;
}