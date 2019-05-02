//C풀이
#include <stdio.h>

int main() {
	char str[101];
	//입력이 성공적으로 받았으면 1을 반환
	while (scanf("%[^\n]\n", str) == 1)
		printf("%s\n", str);
	return 0;
}

//C++ 풀이
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {
		cout << str << endl;
	}
	return 0;
}