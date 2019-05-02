#include<iostream>
using namespace std;
int main() {
	int num;
	cin >> num;

	if (num >= 90 && num <= 100)
		cout << 'A';
	else if (num >= 80 && num < 90)
		cout << 'B';
	else if (num >= 70 && num < 80)
		cout << 'C';
	else if (num >= 60 && num < 70)
		cout << 'C';
	else
		cout << 'F';
	return 0;
}