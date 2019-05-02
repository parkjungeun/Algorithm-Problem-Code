#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node
{
	int num;
	char op;
	int left, right;
};
struct node* nodes;
vector<char> v;

int solution(int idx)
{
	if (nodes[idx].left != -1) {
		solution(nodes[idx].left - 1);
	}

	v.push_back(nodes[idx].op);

	if (nodes[idx].right != -1) {
		solution(nodes[idx].right - 1);
	}
	return 0;
}

int calc()
{
	for (int i = 0; i < v.size(); i++)
	{
		//숫자자리에 숫자가 아닌 것
		if (i % 2 == 0 && (v[i]<'0' && v[i]>'9')) {
			return 0;
		}
		else if (i % 2 == 1 && (v[i] >= '0' && v[i] <= '9')) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int N;
	for (int test = 1; test <= 10; test++)
	{
		cin >> N;
		nodes = (struct node*)malloc(sizeof(struct node)*N);

		if (N % 2 == 1) {
			for (int i = 0; i < N / 2; i++) {
				cin >> nodes[i].num >> nodes[i].op >> nodes[i].left >> nodes[i].right;
			}
		}
		else {
			int i;
			for (i = 0; i < (N / 2) - 1; i++) {
				cin >> nodes[i].num >> nodes[i].op >> nodes[i].left >> nodes[i].right;
			}

			cin >> nodes[i].num >> nodes[i].op >> nodes[i].left;
			nodes[i].right = -1;
		}

		for (int i = N / 2; i < N; i++) {
			cin >> nodes[i].num >> nodes[i].op;
			nodes[i].left = -1;
			nodes[i].right = -1;
		}

		solution(0);
		cout << "#" << test << " " << calc() << endl;
		v.clear();
		free(nodes);
	}
	return 0;
}