//�̺� �׷�����?
//�ڽ��� �������� �ڽŰ� ����Ǿ� �ִ� ������ �ٸ� color���� ���´�.

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

		//����� ��ҿ� ���� ����(color)�� ������ Ȯ��
		for (int j = 0; j < map[i].size(); j++) {
			if (color == visit[map[i][j]])
				return false;
		}
	}
	return true;
}

void solution(int n, int color) {
	for (int i = 0; i < map[n].size(); ++i) {
		//������ color�� �ٸ� ������ ����
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

			//�ѹ��� �湮�� �� ���� �� ���� 1�� ����
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