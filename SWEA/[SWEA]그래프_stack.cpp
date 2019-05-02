#include<stdio.h>
#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;

bool isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

bool isFull()
{
	if (top == STACK_SIZE - 1)
		return true;
	return false;
}

void push(int n)
{
	if (isFull()) {
		printf("Stack is Full\n");
		return;
	}

	top++;
	stack[top] = n;
	return;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack is Empty ");
		return -999;
	}

	int tmp = stack[top];
	top--;
	return tmp;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}