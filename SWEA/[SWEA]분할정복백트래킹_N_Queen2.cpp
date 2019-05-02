#include<stdio.h>

#define ABS(x) (x > 0 ? x : -(x))

int N, Row[100] = { 0, };

void printResult()
{
	static int cnt = 1;

	printf(" %3d Result : ", cnt++);
	for (int i = 1; i <= N; ++i) {
		printf("(%d, %d) ", i, Row[i]);
	}
	printf("\n");
	return;
}

bool promising(int q)
{
	for (int i = 1; i < q; ++i)
	{
		if (Row[q] == Row[i])
			return false;
		if (ABS(Row[q] - Row[i]) == ABS(q - i))
			return false;
	}
	return true;
}

void queens(int q)
{
	if (!promising(q))
		return;

	if (N == q) {
		printResult();
		return;
	}

	for (int i = 1; i <= N; ++i) {
		Row[q + 1] = i;
		queens(q + 1);
	}
}

int main()
{
	scanf("%d", &N);
	queens(0);
	return 0;
}