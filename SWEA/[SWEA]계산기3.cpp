#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int len, ans = 0;
char c;

void calculate(vector<char> v) 
{
	stack<char> st;		//연산자들을 넣는 벡터
	vector<int> res;	//숫자들을 넣는 벡터

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == '(')
			st.push(v[i]);
		else if (v[i] == ')')	//괄호 내의 연산을 해서, res벡터에 저장
		{
			while (st.top() != '(' && !st.empty())
			{
				char ch = st.top();
				st.pop();

				int num2 = res.at(res.size() - 1);
				res.pop_back();
				int num1 = res.at(res.size() - 1);
				res.pop_back();

				if (ch == '+') 
					res.push_back(num1 + num2);
				else          
					res.push_back(num1 * num2);
			}
			st.pop();	// '('을 빼는 부분
		}
		else if (v[i] == '*') 
		{
			while (!st.empty() && st.top() == '*') 
			{
				char ch = st.top();
				st.pop();

				int num2 = res.at(res.size() - 1);
				res.pop_back();
				int num1 = res.at(res.size() - 1);
				res.pop_back();

				if (ch == '+')  
					res.push_back(num1 + num2);
				else            
					res.push_back(num1 * num2);
			}
			st.push(v[i]);
		}
		else if (v[i] == '+') 
		{
			while (!st.empty() && (st.top() == '+' || st.top() == '*')) 
			{
				char ch = st.top();
				st.pop();

				int num2 = res.at(res.size() - 1);
				res.pop_back();
				int num1 = res.at(res.size() - 1);
				res.pop_back();

				if (ch == '+') 
					res.push_back(num1 + num2);
				else            
					res.push_back(num1 * num2);
			}
			st.push(v[i]);
		}
		else //숫자일때
			res.push_back(v[i] - '0');
	}//for

	while (!st.empty())
	{
		char ch = st.top();
		st.pop();

		int num2 = res.at(res.size() - 1);
		res.pop_back();
		int num1 = res.at(res.size() - 1);
		res.pop_back();

		if (ch == '+')  
			res.push_back(num1 + num2);
		else           
			res.push_back(num1 * num2);
	}
	ans = res[0];
}

int main() {
	for (int testCase = 1; testCase <= 10; testCase++) 
	{
		cin >> len;

		vector<char> v;
		for (int i = 0; i < len; i++) 
		{
			cin >> c;
			v.push_back(c);
		}

		calculate(v);
		cout << "#" << testCase << " " << ans << "\n";
	}
}