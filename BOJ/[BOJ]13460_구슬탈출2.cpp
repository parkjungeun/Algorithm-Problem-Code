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

	//�̹� �鸰 ���̸� �� �鸱 �ʿ� X
	visit[info.ry][info.rx][info.by][info.bx] = 1;
	
	int res = -1, cnt = 0;
	while (!Q.empty()) {
		
		INFO cur = Q.front();	Q.pop();
		
		if (cur.cnt > 10)	break;

		//������ ã�� ���
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			res = cur.cnt;
			break;
		}

		//�� ���� ���� ��ȸ
		for (int i = 0; i < 4; ++i) {
			int _ry = cur.ry, _rx = cur.rx;
			int _by = cur.by, _bx = cur.bx;
			
			//���� ��
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

			//�Ķ� ��
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

			//�� ĭ�� ���� �����ϴ� ��� ����
			if (_ry == _by && _rx == _bx) {
				//�����̸� ���� ��ġ ���� ����
				if (map[_ry][_rx] != 'O') {
					int red_dist = abs(cur.ry - _ry) + abs(cur.rx - _rx);
					int blue_dist = abs(cur.by - _by) + abs(cur.bx - _bx);

					//�� ���� �̵��Ѱ� ��ĭ �� ���� ����������.
					if (red_dist > blue_dist) {
						_rx -= dx[i]; _ry -= dy[i];
					}
					else {
						_bx -= dx[i]; _by -= dy[i];
					}
				}
			}

			//���� �湮 �� �̶��,
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