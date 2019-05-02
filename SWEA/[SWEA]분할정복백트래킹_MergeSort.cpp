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
	mergeSort(arr + mid, size - mid);	//arr�� �迭�� ó���� ����Ű�� ������ �̹Ƿ�,
										//mid�� ���Ͽ� ���� ��ġ�� ������ ����

	int *buf = new int[size];
	int i = 0, j = mid, k = 0;	// i : ���� ������ ���� idx
								// j : ������ ������ ���� idx
								// k : �ӽù��ۿ� ���ĵ� ���� ����� idx

	while (i < mid && j < size)
		buf[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];

	while (i < mid)		// ���ʹ��ۿ� ���� �� ���� ���� ������ ��, ������ �ֱ�
		buf[k++] = arr[i++];

	while (j < size)	// �����ʹ��ۿ� ���� �� ���� ���� ������ ��, ������ �ֱ�
		buf[k++] = arr[j++];

	for (int i = 0; i < size; i++)	//�� �迭�� ���ĵ� ���� ����� �迭�� �� �����Ͽ� �ֱ�
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

	cout << "���� �� : ";	showArr(arr);

	mergeSort(arr, N);
	
	cout << "���� �� : ";	showArr(arr);
	return 0;
}