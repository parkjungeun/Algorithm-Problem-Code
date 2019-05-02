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
			cin >> command;

			if (command == 'I') {
				cin >> x >> y;

				//원하는 위치에 삽입하기 위해, 시작점에서부터 그 위치를 찾는 부분
				listPtr = password.begin();
				for (int j = 0; j < x; j++)	
					listPtr++;

				//insert, 삽입한 그 위치를 가리킴.
				int s;
				for (int k = 0; k < y; k++)
				{
					cin >> s;
					password.insert(listPtr, s);
				}
			}
			else if (command == 'D') {
				cin >> x >> y;

				//원하는 위치에 삭제하기 위해, 시작점에서부터 그 위치를 찾는 부분
				listPtr = password.begin();
				for (int k = 0; k < x; k++)
					listPtr++;

				//삭제하면, 그 다음 원소를 가리킴.
				//삭제한 뒤, 빈자리를 메워줌. 계속하여 삭제할 갯수만크 erase
				for (int j = 0; j < y; j++) {
					listPtr = password.erase(listPtr);	
				}
			}
			else if (command == 'A') {
				cin >> y;

				//맨 뒤에 추가해주는 부분.
				int s;
				for (int j = 0; j < y; j++) {
					cin >> s;
					password.push_back(s);
				}
			}
		}

		//처음부터 10개의 값만 출력
		listPtr = password.begin();
		cout << "#" << test << " ";
		for (int i = 0; i < 10; i++)
			cout << *(listPtr++) << " ";
		cout << endl;
	}
	return 0;
}