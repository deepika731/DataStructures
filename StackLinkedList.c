#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *head=NULL;
void push(int data)
{
	struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	printf("element successfully pushed\n");
}
int pop()
{
	int data;
	if(head==NULL)
	{
		printf("no elemets to pop\n");
		return -1;
	}
	else
	{
		data = head->data;
		head = head->next;
		printf("element successfully poped\n");
		return data;
	}
}
int top()
{
	if(head == NULL)
	{
		printf("no elements in stack\n");
		return -1;
	}
	else
	{
		return head->data;
	}
}
void display()
{
	struct stack *current;
	current = head;
	while(current!=NULL)
	{
		printf("\t| %d |\n",current->data);
		current = current->next;
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
	push(5);
	display();
	printf("%d\n",pop());
	printf("%d\n",pop());
	display();
}
