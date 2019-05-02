/*
1767.[SW Test ���ù���] ���μ��� �����ϱ�
1. ������ �� ��ġ���� ��ġ�� �� �ִ��� �˻�
2. �����¿� 4������ Ž���Ͽ�, ������ ��ġ�� �� �ִٸ� ������ ��ġ
3. ��Ʈ��ŷ�� �̿��Ͽ�, ���� ��ġ - ��� - ���� ��ü
*/

#include<iostream>
#include<memory.h>
#include<vector>
#define MAX_N 12

using namespace std;

int map[MAX_N][MAX_N];
int N;	//N : �Է¹��� �ھ��� ����
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

vector<pair<int, int> > core;	//�˻��� �ھ��� ���� (���� �ڸ� ����)
int sz = 0, ans_core, ans_line; //sz :�ھ��� ����

bool isOK(int coreIdx, int dir) {
	int y = core[coreIdx].first;
	int x = core[coreIdx].second;

	while (1) {
		if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
			break;

		x += dx[dir];
		y += dy[dir];


		if (map[y][x])	//�߰��� �ھ �ִ� ��. ����...
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

//coreIdx : ���� Ȯ���� �ھ����
//coreCnt : ���� ����� �ھ��
//lineLen : ����� ������ ����
//���� coreIdx��° �ھ Ȯ���� �� �����̸�, ���ݱ��� coreCnt���� �ھ ����Ǿ���, �� ����� lineLen
void solution(int coreIdx, int coreCnt, int lineLen) {
	//��� �ھ� �˻縦 ������ ��,
	if (coreIdx == sz) {
		if (ans_core < coreCnt) {
			//�ִ� �ھ��� �������� �ּ� ���μ�
			ans_core = coreCnt;
			ans_line = lineLen;
		}
		else if (ans_core == coreCnt) {
			//�ھ��� ������ ���� ��, �ּ� ���� ��
			ans_line = ans_line < lineLen ? ans_line : lineLen;
		}
		return;
	}

	int y = core[coreIdx].first;
	int x = core[coreIdx].second;

	//�����ڸ��� ��, �׳� �Ѿ.
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
		solution(coreIdx + 1, coreCnt, lineLen);
	else {
		//4���� üũ����
		for (int i = 0; i < 4; ++i) {
			//ä��� �������� ���� Ȯ��, �����ϸ� �� ä���
			if (isOK(coreIdx, i)) {
				int add_line = fillLine(coreIdx, i, 1);
				solution(coreIdx + 1, coreCnt + 1, lineLen + add_line);
				fillLine(coreIdx, i, 0);
			}
		}

		//���� �Դٴ� ����, 4������ üũ�ߴµ� ����� �����ִ� core�� ��.
		//Ȥ�� �� core�� �������� �Ƚ�Ű��, �Ѿ ��,
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