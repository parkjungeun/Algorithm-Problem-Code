#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX_N 16
using namespace std;
vector<pair<int, int> > v;
int visited[MAX_N], N, Gain = 0;

void solution(int day) {
	if (day > N) {
		int sum = 0;
		for (int i = 1; i <= N; ++i) {
			if (!visited[i])
				continue;
			if (i + v[i].first - 1 <= N)
				sum += v[i].second;
		}
		if (sum > Gain)
			Gain = sum;
		return;
	}

	for (int i = day; i <= N; ++i) {
		visited[i] = 1;
		solution(i + v[i].first);
		visited[i] = 0;
	}
}

int main() {
	int t, p;
	cin >> N;
	v.assign(N + 1, make_pair(0, 0));

	for (int i = 1; i <= N; ++i) {
		cin >> t >> p;
		v[i] = make_pair(t, p);
	}

	solution(1);
	
	cout << Gain;
	return 0;
}