#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<int> num;
stack<string> op;

int solution(string str)
{
	int sum = 0, check = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (i % 2 == 0) {
			if (check == 1) {
				int n = (str[i] - '0')*num.top();
				num.pop();
				num.push(n);
				check = 0;
			}
			else
				num.push(str[i] - '0');
		}
		else if (str[i] == '*') {
			check = 1;
		}
	}

	while(!num.empty())
	{
		sum += num.top();
		num.pop();
	}
	return sum;
}

int main()
{
	int n;
	string str;

	for (int i = 1; i <= 10; i++) {
		cin >> n;
		cin >> str;
		cout << "#" << i << " " << solution(str) << endl;
	}
}