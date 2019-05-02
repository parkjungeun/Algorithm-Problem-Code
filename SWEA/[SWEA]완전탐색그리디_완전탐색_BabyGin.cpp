#include<iostream>

#define N 6
int Nums[N];

using namespace std;

////3개의 수가 같으면, 1씩 차이나는 연속된 수 이면 run
int run(int a, int b, int c)
{
	if (((a + 1) == b) && ((b + 1) == c))
		return 1;
	return 0;
}

//3개의 수가 같으면, triple
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

//모든 경우의 수 탐색
//arr[] : 입력받은 카드의 정보를 조합해서 임시 저장할 배열
//pos : position으로 현재 임시배열에 저장될 위치(몇 번째인지)를 나타냄
//used : 입력받은 카드 중 사용된 수를 체크하는 것. 
//		 (실제 카드가 저장된 배열의 인덱스를 의미하여 그 인덱스가 사용되었다라는 의미로 씀)
int solve(int arr[], int pos, int used)
{
	//6개의 카드 모두 사용되었으면, 조건 검사
	if (pos == 6)
	{
		int res = 0;

		//show(arr);

		//앞에 3개 혹은 뒤에 3개 카드의 조건 성립여부를 보는 부분
		//1개의 묶음 당 run 또는 triple 중 하나만 만족.
		//총 만족하는 조건은 2개이므로 res변수로 조건이 만족된 횟수를 count
		for (int i = 0; i < 2; i++)
		{
			if (run(arr[i * 3], arr[i * 3 + 1], arr[i * 3 + 2]))
				res++;
			if (triple(arr[i * 3], arr[i * 3 + 1], arr[i * 3 + 2]))
				res++;
		}

		//2묶음 모두 조건이 만족되면 Baby-Gin
		if (res == 2)
			return 1;

		return 0;
	}

	//재귀부분을 손으로 그려보면
	//숫자의 마지막부터 순서대로 위치를 바꿔가며
	//6개의 숫자 조합을 만들어 나가는 것을 알 수 있음.

	for (int i = 0; i < N; i++)	//N은 카드의 갯수 6으로 고정
	{
		if ((used & (1 << i)))	//이미 사용된 수 이면,
			continue;			//넘김

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