#include<iostream>
#include<vector>
using namespace std;

int main() {
	int A, X, n;
	cin >> A >> X;

	vector<int> v;
	for (int i = 0; i < A; ++i) {
		cin >> n;
		if (n < X)	v.push_back(n);
	}

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	return 0;
}
