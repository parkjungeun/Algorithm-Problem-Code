//1249.[S / W �����ذ� ����] 4���� - ���޷� D4
#pragma warning (disable:4996)
#include<stdio.h>
#include<queue>
#include<memory.h>
#define MAX_N 100

using namespace std;

int Graph[MAX_N][MAX_N], N;
int Dist[MAX_N][MAX_N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

int solution()
{
	queue <pair<int, int>> Q;

	Q.push(make_pair(0, 0));	//�������� 0
	Dist[0][0] = 0;		        //ó�� ��ġ�̹Ƿ� ���� �ð��� 0

	while (!Q.empty()) {

		int _x = Q.front().first;	//������ ��ġ x,y���� ������ ����
		int _y = Q.front().second;
		Q.pop();

		//������ ��ġ���� �����¿� �� �� �ִ��� Ȯ��
		for (int i = 0; i < 4; i++) {
			int temp_x = _x + dx[i], temp_y = _y + dy[i];

			//������ ����� ������ ��� ���̹Ƿ� �ѱ�.
			if (temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N)
				continue;

			//����, �����¿� �� ���� ���� ���Եȴٸ�, 
			//���� ��ġ[_x][_y] ������ �ִܰŸ��� ����� Dist[_x][_y]����
			//[temp_x][temp_y]�� �̵����� �� �߰��Ǵ� ���� �ð��� ����.
			int distance = Dist[_x][_y] + Graph[temp_x][temp_y];

			//[_x][_y]�� ���� [temp_x][temp_y]�� �̵����� ���� ���� �ð���
			//������ [temp_x][temp_y]�� ������ �۴ٸ�, �� ���� ������ ���Ž�Ű��,
			//���ο� ��ġ [temp_x][temp_y]�� ť�� ����. (����, ���⼭ ���� �� ������� �̵��� ����)
			if (Dist[temp_x][temp_y] > distance) {
				Q.push(make_pair(temp_x, temp_y));
				Dist[temp_x][temp_y] = distance;
			}
		}
	}
	return Dist[N - 1][N - 1];;
}

void init() {
	for (int i = 0; i < MAX_N; i++) {
		memset(Dist[i], 999999, sizeof(int) * MAX_N);
		memset(Graph[i], 0, sizeof(int) * MAX_N);
	}

	scanf("%d", &N);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			scanf("%1d", &Graph[x][y]);
		}
	}
	return;
}

int main()
{
	int test = 0;
	scanf("%d", &test);

	for (int i = 1; i <= test; i++) {
		init();
		printf("#%d %d\n", i, solution());
	}

	return 0;
}