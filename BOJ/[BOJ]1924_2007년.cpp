#include<iostream>
#include<string>
using namespace std;

int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string Day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
	int x, y;
	cin >> x >> y;

	//1월 1일이 월요일
	int day = 0;
	for (int i = 0; i < x - 1; i++)
		day += mon[i];
	day += y;
	cout << Day[day % 7];
	return 0;
}