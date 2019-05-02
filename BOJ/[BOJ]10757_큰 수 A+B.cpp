/*
 10757번 : 큰 수 A+B
 https://www.acmicpc.net/problem/10757
  A+B ? (0 < A,B < 1010000)
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> v;;

void lastNumbers(string::reverse_iterator& tmp, string& str,int isUp) {
	while (tmp != str.rend()) {
		int n = *tmp - '0';

		if (isUp) { 
			n += isUp; isUp = 0;
		}

		if (n / 10 != 0)
			isUp = 1;

		v.push_back(n % 10);	tmp++;
	}
	if (isUp)
		v.push_back(1);
}

void solution(string num1, string num2) {
	string::reverse_iterator it1 = num1.rbegin();
	string::reverse_iterator it2 = num2.rbegin();

	int isUp = 0;
	while (it1 != num1.rend() && it2 != num2.rend()) {
		int n = *it1 - '0' + *it2 - '0';

		if (isUp) {
			n += isUp; isUp = 0; 
		}

		if (n / 10 != 0)
			isUp = 1;
		v.push_back(n % 10);
		it1++; it2++;
	}

	//제일 높은 자리
	if (it1 == num1.rend() && it2 == num2.rend() && isUp)
		v.push_back(1);
	else if (it1 == num1.rend())
		lastNumbers(it2, num2, isUp);
	else if (it2 == num2.rend())
		lastNumbers(it1, num1, isUp);

	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string num1, num2;

	cin >> num1 >> num2;
	solution(num1, num2);
	return 0;
}