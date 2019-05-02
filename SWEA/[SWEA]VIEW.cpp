#include<iostream>
#include<vector>
using namespace std;

void solution(int test, vector<int> view)
{
	int answer = 0;
	cout << '#' << test << ' ';

	for (int i = 2; i < view.size() - 2; i++)
	{
		int left = view[i - 2] > view[i - 1] ? view[i - 2] : view[i - 1];
		int right = view[i + 2] > view[i + 1] ? view[i + 2] : view[i + 1];

		if (left < view[i] && right < view[i]) {
			int max = left > right ? left : right;

			if (view[i] - max > 0)
				answer += (view[i] - max);
		}
		else
			continue;
	}
	cout << answer << endl;
	return;
}

int main() {
	int n;

	for (int i = 1; i <= 10; i++) {
		cin >> n;
		vector<int> view(n);
		for (int j = 0; j < n; j++)
			cin >> view[j];
		solution(i, view);
	}
	return 0;
}