#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;	//N (3 ≤ N ≤ 8)
vector<int> v;

void solution() {
	int answer = 0, sum = 0;
	sort(v.begin(), v.end());

	do {
		for (int i = 1; i < N; ++i)
			sum += abs(v[i] - v[i - 1]);

		if (answer < sum)
			answer = sum;
		sum = 0;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << answer;
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	v.assign(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> v[i];
	
	solution();
	return 0;
}

//v.size()에서 나오는 결과 값은 unsigned int 형태!!!!!!