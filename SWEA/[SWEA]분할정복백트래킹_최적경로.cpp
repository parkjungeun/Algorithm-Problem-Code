#include<stdio.h>
#include<memory.h>
#include<algorithm>

struct node {
	int x;
	int y;
};

struct node map[12];
int visit[12];
int N, dist, minDist = INT_MAX;

int calc(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

//모든 거래처를 다 들렸으면 True
bool finish()
{
	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == 0)
			return false;
	}
	return true;
}

void solution(int cur_idx) {
	if (finish()) {
		//모든 곳 다 들렸으면 끝. (마지막 거래처 -> 집) 거리 계산해서 최소 거리인지 확인
		int _dist = calc(map[cur_idx].x, map[cur_idx].y, map[N + 1].x, map[N + 1].y);

		if (dist + _dist < minDist) {
			minDist = dist + _dist;
		}
		return;
	}

	//거래처들을 모든 경우의 수를 가지고 다니며 거리 계산
	//인덱스 1부터 계산하는 이유는? 처음거리는 (회사 --> 첫 번째 거래처)로 고정!이기 때문 
	for (int i = 1; i < N + 1; i++) 
	{
		//아직 방문하지 않은 거래처이고, 현재 있는 위치가 아니면!
		if (!visit[i] && cur_idx != i) 
		{
			int _dist = calc(map[cur_idx].x, map[cur_idx].y, map[i].x, map[i].y);

			//경우의 수를 줄여주기 위한 부분
			//모든 거래처를 거친 최소 거리보다 거리의 합이 크면 그 뒤는 계산하지 않아도 됨.
			if (dist + _dist > minDist) {
				continue;
			}

			visit[i] = 1;	dist += _dist;
			solution(i);
			visit[i] = 0;	dist -= _dist;
		}
	}
	return;
}

void init()
{
	int x, y;
	dist = 0; 	minDist = INT_MAX;
	memset(map, 0, sizeof(struct node) * 12);
	memset(visit, 0, sizeof(int) * 12);

	//거래처 개수
	scanf("%d", &N);

	//회사
	scanf("%d %d", &x, &y);
	map[0].x = x; map[0].y = y;

	//집
	scanf("%d %d", &x, &y);
	map[N + 1].x = x; map[N + 1].y = y;

	//거래처들
	for (int i = 1; i < N + 1; i++) {
		scanf("%d %d", &x, &y);
		map[i].x = x; map[i].y = y;
	}
	return;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		init();
		solution(0);	//첫 시작점인 회사부터!
		printf("#%d %d\n", test, minDist);
	}

	return 0;
}