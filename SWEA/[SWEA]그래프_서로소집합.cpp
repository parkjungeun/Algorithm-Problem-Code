//Disjoint-Set (���μ� ����)
#include<stdio.h>
#define MAX_N 100

int Parent[MAX_N];

//makeSet(v)
//������ ��� v�� �����ϴ� ���ο� ������ �����ϴ� ����
void makeSet(int v) {
	Parent[v] = v;
	return;
}

//findSet(v)
//v�� �����ϴ� ������ ã�� ����
int findSet(int v) {
	if (Parent[v] < 0)
		return v;
	return findSet(Parent[v]);
}

//unionSet(u, v)
//u�� v�� �����ϴ� �� ������ �����ϴ� ����(������)
void unionSet(int u, int v) {
	int u_root = findSet(u);
	int v_root = findSet(v);

	if (u_root == v_root)	//�̹� ���� ���տ� ��������.
		return;

	Parent[u_root] += Parent[v_root];
	Parent[v_root] = u_root;
	return;
}

//������ ũ��
int getSetSize(int v){
	return -Parent[findSet(v)];
}

int main()
{
	//Parent[]�� ���� ���� ����������,
	//�� ������ ��ǥ ���ҷμ� size�� ��Ÿ����.
	for (int i = 0; i < MAX_N; ++i)
		Parent[i] = -1;		//���� 1����� �ǹ�

	unionSet(2, 3);
	printf("getSetSize(2) : %d\n", getSetSize(2));
	unionSet(4, 5);
	printf("getSetSize(4) : %d\n", getSetSize(2));
	unionSet(3, 5);

	printf("getSetSize(2) : %d\n", getSetSize(2));
	printf("getSetSize(3) : %d\n", getSetSize(2));
	return 0;
}