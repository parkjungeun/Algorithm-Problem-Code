#include<stdio.h>
#include<memory.h>
using namespace std;

struct node
{
	int parent;
	int child[2];
	int childNodeCount;
};
struct node Node[10001];

int V, E, v1, v2;

int calcNodeNum(int n)
{
	int res = Node[n].childNodeCount;
	for (int i = 0; i < Node[n].childNodeCount; i++) {
		res += calcNodeNum(Node[n].child[i]);
	}
	return res;
}

int solution()
{
	int temp1[10001] = { 0, };
	int idx = 0;
	temp1[0] = v1;

	int pre = temp1[0];
	while (Node[pre].parent != 0) {
		temp1[++idx] = Node[pre].parent;
		pre = Node[temp1[idx - 1]].parent;
	}

	int temp2 = v2;
	while (temp2 != 0) {
		for (int i = 0; i <= idx; i++) {
			if (temp2 == temp1[i])
				return temp2;
		}
		temp2 = Node[temp2].parent;
	}
}

void init()
{
	memset(Node, 0, sizeof(struct node) * 10001);
	scanf("%d %d %d %d", &V, &E, &v1, &v2);

	int p, c;
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d", &p, &c);
		Node[c].parent = p;
		Node[p].child[Node[p].childNodeCount++] = c;
	}
	return;
}

int main()
{
	int t;

	scanf("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		init();
		int res = solution();
		int cnt = calcNodeNum(res) + 1;
		printf("#%d %d %d\n", test, res, cnt);
	}
}