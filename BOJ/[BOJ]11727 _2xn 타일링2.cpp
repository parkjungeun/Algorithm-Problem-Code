#pragma warning(disable:4996)
#include<stdio.h>

void solution(int n) {
	int dp[1001] = { 0, };
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i)
		dp[i] = ((dp[i - 2] * 2) * dp[i-1]) % 10007;
	printf("%d", dp[n]);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	solution(n);
	return 0;
}