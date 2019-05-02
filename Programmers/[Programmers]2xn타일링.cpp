#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int dp[600001] = { 0, };

	dp[1] = 1;	//세로로 세울 때,
	dp[2] = 2;	//가로로 세울 때,

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;

	answer = dp[n];
	return answer;
}

int main() {
	printf("%d\n", solution(4));
	printf("%d\n", solution(100000));
	return 0;
}