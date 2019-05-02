
//https://www.acmicpc.net/problem/1475
#include<iostream>
#include<string>

#define MAX_SIZE 7

using namespace std;

string N;
int num[10];	//���ڰ��� ī��Ʈ

int solution() {

	for (int i = 0; i < N.length(); ++i) {
		if (N[i] - '0' == 9)	num[6]++;
		else	num[N[i] - '0']++;
	}

	int maxCnt = -1, maxNum = -1;
	for (int i = 0; i < 9; ++i) {
		if (maxCnt < num[i]) {	//1�� �̻� �ʿ��� ���ڵ� ����
			maxCnt = num[i];
			maxNum = i;
		}
	}
//	cout << maxNum << ", " << maxCnt << endl;

	if (maxNum == 6) {
		if (maxCnt % 2)	maxCnt = ++maxCnt / 2;
		else	maxCnt /= 2;
	}
	return maxCnt;
}

int main() {
	cin >> N;
	cout << solution();
	return 0;
}