#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>
#include<vector>

#define MAX_N 51	//2 �� N �� 50
#define MAX_M 13	//1 �� M �� 13
#define INT_MAX 2e9

using namespace std;

int map[MAX_N][MAX_N], choose_chicken[MAX_M];
int M, N, minDist = INT_MAX;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

void solution(int n, int depth) {
	
	//��� ���� ���õ� ġŲ �� ������ �ּҰ� ���ϱ�.
	if (depth == M) {
		int sumDist = 0;

		//���� ���� ���� ���� ġŲ�� ���� ���� �ִ� �Ÿ��� �̱� 
		for (int i = 0; i < house.size(); ++i) {
			int dist = INT_MAX;
			for (int j = 0; j < chicken.size(); ++j) {
				if (!choose_chicken[j])
					continue;

				int d = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);

				if (d < dist)	dist = d;

				//printf("�� (%d %d)�� ġŲ��(%d %d) ���� �Ÿ� %d\n", house[i].second, house[i].first, chicken[j].second, chicken[j].first, r + c);
				if (dist == 1)	break;
			}
			sumDist += dist;
		}

		if (sumDist < minDist)
			minDist = sumDist;
		
		return;
	}
	
	int sz = chicken.size();
	for (int i = n; i < sz; ++i) {
		choose_chicken[i] = 1;
		solution(i + 1, depth + 1);
		choose_chicken[i] = 0;
	}
	return;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			scanf("%d", &map[r][c]);
			if (map[r][c] == 1)	//�� ����
				house.push_back(make_pair(r, c));
			else if (map[r][c] == 2)	//ġŲ �� ����
				chicken.push_back(make_pair(r, c));
		}
	}

	solution(0,0);

	printf("%d", minDist);
	return 0;
}