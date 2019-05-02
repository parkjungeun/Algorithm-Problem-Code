#include<iostream>
#include<vector>

using namespace std;

void solution(vector<int> v)
{
	int front = 0;
	int rear = v.size() - 1;   //제일 마지막 위치를 가리킴. 이미 값이 모두 입력된 상태의 vector이기 때문,
	int num = 1;	//1~5까지 빼줌
	while (1)
	{
		v[front] = v[front] - num;  //맨 앞의 값에서 1씩 증가하며 빼야함.

		if (v[front] <= 0) {        //값이 0이하면, 모두 출력하고 종료.
			v[front] = 0;       //그 값은 0

			front = (front + 1) % v.size();   //front 1 증가

											  //front의 위치부터 모든(vector의 size만큼) 값 출력
											  //front % v.size를 한 이유?
											  //원형 큐처럼 동작해야하므로, 마지막 rear까지 출력하기 위해,
			for (int i = 0; i < v.size(); i++) {
				cout << v[front % v.size()] << " ";
				front++;
			}
			return;
		}

		front = (front + 1) % v.size();   //한 번 실행할 때마다, front변경

		rear++;                //처음 위치한 값이 마지막 값이 되어야 함.
		if (rear >= v.size())  //rear의 위치가 맨 마지막 위치를 넘으면, 다시 처음위치를 가리킴.
		{
			rear = 0;
		}

		num++;
		if (num == 6)   //1~5의 값을 반복하여 빼주기 위함.
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