#include<stdio.h>

#define ABS(x) (x > 0 ? x : -(x))

// N : N-Queen에서의 N
//Row[100] : 99-Queen까지 가능한 배열.
int N, Row[100] = { 0, };

//경우의 수와 퀸이 놓인 자리를 출력하는 함수
//즉, 체스판 상의 좌표를 출력
void printResult() {
	static int cnt = 1;	//총 가능한 경우의 수를 나타낼 변수.

	printf("%3d Result : ", cnt++);
	
	for (int i = 1; i <= N; ++i)
		printf("(%d, %d) ", i, Row[i]);
	
	printf("\n");
	return;
}

//현재 q행에 놓인 퀸의 위치(열)가 유망한지 안한지 판단하는 함수
bool promising(int q) {
	for (int i = 1; i < q; i++) {
		if (Row[q] == Row[i])	//세로로 침범하는지 (같은 열의 값을 가지면)
			return false;
		else if (ABS(Row[q] - Row[i]) == ABS(q - i))	//대각선으로 침범하는지
			return false;								//(가로의 차 == 세로의 차)이면 대각선 위치에 있는 것.
														//이등변 삼각형의 원리!
	}
	return true;
}

// q : 현재 몇 개의 퀸이 놓여졌는지.
void queens(int q) {

	//유망한지 아닌지 판단.
	//유망하지 않으면 return => 이 부분이 가지치기(prunning)부분!
	//가지치기(prunning) : 탐색하는 경우의 수를 줄여줌.
	if (!promising(q))	
		return;		

	//모든 퀸이 다 놓여졌으면, 출력.
	if (q == N) {
		printResult();
		return;
	}

	//각 행에 1개씩만 퀸을 놓음.
	//다음 행에 놓여질 퀸의 위치(열)를 찾는 부분
	for (int i = 1; i <= N; ++i) {
		Row[q + 1] = i;

		//다음 행의 열에 퀸을 놓고, 유망한지 아닌지 판별위해 재귀호출!
		queens(q + 1);
		//유망하면, 또 그 다음 행에서의 퀸의 위치를 찾고,
		//유망하지 않으면, 이 부분으로 돌아와 다시 다른 열에다가 퀸을 놓아보는 작업을 반복.
	}
	return;
}

int main()
{
	scanf("%d", &N);
	queens(0);	// 처음 시작은 놓여진 퀸이 존재하지 않으므로 0.
	return 0;
}