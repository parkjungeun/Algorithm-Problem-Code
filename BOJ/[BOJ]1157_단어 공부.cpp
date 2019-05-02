#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
pair<char, int> alpha[26];

bool cmp(pair<char, int> &a, pair<char, int> &b) {
	return a.second > b.second ? true : false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (char c = 'A'; c <= 'Z'; c++)
		alpha[c - 'A'].first = c;

	string str;	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		str[i] < 'a' ? alpha[str[i]-'A'].second++ : alpha[str[i] - 'a'].second++;
	
	sort(alpha, alpha + 26, cmp);

	if (alpha[0].second == alpha[1].second)
		cout << '?';
	else
		cout << alpha[0].first;
	return 0;
}