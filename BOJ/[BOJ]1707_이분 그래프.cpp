//이분 그래프란?
//자신을 기준으로 자신과 연결되어 있는 노드들은 다른 color값을 갖는다.

#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 20001

using namespace std;
vector<int> map[MAX_N], visit;
int K, V, E;

bool bipartite() {
	for (int i = 1; i <= V; i++) {
		int color = visit[i];

		//연결된 요소와 같은 집합(color)을 갖는지 확인
		for (int j = 0; j < map[i].size(); j++) {
			if (color == visit[map[i][j]])
				return false;
		}
	}
	return true;
}

void solution(int n, int color) {
	for (int i = 0; i < map[n].size(); ++i) {
		//기존의 color와 다른 색으로 연결
		if (!visit[map[n][i]]) {
			visit[map[n][i]] = color*-1;
			solution(map[n][i], color*-1);
		}
	}
}

int main() {
	cin >> K;
	int n1, n2;

	for (int i = 0; i < K; ++i) {
		cin >> V >> E;

		for (int j = 0; j < E; ++j) {
			cin >> n1 >> n2;
			map[n1].push_back(n2);
			map[n2].push_back(n1);
		}

		visit = vector<int>(V + 1, 0);
		for (int j = 0; j <= V; ++j) {
			if (!map[j].size())		continue;

			//한번도 방문한 적 없을 때 값을 1로 설정
			if (!visit[j]) {
				visit[j] = 1;
				solution(j, 1);
			}
		}

		if (bipartite()) 	cout << "YES" << endl;
		else				cout << "NO" << endl;

		for (int i = 1; i <= V; i++)
			map[i].clear();
	}
	return 0;
}