#include<stdio.h>
#include<string.h>
#define MAX_N 100

int next[MAX_N];

//next배열을 구하는 함수
void kmp(char* pattern) {
	int n = strlen(pattern);
	int i = -1, j = 0;

	next[j] = i;

	while (j < n) {
		//i번째에서 패턴이 일치될 경우,
		//돌아갈 위치를 나타내는 i+1을 next배열에 저장
		if (i == -1 || (i >= 0 && pattern[i] == pattern[j])) {
			++i;
			++j;
			next[j] = i;
		}
		else //일치하지 않았을 때, 돌아갈 위치로 돌아간다음 재반복
			i = next[i];
	}
}

int main()
{
	return 0;
}