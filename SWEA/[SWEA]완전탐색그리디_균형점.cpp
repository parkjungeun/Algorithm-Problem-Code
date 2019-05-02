//1245. [S/W �����ذ� ����] 2���� - ������ D5 
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

struct obj
{
	int x;
	int weight;
};

//�ڼ�ü�� ��ü ������ �Ÿ�(d)�� �ڼ�ü�� ��ü�� ����(m)
//�� ���� �ڼ�ü���� ���� ���� ������ �ڼ�ü���� ���� ���� ���� ���� ������
void solve(struct obj object[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		//�� �ڼ�ü�� ��ġ
		double left_F, right_F;
		double left = object[i].x, right = object[i + 1].x, ans = 0;

		//�� �ȿ� �ڼ�ü�� x���� �����ؾ���.
		while (1)
		{
			double mid = (left + right) / 2;
			left_F = 0.0; right_F = 0.0;

			//��ü�� ���� �ڼ�ü���� �η� ��
			for (int j = 0; j <= i; j++) {
				double d = (mid - object[j].x);
				left_F += (object[j].weight / (d*d));
			}

			//��ü�� ������ �ڼ�ü���� �η� ��
			for (int j = i + 1; j < N; j++) {
				double d = (mid - object[j].x);
				right_F += (object[j].weight / (d*d));
			}

			double res = left_F - right_F;

			//�� ��ǥ�� ������ 1e-12 ���Ͽ����ϰ�,
			//������ �� ũ����, �� ���� �η��� ������ �� ���� ������!
			if ((abs(right - left) <= (1e-12)) || (res == 0)) {
				printf("%.10f ", mid);
				break;
			}

			if (res > 0)		//������ �� ŭ.
				left = mid;
			else if (res < 0) //�������� �� ŭ.
				right = mid;
		}
	}
	std::cout << endl;
	return;
}

int main()
{
	int testCase, N;

	cin >> testCase;
	for (int test = 1; test <= testCase; test++)
	{
		cin >> N;

		struct obj object[10];
		for (int j = 0; j < N; j++)
			cin >> object[j].x;

		for (int j = 0; j < N; j++)
			cin >> object[j].weight;

		std::cout << "#" << test << " ";
		solve(object, N);
	}
	return 0;
}