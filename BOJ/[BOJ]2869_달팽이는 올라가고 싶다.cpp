//https://www.acmicpc.net/problem/2869
#include<stdio.h>

int main() {
	int A, B, V, day = 1;
	scanf("%d %d %d", &A, &B, &V);

	if (A >= V)
		printf("1");
	else {
		day += (V - A) / (A - B);
		if ((V - A) % (A - B))
			day++;
		printf("%d", day);
	}
	return 0;
}