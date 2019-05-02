#include<iostream>
#include<vector>

using namespace std;

void solution(vector<int> v)
{
	int front = 0;
	int rear = v.size() - 1;   //���� ������ ��ġ�� ����Ŵ. �̹� ���� ��� �Էµ� ������ vector�̱� ����,
	int num = 1;	//1~5���� ����
	while (1)
	{
		v[front] = v[front] - num;  //�� ���� ������ 1�� �����ϸ� ������.

		if (v[front] <= 0) {        //���� 0���ϸ�, ��� ����ϰ� ����.
			v[front] = 0;       //�� ���� 0

			front = (front + 1) % v.size();   //front 1 ����

											  //front�� ��ġ���� ���(vector�� size��ŭ) �� ���
											  //front % v.size�� �� ����?
											  //���� ťó�� �����ؾ��ϹǷ�, ������ rear���� ����ϱ� ����,
			for (int i = 0; i < v.size(); i++) {
				cout << v[front % v.size()] << " ";
				front++;
			}
			return;
		}

		front = (front + 1) % v.size();   //�� �� ������ ������, front����

		rear++;                //ó�� ��ġ�� ���� ������ ���� �Ǿ�� ��.
		if (rear >= v.size())  //rear�� ��ġ�� �� ������ ��ġ�� ������, �ٽ� ó����ġ�� ����Ŵ.
		{
			rear = 0;
		}

		num++;
		if (num == 6)   //1~5�� ���� �ݺ��Ͽ� ���ֱ� ����.
			num = 1;
	}
}

int main()
{
	int n, tmp;
	for (int test = 1; test <= 10; test++)
	{
		vector<int> v(8);
		cin >> tmp;
		for (int i = 0; i < 8; i++) {
			cin >> n;
			v[i] = n;
		}
		cout << "#" << test << " ";
		solution(v);
		cout << "\n";
	}
}