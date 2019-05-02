//탐욕(Greedy) 알고리즘 : 회의실 배정 알고리즘
#include<iostream>

using namespace std;

struct meeting
{
	int start;
	int end;
};

int N;
meeting Meetings[10];

void sort()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (Meetings[i].end > Meetings[j].end)
			{
				meeting temp = Meetings[i];
				Meetings[i] = Meetings[j];
				Meetings[j] = temp;
			}
		}
	}
}

int solve()
{
	sort();
	
	int lastEnd = 0, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (Meetings[i].start < lastEnd)
			continue;

		printf("<start : %2d, end : %2d>\n", Meetings[i].start, Meetings[i].end);
		lastEnd = Meetings[i].end;
		cnt++;
	}
	return cnt;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Meetings[i].start >> Meetings[i].end;
	}

	cout << "최대 배정 개수 : " << solve() << endl;
	return 0;
}

/*
10
1 4 1 6 6 10 5 7 3 8 5 9 3 5 8 11 2 13 12 14
*/