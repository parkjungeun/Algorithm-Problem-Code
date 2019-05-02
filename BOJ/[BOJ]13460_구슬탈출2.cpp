#include<iostream>
#include<queue>
#define MAX_N 10
using namespace std;

char map[MAX_N][MAX_N], visit[MAX_N][MAX_N][MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int N, M;

struct INFO {
	int ry, rx, by, bx, cnt;
};

int solution(struct INFO info) {
	queue<INFO> Q;
	Q.push(info);

	//이미 들린 곳이면 또 들릴 필요 X
	visit[info.ry][info.rx][info.by][info.bx] = 1;
	
	int res = -1, cnt = 0;
	while (!Q.empty()) {
		
		INFO cur = Q.front();	Q.pop();
		
		if (cur.cnt > 10)	break;

		//구멍을 찾은 경우
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			res = cur.cnt;
			break;
		}

		//이 외의 경우는 순회
		for (int i = 0; i < 4; ++i) {
			int _ry = cur.ry, _rx = cur.rx;
			int _by = cur.by, _bx = cur.bx;
			
			//빨간 공
			while (1) {
				if (map[_ry][_rx] != '#' && map[_ry][_rx] != 'O') {
					_rx += dx[i];	_ry += dy[i];
				}
				else {
					if (map[_ry][_rx] == '#') {
						_rx -= dx[i];	_ry -= dy[i];
					}
					break;
				}
			}

			//파란 공
			while (1) {
				if (map[_by][_bx] != '#' && map[_by][_bx] != 'O') {
					_bx += dx[i];	_by += dy[i];
				}
				else {
					if (map[_by][_bx] == '#') {
						_bx -= dx[i];	_by -= dy[i];
					}
					break;
				}
			}

			//한 칸에 같이 존재하는 경우 정리
			if (_ry == _by && _rx == _bx) {
				//구멍이면 같은 위치 존재 가능
				if (map[_ry][_rx] != 'O') {
					int red_dist = abs(cur.ry - _ry) + abs(cur.rx - _rx);
					int blue_dist = abs(cur.by - _by) + abs(cur.bx - _bx);

					//더 많이 이동한게 한칸 더 적게 움직여야함.
					if (red_dist > blue_dist) {
						_rx -= dx[i]; _ry -= dy[i];
					}
					else {
						_bx -= dx[i]; _by -= dy[i];
					}
				}
			}

			//아직 방문 전 이라면,
			if (!visit[_ry][_rx][_by][_bx]) {
				visit[_ry][_rx][_by][_bx] = 1;

				INFO info;
				info.bx = _bx; info.by = _by;
				info.rx = _rx; info.ry = _ry;
				info.cnt = cur.cnt + 1;
				Q.push(info);
			}
		}
	}
	return res;
}

int main() {
	cin >> N >> M;

	struct INFO start;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 'R') {
				start.rx = c; start.ry = r;
			}
			else if (map[r][c] == 'B') {
				start.bx = c; start.by = r;
			}
		}
	}
	start.cnt = 0;
	cout << solution(start);
	return 0;
}