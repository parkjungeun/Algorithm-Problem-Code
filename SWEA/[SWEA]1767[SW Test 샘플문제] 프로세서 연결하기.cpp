/*
1767.[SW Test 샘플문제] 프로세서 연결하기
1. 전선을 현 위치에서 설치할 수 있는지 검사
2. 상하좌우 4방향을 탐색하여, 정선을 설치할 수 있다면 전선을 설치
3. 백트래킹을 이용하여, 전선 설치 - 재귀 - 전선 해체
*/

#include<iostream>
#include<memory.h>
#include<vector>
#define MAX_N 12

using namespace std;

int map[MAX_N][MAX_N];
int N;	//N : 입력받은 코어의 개수
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

vector<pair<int, int> > core;	//검사할 코어의 정보 (가장 자리 제외)
int sz = 0, ans_core, ans_line; //sz :코어의 개수

bool isOK(int coreIdx, int dir) {
	int y = core[coreIdx].first;
	int x = core[coreIdx].second;

	while (1) {
		if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
			break;

		x += dx[dir];
		y += dy[dir];


		if (map[y][x])	//중간에 코어가 있는 것. 실패...
			return false;
	}
	return true;
}

int fillLine(int coreIdx, int dir, int val) {
	int y = core[coreIdx].first;
	int x = core[coreIdx].second;
	int line = 0;

	while (1) {
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= N)
			break;
			
		map[y][x] = val;
		line++;
	}
	return line;
}

//coreIdx : 현재 확인할 코어번수
//coreCnt : 현재 연결된 코어개수
//lineLen : 연결된 전선의 길이
//현재 coreIdx번째 코어를 확인해 볼 차례이며, 지금까지 coreCnt개의 코어가 연결되었고, 그 비용은 lineLen
void solution(int coreIdx, int coreCnt, int lineLen) {
	//모든 코어 검사를 끝냈을 때,
	if (coreIdx == sz) {
		if (ans_core < coreCnt) {
			//최대 코어의 개수에서 최소 라인수
			ans_core = coreCnt;
			ans_line = lineLen;
		}
		else if (ans_core == coreCnt) {
			//코어의 개수가 같을 때, 최소 라인 수
			ans_line = ans_line < lineLen ? ans_line : lineLen;
		}
		return;
	}

	int y = core[coreIdx].first;
	int x = core[coreIdx].second;

	//가장자리일 때, 그냥 넘어감.
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
		solution(coreIdx + 1, coreCnt, lineLen);
	else {
		//4방향 체크과정
		for (int i = 0; i < 4; ++i) {
			//채우기 가능한지 먼저 확인, 가능하면 선 채우기
			if (isOK(coreIdx, i)) {
				int add_line = fillLine(coreIdx, i, 1);
				solution(coreIdx + 1, coreCnt + 1, lineLen + add_line);
				fillLine(coreIdx, i, 0);
			}
		}

		//여기 왔다는 것은, 4방향을 체크했는데 사방이 막혀있는 core인 것.
		//혹은 이 core를 전선연결 안시키고, 넘어갈 때,
		solution(coreIdx + 1, coreCnt, lineLen);
	}
}

void init() {
	memset(map, 0, sizeof(map));
	core.clear();
	ans_core = -1;	ans_line = INT_MAX;	sz = 0;
	return;
}

int main() {
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; ++testCase) {
		cin >> N;
		init();

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];

				if (map[i][j])
					core.push_back(make_pair(i, j));
			}

		}
		sz = core.size();
		solution(0, 0, 0);
		cout << "#" << testCase << ' ' << ans_line << endl;
	}
	return 0;
}