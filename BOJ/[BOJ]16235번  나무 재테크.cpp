//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<queue>
//#define MAX_N 11
//using namespace std;
//
//struct info {
//	int r, c, age;
//};
//int map[MAX_N][MAX_N], energy[MAX_N][MAX_N], M, N, K;
//int dx[8] = { 0,0,-1,1,-1,1,-1,1 }, dy[8] = { -1,1,0,0,-1,-1,1,1 };
//vector<int> trees[MAX_N][MAX_N];
//queue<info> alive, death;
//
////������ ��� ���
//void spring() {
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= N; ++j) {
//			int sz = trees[i][j].size();
//			if (sz == 0)
//				continue;
//
//			vector<int> v;
//			for (int k = 0; k < sz; ++k) {
//				int t = trees[i][j][k];
//
//				if (map[i][j] < t) {
//					death.push({ i,j,t });
//				}
//				else {
//					map[i][j] -= t;
//					v.push_back(trees[i][j][k] + 1);
//					alive.push({ i,j,t + 1 });
//				}
//			}
//			trees[i][j].clear();	trees[i][j] = v;
//		}
//	}
//}
//
////���� �����鿡 ���� ��� ���ϱ�
//void summer() {
//	while (!death.empty()) {
//		int r = death.front().r;
//		int c = death.front().c;
//		int age = death.front().age;
//		death.pop();
//		
//		map[r][c] += (age / 2);
//	}
//}
//
////����ִ� ������ �� ���̰� 5�� ����� ������ �ֺ��� ����(���� : 1)�ɱ�
//void fall() {
//	while(!alive.empty()) {
//		int r = alive.front().r;
//		int c = alive.front().c;
//		int age = alive.front().age;
//		alive.pop();
//
//		if (age % 5 == 0) {
//			for (int idx = 0; idx < 8; ++idx) {
//				int ny = r + dy[idx], nx = c + dx[idx];
//				if (ny<1 || ny>N || nx<1 || nx>N)
//					continue;
//				trees[ny][nx].insert(trees[ny][nx].begin(), 1);
//			}
//		}
//	}
//}
//
////S2D2�� ��� ���ϱ�
//void winter() {
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= N; ++j)
//			map[i][j] += energy[i][j];
//	}
//}
//
////����ִ� ������ ���� ����
//int countTreeNum() {
//	int cnt = 0;
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= N; ++j) {
//			cnt += trees[i][j].size();
//		}
//	}
//	return cnt;
//}
//
//int solution(int year) {
//	int y = 0;
//	while (y != year) {
//		spring();
//		summer();
//		fall();
//		winter();
//		++y;
//	}
//
//	return countTreeNum();
//}
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> M >> K;
//
//	//map : ó�� �ִ� ����� ��
//	//energy : �ų� �߰��� ����� ��
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= N; ++j) {
//			cin >> energy[i][j];
//			map[i][j] = 5;
//		}
//	}
//
//	int x, y, z;
//	for (int i = 0; i < M; ++i) {
//		cin >> x >> y >> z;
//		trees[x][y].push_back(z);
//	}
//
//	cout << solution(K);
//	return 0;
//}
#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 11
using namespace std;

struct info { int r, c, age; };
int map[MAX_N][MAX_N], energy[MAX_N][MAX_N], M, N, K;
int dx[8] = { 0,0,-1,1,-1,1,-1,1 }, dy[8] = { -1,1,0,0,-1,-1,1,1 };
vector<int> trees[MAX_N][MAX_N];
queue<info> alive;

//������ ��� ���
void spring_summer() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int sz = trees[i][j].size();
			if (sz == 0)
				continue;

			vector<int> v;    int death = 0;
			for (int k = 0; k < sz; ++k) {
				int t = trees[i][j][k];

				if (map[i][j] < t) {
					death += (t/2);
				}
				else {
					map[i][j] -= t;
					v.push_back(trees[i][j][k] + 1);
					alive.push({ i,j,t + 1 });
				}
			}
			map[i][j] += death;
			trees[i][j].clear();	trees[i][j] = v;
		}
	}
}

//����ִ� ������ �� ���̰� 5�� ����� ������ �ֺ��� ����(���� : 1)�ɱ�
void fall() {
	while (!alive.empty()) {
		int r = alive.front().r;
		int c = alive.front().c;
		int age = alive.front().age;
		alive.pop();

		if (age % 5 == 0) {
			for (int idx = 0; idx < 8; ++idx) {
				int ny = r + dy[idx], nx = c + dx[idx];
				if (ny<1 || ny>N || nx<1 || nx>N)
					continue;
				trees[ny][nx].insert(trees[ny][nx].begin(), 1);
			}
		}
	}
}

int solution(int year) {
	int y = 0;
	while (y != year) {
		spring_summer();	fall();

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j)
				map[i][j] += energy[i][j];
		}
		++y;
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cnt += trees[i][j].size();
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> energy[i][j];
			map[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; ++i) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	cout << solution(K);
	return 0;
}