#include <stdio.h>
#include <vector>
#include <iostream>
#define LONG_MAX 0x7fffffffffffffff;
#define ll long long

using namespace std;

int test, N;
double E;

typedef struct point {
	int x;	int y;
} Point;

long long calcDist(Point p1, Point p2) {
	ll L = (ll)(p1.x - p2.x)*(ll)(p1.x - p2.x) + (ll)(p1.y - p2.y)*(ll)(p1.y - p2.y);
	return L;
}

void solution(vector<Point> v) {

	int size = v.size();
	ll ans = 0;
	vector<bool> visit(size);
	vector<ll> Dist(size);

	for (int i = 0; i < size; ++i) {
		visit[i] = false;
		Dist[i] = LONG_MAX;
	}

	Dist[0] = 0;

	for (int i = 0; i < size; ++i) {
		int minVertex = 0;
		ll minDist = LONG_MAX;

		for (int j = 0; j < size; ++j) {
			if (!visit[j] && minDist>Dist[j]) {
				minDist = Dist[j];
				minVertex = j;
			}
		}

		visit[minVertex] = true;
		ans += Dist[minVertex];
		
		for (int j = 0; j < size; ++j) {
			if (!visit[j]) {
				ll dist = calcDist(v[minDist], v[j]);
				if (Dist[j] > dist)
					Dist[j] = dist;
			}
		}
	}



	cout << fixed;
	cout.precision(0);
	cout << (long long)ans * E << "\n";
	return;
}

int main()
{
	int x, y;

	cin >> test;
	for (int i = 1; i <= test; ++i) {
		cin >> N;

		vector <Point> v(N);
		for (int j = 0; j < N; j++)
			cin >> v[j].x;

		for (int j = 0; j < N; j++)
			cin >> v[j].y;

		cin >> E;

		cout << "#" << i << " ";	solution(v);
	}
	return 0;
}