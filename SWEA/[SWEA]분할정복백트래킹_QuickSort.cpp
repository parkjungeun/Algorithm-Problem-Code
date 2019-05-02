#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define N 10

using namespace std;

void quickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = left;
	int l = left + 1;
	int r = right;

	while (1)
	{
		while (arr[pivot] > arr[l])
			l++;
		while (arr[pivot] < arr[r])
			r--;

		if (l < r) {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
		else {
			int temp = arr[pivot];
			arr[pivot] = arr[r];
			arr[r] = temp;
			break;
		}
	}
	quickSort(arr, left, r - 1);
	quickSort(arr, r + 1, right);
	return;
}

void showArr(int arr[])
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

int main()
{
	int arr[N] = { 10,9,8,7,6,5,4,3,2,1 };

	cout << "정렬 전 : ";	showArr(arr);

	quickSort(arr, 0, N - 1);

	cout << "정렬 후 : ";	showArr(arr);
	return 0;
}