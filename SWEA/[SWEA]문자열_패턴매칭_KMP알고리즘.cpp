#include<stdio.h>
#include<string.h>
#define MAX_N 100

int next[MAX_N];

//next�迭�� ���ϴ� �Լ�
void kmp(char* pattern) {
	int n = strlen(pattern);
	int i = -1, j = 0;

	next[j] = i;

	while (j < n) {
		//i��°���� ������ ��ġ�� ���,
		//���ư� ��ġ�� ��Ÿ���� i+1�� next�迭�� ����
		if (i == -1 || (i >= 0 && pattern[i] == pattern[j])) {
			++i;
			++j;
			next[j] = i;
		}
		else //��ġ���� �ʾ��� ��, ���ư� ��ġ�� ���ư����� ��ݺ�
			i = next[i];
	}
}

int main()
{
	return 0;
}