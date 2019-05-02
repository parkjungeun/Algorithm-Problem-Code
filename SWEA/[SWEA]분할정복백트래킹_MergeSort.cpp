#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define N 10

using namespace std;
/*
void mergeSort(int arr[], int size)
{
	if (size == 1)
		return;

	int mid = size / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);	//arr는 배열의 처음을 가리키는 포인터 이므로,
										//mid를 더하여 시작 위치를 재정의 해줌

	int *buf = new int[size];
	int i = 0, j = mid, k = 0;	// i : 왼쪽 버퍼의 시작 idx
								// j : 오른쪽 버퍼의 시작 idx
								// k : 임시버퍼에 정렬된 값이 저장될 idx

	while (i < mid && j < size)
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];

	while (i < mid)		// 왼쪽버퍼에 아직 더 담을 값이 남았을 때, 나머지 넣기
		buf[k++] = arr[i++];

	while (j < size)	// 오른쪽버퍼에 아직 더 담을 값이 남았을 때, 나머지 넣기
		buf[k++] = arr[j++];

	for (int i = 0; i < size; i++)	//본 배열에 정렬된 값이 저장된 배열의 값 복사하여 넣기
		arr[i] = buf[i];

	delete buf;
}
*/

void mergeSort(int arr[], int size)
{
	if (size == 1)
		return;

	int mid = size / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);

	int* buf = new int[size];
	int left = 0, right = mid, idx = 0;

	while (left < mid &&right < size)
	{
		if (arr[left] < arr[right])
			buf[idx++] = arr[left++];
		else
			buf[idx++] = arr[right++];
	}

	while (left < mid)
		buf[idx++] = arr[left++];

	while (right < size)
		buf[idx++] = arr[right++];

	for (int i = 0; i < size; i++) {
		arr[i] = buf[i];
	}

	delete buf;
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

	mergeSort(arr, N);
	
	cout << "정렬 후 : ";	showArr(arr);
	return 0;
}