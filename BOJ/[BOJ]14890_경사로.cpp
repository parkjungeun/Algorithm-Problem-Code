#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>

#define MAX_N 100  //(2 ≤ N ≤ 100)

int map1[MAX_N][MAX_N], map2[MAX_N][MAX_N];
int L;			//경사로 밑변의 길이  (1 ≤ L ≤ N)
int ans = 0, N;

void solution(int idx, int map[MAX_N][MAX_N]) {

	int n = map[idx][0];
	int use[MAX_N] = { 0, };

	for (int i = 0; i < N; ++i) {

		if (map[idx][i] == n)	//같은 높이일 때는 넘어가면 됨.
			continue;

		//다음 언덕과 차이가 1보다 크면 경사로 설치 불가능.
		if (abs(map[idx][i] - n) > 1)
			return;

		if (n < map[idx][i]) {	//뒤쪽의 언덕이 더 높을 때, 경사로를 앞으로 지어야함.
			if (i - L < 0)		//경사로를 놓을 공간 X
				return;

			//경사로는 현재보다 1칸 앞의 언덕부터 설치해야하므로 i-1
			for (int j = i - 1; j >= (i - L); --j) {
				//경사로의 길이 만큼의 언덕을 계산하는 데,
				//중간에 높이가 다르거나 이미 경사로를 설치했으면 종료.
				if (map[idx][i] != map[idx][j] && use[j])
					return;
				use[j] = 1;	//경사로를 설치한 것을 표시
			}

			n = map[idx][i];//현재의 언덕부터 다시 계산.
		}
		else if (n > map[idx][i]) {	//앞쪽의 언덕이 더 높을 때, 경사로를 뒤로 지어야함.
			if (i + L > N)			//경사로를 놓을 공간 X 
				return;

			//현재의 위치부터 경사로를 지어햐 함.
			for (int j = i; j < i + L; ++j) {
				if (map[idx][i] != map[idx][j] || use[j])
					return;
				use[j] = 1;
			}

			if (i + L < N)
				n = map[idx][i + L - 1];	//경사로를 설치한 길이 다음부터 계산

			i = i + L - 1;
		}
	}
	ans++;
	return;
}

int main() {
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map1[i][j]);
			map2[j][i] = map1[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		solution(i, map1);	//row계산
		solution(i, map2);	//col계산
	}
	printf("%d", ans);

	return 0;
}