#include<stdio.h>
#define MAX_N 8

int arr[MAX_N], N, M;

void solution(int idx, int depth) {
	if (depth == M) {
		for (int i = 0; i < depth; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	for (int i = idx; i <= N; ++i) {
		arr[depth] = i;
		solution(i, depth + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	solution(1, 0);
	return 0;
}