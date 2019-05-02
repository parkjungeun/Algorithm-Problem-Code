#include<iostream>
#include<vector>

using namespace std;

void solution(int test, vector<vector<int> > ladder) 
{
	int start = 0;
	int x, y;
	for (int i = 0; i < 100; i++) {
		if (ladder[99][i] == 2) {
			start = i;
			break;
		}
	}

	y = 99; x = start;
	while (y != 0) {

		if (ladder[y][x - 1] == 1) {
			while (x > 0 && ladder[y][x - 1] == 1)
				x--;
		}
		else if (ladder[y][x + 1] == 1) {
			while (x < 99 && ladder[y][x + 1] == 1)
				x++;
		}
		y--;

		if (y == 0) {
			cout << '#' << test << ' ' << x << endl;
			return;
		}
	}
}

int main() {
	int _test = 0;
	vector<vector<int> > ladder(100, vector<int>(100, 0));
	for (int test = 1; test <= 10; test++) {
		cin >> _test;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				cin >> ladder[i][j];
		}
		solution(test, ladder);
	}
	return 0;
}