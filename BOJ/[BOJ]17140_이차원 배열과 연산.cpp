#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX_N 101
using namespace std;
struct INFO {
	int num, cnt;
};

int map[MAX_N][MAX_N], R_Len = 3, C_Len = 3;
int r, c, k;	// 1 ≤ r, c, k ≤ 100
int ansTime = 0;

void showMap() {
	printf("ansTime : %d, R_Len : %d, C_Len : %d\n", ansTime, R_Len, C_Len);
	for (int i = 1; i <= R_Len; ++i) {
		for (int j = 1; j <= C_Len; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

//나온 개수 -> 숫자 오름차순으로 정렬
bool cmp(INFO& a, INFO& b) {
	if (a.cnt >= b.cnt) {
		if (a.cnt == b.cnt) {
			if (a.num < b.num)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	return true;
}

//1 : R연산 / 2: C연산
int mapCalc(int op) {
	int len, sub;
	if (op == 1){ 
		len = R_Len;	sub = C_Len; 
	}
	else { 
		len = C_Len; sub = R_Len;
	}

	int visit[MAX_N], tmp[MAX_N][MAX_N] = { 0, }, maxLen = 0;;
	vector<INFO> v;
	memset(tmp, 0, sizeof(tmp));

	for (int i = 1; i <= len; ++i) {
		memset(visit, 0, sizeof(visit));	v.clear();
		
		for (int j = 1; j <= sub; ++j) {
			int n = op == 1 ? map[i][j] : map[j][i];
			
			if (!visit[n] && n != 0) {
				visit[n] = 1;
				v.push_back({ n,1 });
			}
			else 
				visit[n]++;
		}

		int sz = v.size();
		if (maxLen < sz * 2)
			maxLen = sz * 2;
		
		for (int i = 0; i < sz; ++i)
			v[i].cnt = visit[v[i].num];
		
		sort(v.begin(), v.end(), cmp);
		
		for (int j = 0; j < sz; j++) {
			(op == 1 ? tmp[i][1 + j * 2] : tmp[1 + j * 2][i]) = v[j].num;
			(op == 1 ? tmp[i][1 + j * 2 + 1] : tmp[1 + j * 2 + 1][i]) = v[j].cnt;
		}
	}

	memcpy(map, tmp, sizeof(tmp));
	return maxLen;
}

int solution() {
	while (map[r][c] != k) {
		if (ansTime > 100)
			return -1;

		if (R_Len >= C_Len)	//R연산
			C_Len = mapCalc(1);
		else	//C연산
			R_Len = mapCalc(2);

		ansTime++;
	}
	return ansTime;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j)
			scanf("%d", &map[i][j]);
	}
	printf("%d", solution());
	return 0;
}