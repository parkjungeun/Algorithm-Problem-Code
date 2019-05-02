#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>

#define MAX_N 100  //(2 �� N �� 100)

int map1[MAX_N][MAX_N], map2[MAX_N][MAX_N];
int L;			//���� �غ��� ����  (1 �� L �� N)
int ans = 0, N;

void solution(int idx, int map[MAX_N][MAX_N]) {

	int n = map[idx][0];
	int use[MAX_N] = { 0, };

	for (int i = 0; i < N; ++i) {

		if (map[idx][i] == n)	//���� ������ ���� �Ѿ�� ��.
			continue;

		//���� ����� ���̰� 1���� ũ�� ���� ��ġ �Ұ���.
		if (abs(map[idx][i] - n) > 1)
			return;

		if (n < map[idx][i]) {	//������ ����� �� ���� ��, ���θ� ������ �������.
			if (i - L < 0)		//���θ� ���� ���� X
				return;

			//���δ� ���纸�� 1ĭ ���� ������� ��ġ�ؾ��ϹǷ� i-1
			for (int j = i - 1; j >= (i - L); --j) {
				//������ ���� ��ŭ�� ����� ����ϴ� ��,
				//�߰��� ���̰� �ٸ��ų� �̹� ���θ� ��ġ������ ����.
				if (map[idx][i] != map[idx][j] && use[j])
					return;
				use[j] = 1;	//���θ� ��ġ�� ���� ǥ��
			}

			n = map[idx][i];//������ ������� �ٽ� ���.
		}
		else if (n > map[idx][i]) {	//������ ����� �� ���� ��, ���θ� �ڷ� �������.
			if (i + L > N)			//���θ� ���� ���� X 
				return;

			//������ ��ġ���� ���θ� ������ ��.
			for (int j = i; j < i + L; ++j) {
				if (map[idx][i] != map[idx][j] || use[j])
					return;
				use[j] = 1;
			}

			if (i + L < N)
				n = map[idx][i + L - 1];	//���θ� ��ġ�� ���� �������� ���

			i = i + L - 1;
		}
	}
	ans++;
	return;
}

int main() {
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map1[i][j]);
			map2[j][i] = map1[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		solution(i, map1);	//row���
		solution(i, map2);	//col���
	}
	printf("%d", ans);

	return 0;
}