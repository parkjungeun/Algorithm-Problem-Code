#pragma warning(disable:4996)
#include<stdio.h>
#include<memory.h>
#define MAX_N 1000

int Num[MAX_N + 1];
int visited[MAX_N + 1];
int N;

int solution() {
	int ans = 0;

	for (int i = 1; i <= N; ++i) {
		if (visited[i])
			continue;

		int idx = i;
		while (1) {
			visited[idx] = 1;
			idx = Num[idx];
			if (visited[idx]) {
				ans++;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (int j = 1; j <= N; ++j)
			scanf("%d", &Num[j]);

		printf("%d\n", solution());
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}