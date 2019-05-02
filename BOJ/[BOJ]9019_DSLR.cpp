#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#define MAX_N 10000
using namespace std;
struct INFO {
	int n, cnt;
	string str = "";
};

void solution(int a, int b) {
	bool visit[MAX_N];	memset(visit, false, sizeof(visit));
	queue<INFO> Q;	Q.push({ a,0,"" });

	while (!Q.empty()) {
		int curNum = Q.front().n;
		int cnt = Q.front().cnt;
		string str = Q.front().str;
		Q.pop();

		if (curNum == b) {
			cout << str << '\n';	return;
		}

		//D연산
		if ((2 * curNum < MAX_N) && !visit[2 * curNum]) {
			Q.push({ 2 * curNum,cnt + 1,str + "D" });
			visit[2 * curNum] = 1;
		}
		else if (!visit[(2 * curNum) % MAX_N]){
			Q.push({ (2 * curNum) % MAX_N,cnt + 1,str + "D" });
			visit[(2 * curNum) % MAX_N] = 1;
		}

		//S연산
		if ((curNum - 1 < 0) && !visit[MAX_N + (curNum - 1)]) {
			Q.push({ MAX_N + (curNum - 1),cnt + 1,str + "S" });
			visit[MAX_N + (curNum - 1)] = 1;
		}
		else if (curNum - 1 >= 0 && !visit[curNum - 1]) {
			Q.push({ curNum - 1,cnt + 1,str + "S" });
			visit[curNum - 1] = 1;
		}

		//L연산
		if (!visit[(curNum % 1000) * 10 + curNum / 1000]) {
			Q.push({ (curNum % 1000) * 10 + curNum / 1000,cnt + 1,str + "L" });
			visit[(curNum % 1000) * 10 + curNum / 1000] = 1;
		}

		//R연산
		if (!visit[(curNum % 10) * 1000 + curNum / 10]) {
			Q.push({ (curNum % 10) * 1000 + curNum / 10,cnt + 1,str + "R" });
			visit[(curNum % 10) * 1000 + curNum / 10] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;

	int a, b;
	for (int i = 0; i < T; ++i) {
		cin >> a >> b;
		solution(a, b);
	}
	return 0;
}