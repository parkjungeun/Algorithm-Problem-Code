/*
�ּ� ���� Ʈ��(Minimum Spanning Tree) 
 : ������ ����ġ �׷������� ���� Ʈ���� �����ϴ� �������� ����ġ�� ���� �ּ��� ���� Ʈ��
*/
#include<stdio.h>
#include<iostream>
#include<queue>
#include <functional>
#define MAX_N 20

using namespace std;

/*
Prim �˰���
 : �ϳ��� �������� ����� ������ �߿� �ϳ��� �����ϸ鼭 MST�� ������ ���
 1) ���� ������ �ϳ� �����ؼ� ����
 2) ������ ������ �����ϴ� ������ ���� �ּ� ����� ������ �����ϴ� ������ ����
 3) ��� ������ ���õ� �� ����, 1),2) ������ �ݺ�
 */

int Graph[MAX_N][MAX_N], Parent[MAX_N], weight[MAX_N];
int N;

int primAlgorithm() {
	// ������ ��尡 ���� ���õ��� �ʾҴٴ� �ǹ�
	// ���� ������ �ƴ϶�� MST�� ���Եƴٴ� �ǹ�
	// ������ �ƴ� ���� �־�����, �� ��带 MST�� �����ϱ� ���� ����� ����
	for (int i = 0; i < N; ++i)	// weight�迭 �ʱ�ȭ ����
		weight[i] = -1;

	//������ ���� ����
	weight[0] = 0;

	//�̹� �� ���� ���� ����(0) �����Ƿ�, N-1���� ������ �� �����ϸ� ��!
	for (int k = 1; k < N; ++k) {
		int minWeight = INT_MAX, minVertex, minParent;

		for (int i = 0; i < N; ++i) {
			//�̹� ���õ� ������� ����Ǵ� ������ �����ؾ� �ϹǷ�, 
			//���� MST�� ���Ե��� ���� ������ skip
			if (weight[i] < 0)
				continue;

			for (int j = 0; j < N; ++j) {
				/* ���� �������� ����� ������ �� ���� 
				   ���õ��� ���� ������ �����ؾ��ϹǷ�,
				   ������ �ƴ�(�̹� ���õ�) ������ ���� */
				if (weight[j] >= 0)
					continue;

				// i (������ ����)�� ����� j ã�� (���� MST�� ���� �ȵ� ����)
				if (Graph[i][j] < minWeight) {
					minVertex = j;	minParent = i;
					minWeight = Graph[i][j];
				}
			}
		}
		Parent[minVertex] = minParent;
		weight[minVertex] = minWeight;
	}

	int sumCost = 0;	// MST�� ����� ����ϴ� ����
	for (int i = 0; i < N; ++i)
		sumCost += weight[i];
	
	return sumCost;
}


/*
 Prim �˰��� - priority queue (Heap)�� ����Ͽ� ���� ����
 MST�� �ּ� ��븸 ���ϴ� ����
*/
int Graph[MAX_N][MAX_N], N;

int primAlgorithm_priorityQueue() {
	// pair<int, int> : ����ġ, ���� ��ȣ
	// greater<pair<int, int>> : ���� ���� ����ġ�� �켱������ ������
	priority_queue< pair<int, int>, vector<pair<int, int>>,
					greater<pair<int, int>>> pq;
	bool visited[MAX_N] = { false };	//������ 1������ ó���� �� �ֵ��� bool�迭!

	visited[0] = true;

	for (int next = 0; next < N; ++next)
		pq.push(make_pair(Graph[0][next], next));	//0������ next���������� ����ġ, next(���� ��ȣ)

	int sumCost = 0;
	
	//ť�� �� �� ������ �ݺ�
	while(!pq.empty()) {
		//�켱����ť�� ���� ���� ����ġ�� ���� ������ top�� ����!
		int curNode = pq.top().second;	 //����ġ�� ���� ���� ��ȣ
		int weight = pq.top().first; //����ġ
		pq.pop();

		// �̹� MST�� ���� �����̶�� skip
		if (visited[curNode])
			continue;
		
		// MST�� �߰��ؾ��� ����
		visited[curNode] = true;
		sumCost += weight;

		//���� �߰��� ������ ����� �������� �켱���� ť�� ��� push
		//�̶�, �켱���� ť�̹Ƿ� ����ġ�� ���� ���� ���� �� �տ� ��ġ�ϰ� ��.
		for (int next = 0; next < N; ++next)
			pq.push(make_pair(Graph[curNode][next], next));
	}
	return sumCost;
}
