#include<stdio.h>
#include<cstring>
#include<vector>
#define MAX_N 11

using namespace std;

typedef struct Info {
	int row;
	int col;
	int height = -1;
}Info;

int map[MAX_N][MAX_N];
int N;	//방의 한 병의 길이 4 ≤ N ≤ 10
vector<Info> P;	//사람의 위치 (사람의 수  1 ≤ P ≤ 10)
vector<Info> S(2); //계단 2개의 위치와 높이 (계단의 길이는 2 ≤ S[] ≤ 10)
int minTime = INT_MAX;

//이동 시간(분) = | PR - SR | + | PC - SC |
int calcTime(int PR, int PC, int SR, int SC) {
	return abs(PR - SR) + abs(PC - SC);
}

//현재 완료된 사람, 현재까지 걸린 시간
void solution(int curPerson, int curTime) {

	if (curPerson == N) {
		if (curTime < minTime)
			minTime = curTime;
		return;
	}


}

void init() {
	memset(map, 0, sizeof(map));
	P.clear();	S.clear();
	minTime = INT_MAX;
	return;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		init();

		scanf("%d", &N);
		for (int row = 1; row <= N; ++row) {
			for (int col = 1; col <= N; ++col) {
				scanf("%d", &map[row][col]);
				if (map[row][col]) {
					Info info;
					info.row = row; info.col = col; 
					if (map[row][col] == 1)	P.push_back(info);
					else if (map[row][col] >= 2) {
						info.height = map[row][col];
						S.push_back(info);
					}
				}
			}
		}

		solution(0, 0);
		printf("#%d %d\n", i, minTime);
	}
	return 0;
}