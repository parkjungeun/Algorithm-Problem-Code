#pragma warning(disable:4996)
#include<stdio.h>
#include<queue>
#define MAX_N 100001
using namespace std;
int visit[MAX_N];
int N, K;

void solution() {

	if (N == K) {
		printf("0");	return;
	}

	queue<pair<int,int> > Q;
	Q.push(make_pair(0, N));

	while (!Q.empty()) {
		int x = Q.front().second;
		int cnt = Q.front().first;
		//printf("%d %d\n", x, cnt);
		Q.pop();

		if (x == K) {
			printf("%d", cnt);
			return;
		}

		if (x - 1 >= 0 && !visit[x - 1]) {
			Q.push(make_pair(cnt + 1, x - 1));
			visit[x - 1] = 1;
		}
		if (x + 1 <= MAX_N && !visit[x + 1]) {
			Q.push(make_pair(cnt + 1, x + 1));
			visit[x + 1] = 1;
		}
		if (2 * x <= MAX_N && !visit[2 * x]) {
			Q.push(make_pair(cnt + 1, 2 * x));
			visit[2 * x] = 1;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	solution();
	return 0;
}