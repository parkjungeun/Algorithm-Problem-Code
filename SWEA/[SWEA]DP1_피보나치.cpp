#include<stdio.h>
#include<memory.h>
int dp[100] = {};

int fibo(int n) {
	if (n >= 2 && dp[n] == -1)
		dp[n] = fibo(n - 1) + fibo(n - 2);
	return dp[n];
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1;
	printf("%d\n", fibo(10));
	return 0;
}