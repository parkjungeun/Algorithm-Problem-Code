/*
최소 신장 트리(Minimum Spanning Tree) 
 : 무방향 가중치 그래프에서 신장 트리를 구성하는 간선들의 가중치의 합이 최소의 신장 트리
*/
#include<stdio.h>
#include<iostream>
#include<queue>
#include <functional>
#define MAX_N 20

using namespace std;

/*
Prim 알고리즘
 : 하나의 정점에서 연결된 간선들 중에 하나씩 선택하면서 MST를 만들어가는 방식
 1) 임의 정점을 하나 선택해서 시작
 2) 선택한 정점과 인접하는 정점들 중의 최소 비용의 간선이 존재하는 정점을 선택
 3) 모든 정점이 선택될 때 까지, 1),2) 과정을 반복
 */

int Graph[MAX_N][MAX_N], Parent[MAX_N], weight[MAX_N];
int N;

int primAlgorithm() {
	// 각각의 노드가 아직 선택되지 않았다는 의미
	// 값이 음수가 아니라면 MST에 포함됐다는 의미
	// 음수가 아닌 값이 주어지면, 그 노드를 MST에 연결하기 위한 비용을 저장
	for (int i = 0; i < N; ++i)	// weight배열 초기화 과정
		weight[i] = -1;

	//임의의 정점 선택
	weight[0] = 0;

	//이미 한 개는 임의 선택(0) 했으므로, N-1개의 정점을 더 선택하면 됨!
	for (int k = 1; k < N; ++k) {
		int minWeight = INT_MAX, minVertex, minParent;

		for (int i = 0; i < N; ++i) {
			//이미 선택된 정점들과 연결되는 정점을 선택해야 하므로, 
			//아직 MST에 포함되지 않은 정점은 skip
			if (weight[i] < 0)
				continue;

			for (int j = 0; j < N; ++j) {
				/* 현재 정점에서 연결된 정점들 중 아직 
				   선택되지 않은 정점을 선택해야하므로,
				   음수가 아닌(이미 선택된) 정점은 제외 */
				if (weight[j] >= 0)
					continue;

				// i (임의의 정점)과 연결된 j 찾기 (아직 MST에 포함 안된 정점)
				if (Graph[i][j] < minWeight) {
					minVertex = j;	minParent = i;
					minWeight = Graph[i][j];
				}
			}
		}
		Parent[minVertex] = minParent;
		weight[minVertex] = minWeight;
	}

	int sumCost = 0;	// MST의 비용을 계산하는 변수
	for (int i = 0; i < N; ++i)
		sumCost += weight[i];
	
	return sumCost;
}


/*
 Prim 알고리즘 - priority queue (Heap)를 사용하여 성능 개선
 MST의 최소 비용만 구하는 예제
*/
int Graph[MAX_N][MAX_N], N;

int primAlgorithm_priorityQueue() {
	// pair<int, int> : 가중치, 정점 번호
	// greater<pair<int, int>> : 가장 작은 가중치가 우선순위가 높도록
	priority_queue< pair<int, int>, vector<pair<int, int>>,
					greater<pair<int, int>>> pq;
	bool visited[MAX_N] = { false };	//정점을 1번씩만 처리할 수 있도록 bool배열!

	visited[0] = true;

	for (int next = 0; next < N; ++next)
		pq.push(make_pair(Graph[0][next], next));	//0번에서 next정점까지의 가중치, next(정점 번호)

	int sumCost = 0;
	
	//큐가 다 빌 때까지 반복
	while(!pq.empty()) {
		//우선순위큐로 가장 작은 가중치를 가진 정점이 top에 있음!
		int curNode = pq.top().second;	 //가중치가 작은 정점 번호
		int weight = pq.top().first; //가중치
		pq.pop();

		// 이미 MST에 속한 정점이라면 skip
		if (visited[curNode])
			continue;
		
		// MST에 추가해야할 정점
		visited[curNode] = true;
		sumCost += weight;

		//새로 추가한 정점과 연결된 간선들을 우선순위 큐에 모두 push
		//이때, 우선순위 큐이므로 가중치가 가장 작은 값이 맨 앞에 위치하게 됨.
		for (int next = 0; next < N; ++next)
			pq.push(make_pair(Graph[curNode][next], next));
	}
	return sumCost;
}
