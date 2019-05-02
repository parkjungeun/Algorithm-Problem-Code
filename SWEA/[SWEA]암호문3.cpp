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
			cin >> command;

			if (command == 'I') {
				cin >> x >> y;

				//���ϴ� ��ġ�� �����ϱ� ����, �������������� �� ��ġ�� ã�� �κ�
				listPtr = password.begin();
				for (int j = 0; j < x; j++)	
					listPtr++;

				//insert, ������ �� ��ġ�� ����Ŵ.
				int s;
				for (int k = 0; k < y; k++)
				{
					cin >> s;
					password.insert(listPtr, s);
				}
			}
			else if (command == 'D') {
				cin >> x >> y;

				//���ϴ� ��ġ�� �����ϱ� ����, �������������� �� ��ġ�� ã�� �κ�
				listPtr = password.begin();
				for (int k = 0; k < x; k++)
					listPtr++;

				//�����ϸ�, �� ���� ���Ҹ� ����Ŵ.
				//������ ��, ���ڸ��� �޿���. ����Ͽ� ������ ������ũ erase
				for (int j = 0; j < y; j++) {
					listPtr = password.erase(listPtr);	
				}
			}
			else if (command == 'A') {
				cin >> y;

				//�� �ڿ� �߰����ִ� �κ�.
				int s;
				for (int j = 0; j < y; j++) {
					cin >> s;
					password.push_back(s);
				}
			}
		}

		//ó������ 10���� ���� ���
		listPtr = password.begin();
		cout << "#" << test << " ";
		for (int i = 0; i < 10; i++)
			cout << *(listPtr++) << " ";
		cout << endl;
	}
	return 0;
}