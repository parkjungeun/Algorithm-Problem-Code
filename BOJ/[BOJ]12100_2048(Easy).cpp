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
	//j (행 또는 열)에 대해서 블록 값을 저장하고 합치기.
	for (int j = 0; j < N; ++j) {
		//방향이 세로(상,하)인 경우 행과 열을 뒤집음 
		//방향이 1(우)또는 3(하)인경우 순서를 뒤집음
		vector<int> v;
		for (int p = 0; p < N; ++p) {
			//0이 아닌 원소를 v에 저장
			if ((i < 2 ? map[j][p] : map[p][j]) != 0)
				v.push_back(i < 2 ? map[j][p] : map[p][j]);
		}

		//우, 하 방향일 때는 뒤집기
		if (i == 1 || i == 3)
			reverse(v.begin(), v.end());

		vector<int> perm;
		for (int p = 0; p < v.size(); ++p) {
			//다음 숫자랑 같으면? 합쳐야 함.
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

		//다음 상태 공간에 저장
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

	//좌,우,상,하 순서
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