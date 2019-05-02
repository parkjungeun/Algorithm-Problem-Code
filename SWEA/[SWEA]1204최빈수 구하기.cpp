#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v(101);

int main()
{
	int test, testNum, n;
	scanf("%d", &test);


	for (int t = 1; t <= test; ++t) {
		scanf("%d", &testNum);

		for (int i = 0; i < 1000; ++i) {
			scanf("%d", &n);
			v[n]++;
		}

		int max = -1, maxIdx = -1;
		for (int i = 0; i < 101; ++i) {
			if (max <= v[i]) {
				max = v[i];
				maxIdx = i;
			}
		}

		printf("#%d %d\n", testNum, maxIdx);
		v.clear();	v.assign(101, 0);
	}
	return 0;
}