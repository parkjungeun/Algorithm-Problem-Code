#include<stdio.h>
#include<memory.h>
#define MAX_N 10

int Graph[MAX_N][MAX_N];
bool visited[MAX_N];
int V, E;

void dfs1(int n)
{
	visited[n] = true;
	printf("%d ", n);
	
	for (int i = 0; i < V; i++) {
		if (!visited[i] && Graph[n][i] != 0)
			dfs1(i);
	}
}

int stack[20], top = -1;
void dfs2(int n)
{
	bool visit[MAX_N] = { false, };
	stack[++top] = n;

	while (top != -1)
	{
		int cur = stack[top--];
		if (!visit[cur]) {
			visit[cur] = true;
			printf("%d ", cur);

			for (int i = 0; i < V; i++) {
				if (!visit[i] && Graph[cur][i])
					stack[++top] = i;
			}
		}
	}
}
int main()
{
	memset(visited, false, sizeof(int)*MAX_N);
	for (int i = 0; i < V; i++) {
		memset(Graph[i], 0, sizeof(int)*MAX_N);
	}

	scanf("%d %d", &V, &E);

	int a, b;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		Graph[a][b] = 1;
		Graph[b][a] = 1;
	}

	printf("재귀 : ");			   dfs1(0);	
	printf("\n직접 스택 구현 : "); dfs2(0);
	return 0;
}

/*
int Graph1[MAX_N][MAX_N];
bool visit[MAX_N];

void recursive_DFS(int n)
{
	visit[n] = true;

	for (int i = 0; i < MAX_N; i++) {
		if (!visit[i] && Graph1[n][i] != 0)
			recursive_DFS(i);
	}
	return;
}

#define STACK_SIZE 100
int Graph2[MAX_N][MAX_N];
int Stack[STACK_SIZE], top = -1;
void repeat_DFS(int n)
{
	bool visited[MAX_N] = { false };
	top = -1;
	Stack[++top] = n;

	while (top != -1)
	{
		int cur = Stack[top--];
		if (!visited[cur]) {
			visited[cur] = true;

			for (int i = 0; i < MAX_N; i++)
			{
				if (!visited[i] && Graph2[cur][i] != 0) {
					Stack[++top] = i;
				}
			}
		}
	}
}
*/