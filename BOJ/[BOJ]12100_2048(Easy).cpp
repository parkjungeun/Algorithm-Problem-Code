#include<stdio.h>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 20

using namespace std;
int map[MAX_N][MAX_N];
int N, maxAns = 0;

void moveMap(int i) {
	//j (�� �Ǵ� ��)�� ���ؼ� ��� ���� �����ϰ� ��ġ��.
	for (int j = 0; j < N; ++j) {
		//������ ����(��,��)�� ��� ��� ���� ������ 
		//������ 1(��)�Ǵ� 3(��)�ΰ�� ������ ������
		vector<int> v;
		for (int p = 0; p < N; ++p) {
			//0�� �ƴ� ���Ҹ� v�� ����
			if ((i < 2 ? map[j][p] : map[p][j]) != 0)
				v.push_back(i < 2 ? map[j][p] : map[p][j]);
		}

		//��, �� ������ ���� ������
		if (i == 1 || i == 3)
			reverse(v.begin(), v.end());

		vector<int> perm;
		for (int p = 0; p < v.size(); ++p) {
			//���� ���ڶ� ������? ���ľ� ��.
			if (p + 1 < v.size() && v[p] == v[p + 1]) {
				perm.push_back(v[p] * 2);
				++p;
			}
			else	perm.push_back(v[p]);
		}

		for (int p = perm.size(); p < N; ++p)
			perm.push_back(0);

		if (i == 1 || i == 3)
			reverse(perm.begin(), perm.end());

		//���� ���� ������ ����
		for (int p = 0; p < N; ++p)
			(i < 2 ? map[j][p] : map[p][j]) = perm[p];
	}
}

void solution(int depth) {
	if (depth == 5) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (maxAns < map[i][j])
					maxAns = map[i][j];
			}
		}
		return;
	}

	//��,��,��,�� ����
	int temp[MAX_N][MAX_N];
	for (int i = 0; i < 4; ++i) {
		memcpy(temp, map, sizeof(map));
		moveMap(i);  solution(depth + 1);
		memcpy(map, temp, sizeof(temp));
	}
}

int main() {
	scanf("%d", &N);
	
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c)
			scanf("%d", &map[r][c]);
	}

	solution(0);
	printf("%d", maxAns);
	return 0;
}