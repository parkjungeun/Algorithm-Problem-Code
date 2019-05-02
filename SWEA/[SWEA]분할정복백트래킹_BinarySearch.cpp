#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define N 10

using namespace std;

int BinarySearch(int arr[], int size, int key)
{
	int low = 0, high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int key)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == key)		//원하는 값을 찾았을 때,
		return mid;
	else if (arr[mid] > key)	//찾는 값이 지금보다 왼쪽에 있음.
		recursiveBinarySearch(arr, low, mid - 1, key);
	else						//찾는 값이 지금보다 오른쪽에 있음.
		recursiveBinarySearch(arr, mid + 1, high, key);
}

int main()
{
	int arr[N] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "recursiveBinarySearch Idx : " << recursiveBinarySearch(arr, 0, N - 1, 27) << endl;
	cout << "BinarySearch Idx : " << BinarySearch(arr, N, 27) << endl;
	return 0;
}