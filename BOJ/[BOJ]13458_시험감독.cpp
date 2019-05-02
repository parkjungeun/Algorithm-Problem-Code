#include<iostream>
#include<vector>
#define MAX_N 1000000
using namespace std;

int room[MAX_N];
int N;	//������ ����
int B, C;	//�� ������, �ΰ����� ��簡���� �л� ��

long long solution() {
	long long ans = 0;	//������ ��

	//�� ���� ���� �� ����
	for (int i = 0; i < N; ++i) {
		room[i] -= B;
		ans++;
	}

	for (int i = 0; i < N; ++i) {
		if (room[i] > 0) {
			ans += (room[i] / C);
			room[i] %= C;
			if (room[i])	ans++;
		}
	}
	return ans;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> room[i];
	
	cin >> B >> C;
	cout << solution();
	return 0;
}
