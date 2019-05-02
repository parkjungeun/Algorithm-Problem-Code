#include<stdio.h>
#define MAX_N 7

int arr[MAX_N], N, M;

void solution(int depth) {
	if (depth == M) {
		for (int i = 0; i < depth; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; ++i) {
		arr[depth] = i;
		solution(depth + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	solution(0);
	return 0;
}
