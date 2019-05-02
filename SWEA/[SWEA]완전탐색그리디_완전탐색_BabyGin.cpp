#include<iostream>

#define N 6
int Nums[N];

using namespace std;

////3���� ���� ������, 1�� ���̳��� ���ӵ� �� �̸� run
int run(int a, int b, int c)
{
	if (((a + 1) == b) && ((b + 1) == c))
		return 1;
	return 0;
}

//3���� ���� ������, triple
int triple(int a, int b, int c)
{
	if ((a == b) && (a == c))
		return 1;
	return 0;
}

void show(int arr[])
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return;
}

//��� ����� �� Ž��
//arr[] : �Է¹��� ī���� ������ �����ؼ� �ӽ� ������ �迭
//pos : position���� ���� �ӽù迭�� ����� ��ġ(�� ��°����)�� ��Ÿ��
//used : �Է¹��� ī�� �� ���� ���� üũ�ϴ� ��. 
//		 (���� ī�尡 ����� �迭�� �ε����� �ǹ��Ͽ� �� �ε����� ���Ǿ��ٶ�� �ǹ̷� ��)
int solve(int arr[], int pos, int used)
{
	//6���� ī�� ��� ���Ǿ�����, ���� �˻�
	if (pos == 6)
	{
		int res = 0;

		//show(arr);

		//�տ� 3�� Ȥ�� �ڿ� 3�� ī���� ���� �������θ� ���� �κ�
		//1���� ���� �� run �Ǵ� triple �� �ϳ��� ����.
		//�� �����ϴ� ������ 2���̹Ƿ� res������ ������ ������ Ƚ���� count
		for (int i = 0; i < 2; i++)
		{
			if (run(arr[i * 3], arr[i * 3 + 1], arr[i * 3 + 2]))
				res++;
			if (triple(arr[i * 3], arr[i * 3 + 1], arr[i * 3 + 2]))
				res++;
		}

		//2���� ��� ������ �����Ǹ� Baby-Gin
		if (res == 2)
			return 1;

		return 0;
	}

	//��ͺκ��� ������ �׷�����
	//������ ���������� ������� ��ġ�� �ٲ㰡��
	//6���� ���� ������ ����� ������ ���� �� �� ����.

	for (int i = 0; i < N; i++)	//N�� ī���� ���� 6���� ����
	{
		if ((used & (1 << i)))	//�̹� ���� �� �̸�,
			continue;			//�ѱ�

		arr[pos] = Nums[i];
		if (solve(arr, pos + 1, used | (1 << i)))
			return 1;
	}
	return 0;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Nums[j];

		cout << '#' << i + 1;
		
		int arr[6];
		if (solve(arr, 0, 0))
			cout << " : Baby-Gin" << endl;
		else
			cout << " : Non Baby-Gin" << endl;
	}
	return 0;
}