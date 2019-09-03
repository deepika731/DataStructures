#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int stack[11],top = -1;
void push(int data)
{
	if(top == MAXSIZE-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[++top] = data;
		printf("element successfully pushed\n");
	}
}
int pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		stack[top--];
		printf("Successfully Poped\n");
		return stack[top+1];
	}
}
int size()
{
	return top;
}
int IsEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsFull()
{
	if(top == MAXSIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("\t| %d  |\n",stack[i]);
	}
}
int main()
{
	push(1);
	display();
	push(2);
	display();
	push(3);
	display();
	push(4);
	display();
	printf("%d\n",pop());
	printf("%d\n",pop());
}
