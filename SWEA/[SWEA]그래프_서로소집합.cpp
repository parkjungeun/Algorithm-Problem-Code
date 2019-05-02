//Disjoint-Set (서로서 집합)
#include<stdio.h>
#define MAX_N 100

int Parent[MAX_N];

//makeSet(v)
//유일한 멤버 v를 포함하는 새로운 집합을 생성하는 연산
void makeSet(int v) {
	Parent[v] = v;
	return;
}

//findSet(v)
//v를 포함하는 집합을 찾는 연산
int findSet(int v) {
	if (Parent[v] < 0)
		return v;
	return findSet(Parent[v]);
}

//unionSet(u, v)
//u와 v를 포함하는 두 집합을 통합하는 연산(합집합)
void unionSet(int u, int v) {
	int u_root = findSet(u);
	int v_root = findSet(v);

	if (u_root == v_root)	//이미 같은 집합에 속해있음.
		return;

	Parent[u_root] += Parent[v_root];
	Parent[v_root] = u_root;
	return;
}

//집합의 크기
int getSetSize(int v){
	return -Parent[findSet(v)];
}

int main()
{
	//Parent[]에 음수 값을 갖고있으면,
	//그 집합의 대표 원소로서 size를 나타낸다.
	for (int i = 0; i < MAX_N; ++i)
		Parent[i] = -1;		//원소 1개라는 의미

	unionSet(2, 3);
	printf("getSetSize(2) : %d\n", getSetSize(2));
	unionSet(4, 5);
	printf("getSetSize(4) : %d\n", getSetSize(2));
	unionSet(3, 5);

	printf("getSetSize(2) : %d\n", getSetSize(2));
	printf("getSetSize(3) : %d\n", getSetSize(2));
	return 0;
}