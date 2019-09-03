#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10
char stack[11];
int top = -1;
void push(char data)
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
	char inp[10];
	printf("enter string:");
	scanf("%s",inp);
	int i = 0;
	for(i=0;i<strlen(inp);i++)
	{
		if(inp[i]=='x')
		{
			break;
		}
		push(inp[i]);
	}
	printf("%d\n",i);
	int n = i+1;
	for(i=n;i<strlen(inp);i++)
	{
		if(inp[i]!=pop())
		{
			printf("The string is not a palindrome\n");
			break;
		}
	}
	if(top == -1)
	{
		printf("The string is a palindrome\n");
	}
			
		
}
