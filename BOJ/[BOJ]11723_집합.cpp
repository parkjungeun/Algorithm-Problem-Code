#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string str;	int M, x, ans = 0;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> str >> x;	cin.clear();
		x -= 1;
		if (!str.compare("add")) {
			ans |= (1 << x);
		}
		else if (!str.compare("remove")) {
			ans &= ~(1 << x);
		}
		else if (!str.compare("check")) {
			if (ans & (1 << x))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!str.compare("toggle")) {
			ans ^= (1 << x);
		}
		else if (!str.compare("all")) {
			ans = (1 << x) - 1;
		}
		else if (!str.compare("empty")) {
			ans = 0;
		}
	}
}