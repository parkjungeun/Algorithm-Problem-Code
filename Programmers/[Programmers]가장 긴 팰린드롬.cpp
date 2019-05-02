#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s) {
	int answer = 0;
	int len = strlen(s);

	for (int i = 0; i < len; ++i) {
		//정답보다 작아지면, 어차피 답이 아님!	(subLen > answer)
		//여기서 subLen이 팰린드롬의 길이가 된다.
		for (int subLen = len; subLen > answer; subLen--) {
			int left = i;				    //i번 째,
			int right = left + subLen - 1;	//항상 오른쪽 끝 부터 시작하고, 1칸씩 줄어듬.

			//right가 범위를 넘어가면 continue
			if (right >= len)
				continue;

			//같으면 계속 양옆에서 줄여옴
			while (left < right && s[left] == s[right]) {
				left++;
				right--;
			}

			//left, right가 서로 교차하고 현재 subLen이
			//답보다 길면 현재 위치에서 최대 팰린드롬 길이임! (break)
			if (left >= right && answer < subLen) {
				answer = subLen;
				break;
			}
		}
	}
	return answer;
}