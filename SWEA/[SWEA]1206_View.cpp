#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>

using namespace std;
vector <int> v;

int solution() {
	int size = v.size(), max = 0, side_max = 0;
	int ans = 0;

	for (int i = 2; i < size - 2; ++i) {
		max = v[i];

		//오른쪽 전망 확인
		if (v[i - 2] >= max || v[i - 1] >= max ||
			v[i + 2] >= max || v[i + 1] >= max)
			continue;

		if (v[i - 2] > v[i - 1])	
			side_max = v[i - 2];
		else	
			side_max = v[i - 1];

		if (v[i + 2] > side_max || v[i + 1] > side_max) {
			if (v[i + 2] > v[i + 1])	
				side_max = v[i + 2];
			else	
				side_max = v[i + 1];
		}

		ans += (v[i] - side_max);
	}
	return ans;
}

int main() {
	int N;

	for (int i = 1; i <= 10; ++i)  {
		scanf("%d", &N);
		v.clear();
		v.assign(N, 0);

		for (int j = 0; j < N; ++j)
			scanf("%d", &v[j]);
		
		printf("#%d %d\n", i, solution());
	}
}