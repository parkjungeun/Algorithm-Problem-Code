#include<iostream>
#include<cstring>
#define MAX_N 1001
using namespace std;
bool map[MAX_N];
int main() {
	int cnt = 0, N, K;
	cin >> N >> K;
	memset(map, true, sizeof(map));

	for (int i = 2; i <= N; ++i) {
		if (map[i] == false)	continue;
		else {
			cnt++;
			if (cnt == K) { cout << i;	return 0; }
		}
		for (int j = i * i; j <= N; j += i) {
			if (map[j] == false)	continue;
			else {
				map[j] = false; cnt++;
				if (cnt == K) { cout << j;	return 0; }
			}
		}
	}
}