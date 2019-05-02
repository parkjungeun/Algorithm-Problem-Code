#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX_N 20
using namespace std;

struct Info {
	int y;
	int x;
	int sz;
	int eat; // 몇 마리를 먹었는지
	int sec; // 이동한 시간
};

int map[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int N, ans = 0;
int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };

bool cmp(Info& a, Info& b) {
	if (a.sec <= b.sec) {
		if (a.sec == b.sec) {		// 시간이 같을 경우
			if (a.y <= b.y) {		// y값이 작은 거
				if (a.y == b.y) {	// y값이 같으면
					if (a.x < b.x)	return true;	//	x값이 더 작은 것
					else	return false;
				}
				return true;
			}
			else	return false;
		}
		else	return true;
	}
	return false;
}

void solution(int shark_y, int shark_x) {
	queue<Info> Q;	//상어의 방문 가능 위치
	vector<Info> v;	//먹을 수 있는 물고기 정보
	Info info = { shark_y, shark_x, 2, 0 ,0 };

	while (1) {
		v.clear();	memset(visited, 0, sizeof(visited));
		visited[info.y][info.x] = 1;	Q.push(info);

		while (!Q.empty()) {
			int y = Q.front().y;
			int x = Q.front().x;
			int sz = Q.front().sz;
			int eat = Q.front().eat;
			int time = Q.front().sec;
			Q.pop();

			//상,하,좌,우 검사
			for (int i = 0; i < 4; ++i) {
				int temp_x = x + dx[i];
				int temp_y = y + dy[i];

				if (temp_x < 0 || temp_x >= N || temp_y<0 || temp_y >= N ||
					map[temp_y][temp_x]>sz || visited[temp_y][temp_x])
					continue;

				//여기 까지 온 것은 지나갈 수 있는 경우
				visited[temp_y][temp_x] = 1;

				if (map[temp_y][temp_x] == 0 || map[temp_y][temp_x] == sz)	//그냥 지나가는 길
					Q.push({ temp_y, temp_x, sz, eat, time + 1 });
				else if (map[temp_y][temp_x] < sz)	//아기 상어가 먹을 수 있는 물고기인 경우,
					v.push_back({ temp_y, temp_x, sz, eat + 1, time + 1 });	//먹을 수 있는 물고기의 정보를 저장하는 벡터에 저장
			}
		}

		//먹을 수 있는 물고기가 없음	(끝나는 부분)
		if (v.size() == 0)	break;

		//먹을 수 있는 물고기가 있는 경우는 제일 시간이 짧고(가깝고), 위쪽에 있으며, 왼쪽에 있는 것 -> 이렇게 정렬
		sort(v.begin(), v.end(), cmp);
		
		//현재 먹을 물고기 개수가 상어의 크기와 같으면, 상어의 크기 +1, 먹은 개수는 초기화
		if (v[0].sz == v[0].eat) {
			v[0].sz++;	v[0].eat = 0;
		}

		//이 곳의 물고기 먹음.
		map[v[0].y][v[0].x] = 0;
		//이 물고기먹으러 오는데 걸린 시간
		ans += v[0].sec;
		//이 물고기 부터 다시 시작 (반복)
		info = { v[0].y,v[0].x,v[0].sz,v[0].eat,0 };
	}
	return;
}

int main() {
	scanf("%d", &N);

	int shark_x, shark_y;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			scanf("%d", &map[r][c]);
			
			if (map[r][c] == 9) {	//처음 상어의 위치
				shark_x = c; shark_y = r;
				map[r][c] = 0;
			}
		}
	}
	solution(shark_y, shark_x);	printf("%d", ans);
	return 0;
}