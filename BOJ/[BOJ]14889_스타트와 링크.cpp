//https://www.acmicpc.net/problem/14889
#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define MAX_N 21
using namespace std;

int map[MAX_N][MAX_N], visit[MAX_N], N;
int minDiff = 999999, flag = 0;

int calcDiff() {
	int start_power = 0, link_power = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (visit[i] == 0 && visit[j] == 0)
				start_power += (map[i][j] + map[j][i]);
			if (visit[i] == 1 && visit[j] == 1)
				link_power += (map[i][j] + map[j][i]);
		}
	}

	int diff = start_power - link_power;
	diff = (diff < 0) ? -diff : diff;

	return diff;
}

void solution(int n, int peopleNum) {
	if (peopleNum == (N / 2)) {
		int diff = calcDiff();

		if (minDiff > diff)
			minDiff = diff;

		if (minDiff == 0)
			flag = 1;
		return;
	}

	for (int i = n; i <= N; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			solution(i + 1, peopleNum + 1);
			visit[i] = 0;
		}
		if (flag)	return;
	}
}

int main() {
	scanf("%d", &N);

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c)
			scanf("%d", &map[r][c]);
	}

	solution(0, 0);	printf("%d", minDiff);
	return 0;
}