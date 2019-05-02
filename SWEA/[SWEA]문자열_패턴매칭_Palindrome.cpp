#pragma warning (disable:4996)
#include<iostream>
#include<string>

using namespace std;

int first = 1;
//O(N)
void printStr(char str[], int len) {
	if (!first)
		printf(", ");
	first = 0;

	for (int i = 0; i < len; ++i)
		printf("%c", str[i]);
	
	return;
}

//O(N*N)
int findPalindrome(char str[]) {

	int len = strlen(str);

	for (int i = 0; i < len; ++i) {
		int l = i, r = i;

		while (str[l] == str[r] && l >= 0 && r < len) //길이가 홀수인 str
		{
			printStr(str + 1, r - l + 1);
			l--; r++;
		}
		l = i; r = i + 1;

		while (str[l] == str[r] && l >= 0 && r < len) //길이가 짝수인 str
		{	
			printStr(str + 1, r - l + 1);
			l--; r++;
		}
	}
	return 0;
}

int main()
{
	char* str = "";
	scanf("%s", str);

	findPalindrome(str);
	return 0;
}