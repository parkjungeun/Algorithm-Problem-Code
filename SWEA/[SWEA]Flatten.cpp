#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solution(int testCnt, int dump, vector<int> flat)
{
	int answer = 0;
	cout << '#' << testCnt << ' ';

	vector<int>::iterator minIt;
	vector<int>::iterator maxIt;
	for (int i = 0; i < dump; i++) {
		minIt = min_element(flat.begin(), flat.end());
		maxIt = max_element(flat.begin(), flat.end());

		(*maxIt)--;
		(*minIt)++;
	}
	minIt = min_element(flat.begin(), flat.end());
	maxIt = max_element(flat.begin(), flat.end());

	answer = *maxIt - *minIt;
	cout << answer << endl;
	return;
}

int main() {
	int dump;

	for (int i = 1; i <= 10; i++) {
		cin >> dump;
		vector<int> flat(100);
		for (int j = 0; j < 100; j++)
			cin >> flat[j];
		solution(i, dump, flat);
	}
	return 0;
}