/*
최소 신장 트리(Minimum Spanning Tree)
: 무방향 가중치 그래프에서 신장 트리를 구성하는 간선들의 가중치의 합이 최소의 신장 트리
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX_N 20

using namespace std;

struct edge_type{
	int u;		//정점1
	int v;		//정점2
	int  cost;	//정점1과 정점2 사이의 가중치
};

//MAX_N*(MAX_N - 1) / 2 이란?
//정점의 개수가 MAX_N일 때, 가질 수 있는 최대 간선의 개수
edge_type EdgeArr[MAX_N*(MAX_N - 1) / 2];
int EdgeCnt;	//간선의 갯수
int Parent[MAX_N], N;
void quickSort(int arr[], int left, int right);
int findSet(int v);

/*
KRUSKAL 알고리즘
 : 간선을 하나씩 선택해서 MST를 찾는 알고리즘
  1) 모든 간선을 가중치에 따라 오름차순으로 정렬
  2) 가중치가 가장 낮은 간선부터 선택하면서 트리를 증가시킴
     - 사이클이 존재하면 다음으로 가중치가 낮은 간선 선택
  3) n-1개의 간선이 선택될 때까지 2)를 반복

사이클 여부는 Union-find 자료구조를 사용해서 판단함.
*/
int Kruskal() {
	quickSort(EdgeArr, 0, EdgeCnt - 1);	//오름차순으로 정렬
	
	for (int i = 0; i < N; ++i)	//Make Set (처음 집합은 자기 자신만을 가짐)
		Parent[i] = i;

	int sumCost = 0, selectCnt = 0;	//sumCost : MST의 총 가중치 값
									//selectCnt : MST를 구현하는데 사용된 간선의 개수

	for (int i = 0; i < EdgeCnt; ++i) {
		int u = EdgeArr[i].u, v = EdgeArr[i].v;
		int u_root = findSet(u), v_root = findSet(v);

		if (u_root == v_root)	//Cycle
			continue;			//skip

		//같은 집합에 속하지 않는다는 의미.
		//이 간선을 선택하면 u_root와 v_root는 같은 집합에 속하게 됨.
		Parent[u_root] = v_root;	//Union

		sumCost += EdgeArr[i].cost;
		selectCnt++;

		if (selectCnt >= N - 1)	//모든 간선 다 구했을 때,
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