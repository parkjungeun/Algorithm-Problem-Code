#include<stdio.h>
#include<iostream>


#define MAX_N 10

// Dist[MAX_N] : 각각의 정점에 이르는 최단거리의 비용
// Prev[MAX_N] : 시작 정점에서 마지막 정점까지의 경로를 추적하기 위한 배열 (바로 앞 노드를 저장)
int N, Graph[MAX_N][MAX_N], Dist[MAX_N], Prev[MAX_N];

/*
Dijkstra 알고리즘
 : 시작 정점에서 거리가 최소인 정점을 선택해 나가면서 최단 경로를 구하는 방식

 1) 시작 정점(S)에서 끝 정점(T)까지의 최단 경로에 정점 X가 존재함.
 2) 이때, 최단 경로는 S에서 X까지의 최단 경로와 X에서 T까지의 최단 경로로 구성됨
*/
void dijkstra(int start) {
	bool visited[MAX_N] = { false };	//들린 정점을 표시하기 위한 배열

	//이론적으로 무한대.
	for (int i = 0; i < N; ++i) {
		Prev[i] = -1;
		Dist[i] = INT_MAX;
	}
	
	Dist[start] = 0;	//최초 시작점은 비용이 들지 않으므로, 0으로 초기화

	// 갈 수 있다고,경로를 파악한 정점 중에서 가장 작은 것을 선택한 뒤, 확장
	for (int i = 0; i < N; ++i) {
		int minCost = INT_MAX, minVertex;

		//정점을 모두 확인 해보는데,
		// 아직 방문되지 않은 정점들 중에서 최소값을 갖는 정점을 선택
		for (int j = 0; j < N; ++j) {
			if (!visited[j] && Dist[j] < minCost) {
				minCost = Dist[j];
				minVertex = j;
			}
		}

		visited[minVertex] = true;

		// 선택된 정점을 통해서 갈 수 있는(인접한) 정점들을 구하는 부분
		for (int j = 0; j < N; ++j) {
			int distance = Dist[minVertex] + Graph[minVertex][j];

			// 선택된 정점과 인접한 정점 사이의 비용이 기존에 저장된 비용(무한대)보다 작으면 대입
			if (Dist[j] > distance) {
				Prev[j] = minVertex;	// j까지의 최단 경로를 구하려면, 바로 앞 정점 minVertex를 거쳐와야 함!
				Dist[j] = distance;
			}
		}
	}
}

