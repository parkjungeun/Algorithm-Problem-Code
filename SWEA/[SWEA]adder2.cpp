#include<iostream>
#include<vector>

using namespace std;

void solution(int test, vector<vector<int> > ladder)
{
	vector<int> start;
	int x, y;
	for (int i = 0; i < 100; i++) {
		if (ladder[0][i] == 1)
			start.push_back(i);
	}
	//cout << "SIZE : " << start.size() << endl;
	int minDist = 10001, Dist = 0, minX = 0;
	for (int i = 0; i < start.size(); i++)
	{
		y = 0; x = start[i];	Dist = 0;

		while (1) {
			if (x > 0 && ladder[y][x - 1]) {
				while (x > 0 && ladder[y][x - 1]) {
					x--;	Dist++;
				}
			}
			else if (x < 99 && ladder[y][x + 1]) {
				while (x < 99 && ladder[y][x + 1]) {
					x++;	Dist++;
				}
			}
			y++; Dist++;

			if (y == 99) {
				if (minDist >= Dist) {
					minDist = Dist;	minX = start[i];
				}
				break;
			}
		}
		//cout << "#" << start[i] << " : " << Dist << endl;
	}
	cout << '#' << test << ' ' << minX << endl;
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