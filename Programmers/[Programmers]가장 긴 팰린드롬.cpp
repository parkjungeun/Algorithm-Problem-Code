#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s) {
	int answer = 0;
	int len = strlen(s);

	for (int i = 0; i < len; ++i) {
		//���亸�� �۾�����, ������ ���� �ƴ�!	(subLen > answer)
		//���⼭ subLen�� �Ӹ������ ���̰� �ȴ�.
		for (int subLen = len; subLen > answer; subLen--) {
			int left = i;				    //i�� °,
			int right = left + subLen - 1;	//�׻� ������ �� ���� �����ϰ�, 1ĭ�� �پ��.

			//right�� ������ �Ѿ�� continue
			if (right >= len)
				continue;

			//������ ��� �翷���� �ٿ���
			while (left < right && s[left] == s[right]) {
				left++;
				right--;
			}

			//left, right�� ���� �����ϰ� ���� subLen��
			//�亸�� ��� ���� ��ġ���� �ִ� �Ӹ���� ������! (break)
			if (left >= right && answer < subLen) {
				answer = subLen;
				break;
			}
		}
	}
	return answer;
}