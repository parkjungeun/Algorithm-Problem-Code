#include<iostream>
#include<queue>
#define MAX_F 1000001

using namespace std;

int F, S, G, U, D, visit[MAX_F];

void solution() {
	queue<pair<int,int> > Q;
	Q.push(make_pair(S, 0));
	visit[S] = 1;

	while (!Q.empty()) {
		int cur = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (cur == G) {
			printf("%d", cnt);
			return;
		}
		if (cur + U <= MAX_F && !visit[cur + U]) {
			Q.push(make_pair(cur + U, cnt + 1));
			visit[cur + U] = 1;
		}
		if (cur - D >= 0 && !visit[cur - D]) {
			Q.push(make_pair(cur - D, cnt + 1));
			visit[cur - D] = 1;
		}
	}
	printf("use the stairs");
	return;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	solution();
	return 0;
}