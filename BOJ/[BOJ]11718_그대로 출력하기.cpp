//CǮ��
#include <stdio.h>

int main() {
	char str[101];
	//�Է��� ���������� �޾����� 1�� ��ȯ
	while (scanf("%[^\n]\n", str) == 1)
		printf("%s\n", str);
	return 0;
}

//C++ Ǯ��
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