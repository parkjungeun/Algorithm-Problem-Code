#include<iostream>
#include<vector>

using namespace std;

void solution(int test, vector<vector<int> > sum) {
	int maxVal = 0;
	int lineSum = 0;

	cout << '#' << test << ' ';

	for (int i = 0; i < 100; i++) {
		lineSum = 0;
		for (int j = 0; j < 100; j++)
			lineSum += sum[i][j];

		if (maxVal < lineSum)
			maxVal = lineSum;
	}

	for (int i = 0; i < 100; i++) {
		lineSum = 0;
		for (int j = 0; j < 100; j++)
			lineSum += sum[j][i];

		if (maxVal < lineSum)
			maxVal = lineSum;
	}

	lineSum = 0;
	for (int i = 0; i < 100; i++)
		lineSum += sum[i][i];
	if (maxVal < lineSum)
		maxVal = lineSum;

	lineSum = 0;
	for (int i = 0; i < 100; i++)
		lineSum += sum[i][100 - i - 1];
	if (maxVal < lineSum)
		maxVal = lineSum;

	cout << maxVal << endl;
}


int main() {
	int _test = 0;
	vector<vector<int> > sum(100, vector<int>(100, 0));
	for (int test = 1; test <= 10; test++) {
		cin >> _test;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				cin >> sum[i][j];
		}
		solution(_test, sum);
	}
	return 0;
}