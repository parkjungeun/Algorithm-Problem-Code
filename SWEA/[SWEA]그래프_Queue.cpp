#include<stdio.h>
#define QUEUE_SIZE 5

int Queue[QUEUE_SIZE];
int front, rear;

bool isEmpty()
{
	if (front == rear)
		return true;
	return false;
}

bool isFull()
{
	if ((rear + 1) % QUEUE_SIZE == front)
		return true;
	return false;
}

void enqueue(int n)
{
	if (isFull()) {
		printf("Queue is Full\n");
		return;
	}

	rear = (rear + 1) % QUEUE_SIZE;
	Queue[rear] = n;
	return;
}

int dequeue()
{
	if (isEmpty()){
		printf("Queue is Empty\n");
		return -999;
	}

	front = (front + 1) % QUEUE_SIZE;
	return Queue[front];
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	printf("%d ", dequeue());
	printf("%d ", dequeue());
	printf("%d ", dequeue());
	printf("%d ", dequeue());
	dequeue();
	return 0;
}