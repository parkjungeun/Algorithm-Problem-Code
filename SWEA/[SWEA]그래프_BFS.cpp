#include<stdio.h>
#define MAX_N 20
#define QUEUE_SIZE 20

int Graph[MAX_N][MAX_N];
int Queue[QUEUE_SIZE], front, rear;

void bfs(int node)
{
	bool visited[MAX_N] = { false };
	front = rear = -1;
	Queue[++rear] = node;

	while (front != rear)
	{
		int cur = Queue[++front];

		for (int i = 0; i < MAX_N; i++) {
			if (!visited[i] && Graph[cur][i]) {
				visited[cur] = true;
				Queue[++rear] = i;
			}
		}
	}
}
