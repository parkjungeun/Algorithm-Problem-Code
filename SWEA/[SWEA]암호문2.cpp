#include<iostream>
#include<list>

using namespace std;

int main()
{
	int N1, N2;	//원본 암호문의 길이, 추가할 암호문의 갯수
	int pass;	//암호문

	for (int test = 1; test <= 10; test++)
	{
		list<int> password;	//암호문
		list<int>::iterator listPtr;

		cin >> N1;
		for (int i = 0; i < N1; i++) {
			cin >> pass;
			password.push_back(pass);
		}

		cin >> N2;
		for (int i = 0; i < N2; i++) 
		{
			char command;
			int x, y;
			cin >> command >> x >> y;

			if (command == 'I') {
				listPtr = password.begin();

				for (int j = 0; j < x; j++)
					listPtr++;

				int s;
				for (int k = 0; k < y; k++)
				{
					cin >> s;
					password.insert(listPtr, s);	//삽입하면, 삽입한 위치를 가리킴.
				}
			}
			else if (command == 'D') {
					listPtr = password.begin();
					for (int k = 0; k < x; k++)
						listPtr++;
					
					for (int j = 0; j < y; j++) {
						listPtr = password.erase(listPtr);	//삭제하면, 그 다음 원소를 가리킴.
					}
			}
		}

		listPtr = password.begin();
		cout << "#" << test << " ";
		for (int i = 0; i < 10; i++)
			cout << *(listPtr++) << " ";
		cout << endl;
	}
	return 0;
}