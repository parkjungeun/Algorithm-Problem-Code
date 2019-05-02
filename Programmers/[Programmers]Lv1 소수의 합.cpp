#include <iostream>
#include <vector>
#define MAX_N 10000001
using namespace std;

vector<int> v(MAX_N);

void check(int N) {
	for (int i = 2; i <= N; ++i) {
		for (int j = i * 2; j <= N; j += i) {
			if (v[j] != 1)
				v[j] = 1;
		}
	}
}

long long solution(int N) {
	long long answer = 0;
	check(N);
	for (int i = 2; i <= N; ++i) {
		if (!v[i]) {
			answer += i;
			//cout << i << " ";
		}
	}
	return answer;
}

int main() {
	cout<<solution(10);
	return 0;
}