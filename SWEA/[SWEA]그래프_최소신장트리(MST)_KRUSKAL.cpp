/*
�ּ� ���� Ʈ��(Minimum Spanning Tree)
: ������ ����ġ �׷������� ���� Ʈ���� �����ϴ� �������� ����ġ�� ���� �ּ��� ���� Ʈ��
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX_N 20

using namespace std;

struct edge_type{
	int u;		//����1
	int v;		//����2
	int  cost;	//����1�� ����2 ������ ����ġ
};

//MAX_N*(MAX_N - 1) / 2 �̶�?
//������ ������ MAX_N�� ��, ���� �� �ִ� �ִ� ������ ����
edge_type EdgeArr[MAX_N*(MAX_N - 1) / 2];
int EdgeCnt;	//������ ����
int Parent[MAX_N], N;
void quickSort(int arr[], int left, int right);
int findSet(int v);

/*
KRUSKAL �˰���
 : ������ �ϳ��� �����ؼ� MST�� ã�� �˰���
  1) ��� ������ ����ġ�� ���� ������������ ����
  2) ����ġ�� ���� ���� �������� �����ϸ鼭 Ʈ���� ������Ŵ
     - ����Ŭ�� �����ϸ� �������� ����ġ�� ���� ���� ����
  3) n-1���� ������ ���õ� ������ 2)�� �ݺ�

����Ŭ ���δ� Union-find �ڷᱸ���� ����ؼ� �Ǵ���.
*/
int Kruskal() {
	quickSort(EdgeArr, 0, EdgeCnt - 1);	//������������ ����
	
	for (int i = 0; i < N; ++i)	//Make Set (ó�� ������ �ڱ� �ڽŸ��� ����)
		Parent[i] = i;

	int sumCost = 0, selectCnt = 0;	//sumCost : MST�� �� ����ġ ��
									//selectCnt : MST�� �����ϴµ� ���� ������ ����

	for (int i = 0; i < EdgeCnt; ++i) {
		int u = EdgeArr[i].u, v = EdgeArr[i].v;
		int u_root = findSet(u), v_root = findSet(v);

		if (u_root == v_root)	//Cycle
			continue;			//skip

		//���� ���տ� ������ �ʴ´ٴ� �ǹ�.
		//�� ������ �����ϸ� u_root�� v_root�� ���� ���տ� ���ϰ� ��.
		Parent[u_root] = v_root;	//Union

		sumCost += EdgeArr[i].cost;
		selectCnt++;

		if (selectCnt >= N - 1)	//��� ���� �� ������ ��,
			break;
	}
	return sumCost;
}

int findSet(int v) {
	if (Parent[v] == v)
		return v;
	return findSet(Parent[v]);
}

void quickSort(edge_type arr[], int left, int right) {
	if (left >= right)
		return;

	int pivot = left, l = left + 1, r = right;

	while (1) {
		while (arr[pivot].cost > arr[l].cost)
			l++;
		while (arr[pivot].cost < arr[r].cost)
			r--;

		if (l < r) {
			int temp = arr[l].cost;
			arr[l].cost = arr[r].cost;
			arr[r].cost = temp;
		}
		else {
			int temp = arr[pivot].cost;
			arr[pivot].cost = arr[r].cost;
			arr[r].cost = temp;
			break;
		}
	}
	quickSort(arr, left, r - 1);
	quickSort(arr, r + 1, right);
	return;
}