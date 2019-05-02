#include<stdio.h>
#define MAX_N 9
using namespace std;

int arr[MAX_N];
int N, M, visit[MAX_N];

void solution(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) {
			arr[depth] = i;
			visit[i] = 1;
			solution(depth + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	solution(0);
	return 0;
}