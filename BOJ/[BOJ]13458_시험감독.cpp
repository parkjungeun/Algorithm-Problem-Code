#include<iostream>
#include<vector>
#define MAX_N 1000000
using namespace std;

int room[MAX_N];
int N;	//시험장 개수
int B, C;	//총 감독관, 부감독관 담당가능한 학생 수

long long solution() {
	long long ans = 0;	//감독관 수

	//총 감독 가능 수 제외
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
