#include<stdio.h>
#include<iostream>


#define MAX_N 10

// Dist[MAX_N] : ������ ������ �̸��� �ִܰŸ��� ���
// Prev[MAX_N] : ���� �������� ������ ���������� ��θ� �����ϱ� ���� �迭 (�ٷ� �� ��带 ����)
int N, Graph[MAX_N][MAX_N], Dist[MAX_N], Prev[MAX_N];

/*
Dijkstra �˰���
 : ���� �������� �Ÿ��� �ּ��� ������ ������ �����鼭 �ִ� ��θ� ���ϴ� ���

 1) ���� ����(S)���� �� ����(T)������ �ִ� ��ο� ���� X�� ������.
 2) �̶�, �ִ� ��δ� S���� X������ �ִ� ��ο� X���� T������ �ִ� ��η� ������
*/
void dijkstra(int start) {
	bool visited[MAX_N] = { false };	//�鸰 ������ ǥ���ϱ� ���� �迭

	//�̷������� ���Ѵ�.
	for (int i = 0; i < N; ++i) {
		Prev[i] = -1;
		Dist[i] = INT_MAX;
	}
	
	Dist[start] = 0;	//���� �������� ����� ���� �����Ƿ�, 0���� �ʱ�ȭ

	// �� �� �ִٰ�,��θ� �ľ��� ���� �߿��� ���� ���� ���� ������ ��, Ȯ��
	for (int i = 0; i < N; ++i) {
		int minCost = INT_MAX, minVertex;

		//������ ��� Ȯ�� �غ��µ�,
		// ���� �湮���� ���� ������ �߿��� �ּҰ��� ���� ������ ����
		for (int j = 0; j < N; ++j) {
			if (!visited[j] && Dist[j] < minCost) {
				minCost = Dist[j];
				minVertex = j;
			}
		}

		visited[minVertex] = true;

		// ���õ� ������ ���ؼ� �� �� �ִ�(������) �������� ���ϴ� �κ�
		for (int j = 0; j < N; ++j) {
			int distance = Dist[minVertex] + Graph[minVertex][j];

			// ���õ� ������ ������ ���� ������ ����� ������ ����� ���(���Ѵ�)���� ������ ����
			if (Dist[j] > distance) {
				Prev[j] = minVertex;	// j������ �ִ� ��θ� ���Ϸ���, �ٷ� �� ���� minVertex�� ���Ŀ;� ��!
				Dist[j] = distance;
			}
		}
	}
}

