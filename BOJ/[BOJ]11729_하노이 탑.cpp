#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

void HanoiTop_recursive(int N, int from, int tmp, int to) {
	if (N == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	//N-1개를 A -> (C를 거쳐) -> B로 옮긴다.
	HanoiTop_recursive(N - 1, from, to, tmp);
	//남은 1개를 A->C로 옮긴다.
	cout << from << ' ' << to << '\n';
	//N-1개를 B -> (A를 거쳐 C로 옮긴다.)
	HanoiTop_recursive(N - 1, tmp, from, to);
}

void HanoiTop_stack(int N, int from, int tmp, int to) {
	stack<int> s;
	int done = 0;

	while (!done) {
		while (N > 1) {
			s.push(to);
			s.push(tmp);
			s.push(from);
			s.push(N);
			N--;
			s.push(to);
			to = tmp;
			tmp = s.top();
			s.pop();
		}
		cout << from << ' ' << to << '\n';

		if (!s.empty()) {
			N = s.top(); s.pop();
			from = s.top(); s.pop();
			tmp = s.top(); s.pop();
			to = s.top(); s.pop();
			cout << from << ' ' << to << '\n';
			N--;
			s.push(from);
			from = tmp;
			tmp = s.top(); s.pop();
		}
		else
			done = 1;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	cout << (int)pow(2, N) - 1 << '\n';

	cout << "HanoiTop_recursive" << '\n';
	if (20 >= N)   HanoiTop_recursive(N, 1, 2, 3);

	cout << "\nHanoiTop_stack" << '\n';
	if (20 >= N)    HanoiTop_stack(N, 1, 2, 3);
	return 0;
}