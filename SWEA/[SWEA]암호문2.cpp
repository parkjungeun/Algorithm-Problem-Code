#include<iostream>
#include<list>

using namespace std;

int main()
{
	int N1, N2;	//���� ��ȣ���� ����, �߰��� ��ȣ���� ����
	int pass;	//��ȣ��

	for (int test = 1; test <= 10; test++)
	{
		list<int> password;	//��ȣ��
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
					password.insert(listPtr, s);	//�����ϸ�, ������ ��ġ�� ����Ŵ.
				}
			}
			else if (command == 'D') {
					listPtr = password.begin();
					for (int k = 0; k < x; k++)
						listPtr++;
					
					for (int j = 0; j < y; j++) {
						listPtr = password.erase(listPtr);	//�����ϸ�, �� ���� ���Ҹ� ����Ŵ.
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