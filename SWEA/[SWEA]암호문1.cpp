#include<iostream>
#include<list>
using namespace std;

int main()
{
	int len; //len : 암호문의 길이
	int N;   // N  : 명령어 갯수

	for (int test = 1; test <= 10; test++)
	{
		cin >> len;	//원본 암호문의 갯수
		list<int> v;
		int tmp;
		for (int i = 0; i < len; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		cin >> N;	//추가할 명령어의 갯수
		char I;
		int x, y, s;
		list<int>::iterator iterList;
		for (int j = 0; j < N; j++)
		{
			iterList = v.begin();
			cin >> I >> x >> y;
			
			for (int k = 0; k < x; k++)
				iterList++;
			
			for (int k = 0; k < y; k++) {
				cin >> s;
				v.insert(iterList, s);
			}
		}

		iterList = v.begin();
		cout << "#" << test << " ";
		for (int i = 0; i < 10; i++)
			cout << *(iterList++) << " ";
		cout << endl;
	}

}