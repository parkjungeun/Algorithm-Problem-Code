#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node
{
	int num;
	char ch;
	int l;
	int r;
	struct node* left;
	struct node* right;
};
struct node* root = 0;

vector<struct node*> v;

void addToBST(int _num, char _ch, int _l, int _r)
{
	struct node* cur = (struct node*)malloc(sizeof(struct node));
	cur->num = _num;
	cur->ch = _ch;
	cur->l = _l;
	cur->r = _r;

	cur->left = 0;
	cur->right = 0;

	v.push_back(cur);

	return;
}

void makeBST()
{
	root = v[1];

	for (int i = v.size() - 1; i >= 2; i--)
	{
		if (v[i]->num % 2 == 1) {
			v[v[i]->num / 2]->right = v[i];
		}
		else if (v[i]->num % 2 == 0) {
			v[v[i]->num / 2]->left = v[i];
		}
	}
	return;
}

void inorder(struct node* _root)
{
	if (_root == 0)
		return;

	inorder(_root->left);
	cout << _root->ch;
	inorder(_root->right);
}

int main()
{
	int N, num, left, right;	//노트 개수
	char c;
	for (int test = 1; test <= 10; test++)
	{
		v.clear();
		v.push_back(NULL);
		cin >> N;

		if (N % 2 == 1) {
			for (int i = 0; i < N / 2; i++) {
				cin >> num >> c >> left >> right;
				addToBST(num, c, left, right);
			}
			for (int i = N / 2; i < N; i++) {
				cin >> num >> c;
				addToBST(num, c, 0, 0);
			}
		}
		else {
			for (int i = 0; i < (N / 2) - 1; i++) {
				cin >> num >> c >> left >> right;
				addToBST(num, c, left, right);
			}
			
			cin >> num >> c >> left;
			addToBST(num, c, left, 0);

			for (int i = N / 2; i < N; i++) {
				cin >> num >> c;
				addToBST(num, c, 0, 0);
			}
		}

		makeBST();

		cout << "#" << test << " ";
		inorder(root);
		cout << endl;
	}
	return 0;
}