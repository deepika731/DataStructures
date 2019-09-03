#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode *next,*prev;
};
struct ListNode *head=NULL;
void PushBackDeQueue(struct ListNode *head,int data)
{
	struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->data = data;
	if(head==NULL)
	{
		head = newNode;
		head->next = head;
		head->prev =head;
	}
	else
	{
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
	}
}
void PushFrontDeQueue(struct ListNode *head,int data)
{
	PushBackDeQueue(head,data);
	head = head->prev;
}
int PopBackDeQueue(struct ListNode *head)
{
	int data;
	if(head->prev == head)
	{
		data = head->data;
		free(head);
		head = NULL;
	}
	else
	{
		struct ListNode *newTail = head->prev->prev;
		data = head->prev->data;
		newTail->next = head;
		free(head->prev);
		head->prev = newTail;
	}
}
int PopFrontDeQueue(struct ListNode *head)
{
	int data;
	head = head->next;
	data = PopBackDeQueue(head);
	return data;
}
void display()
{
	if(head == NULL)
	{
		printf("there are no elements are in the queue\n");
	}
	else
	{
		struct ListNode *current = head;
		while(current->next!=head)
		{
			printf("%d->",current->data);
			current = current->next;
		}
		printf("\n");
	}
}
int main()
{
	PushFrontDeQueue(head,1);
	display();
	PushFrontDeQueue(head,1);
	display();
	PushFrontDeQueue(head,1);
	display();
	PushBackDeQueue(head,1);
	display();
	PushBackDeQueue(head,1);
	display();
	PushBackDeQueue(head,1);
	display();
	PushBackDeQueue(head,1);
	display();
	printf("%d\n",PopFrontDeQueue(head));
	display();
	printf("%d\n",PopFrontDeQueue(head));
	display();
	printf("%d\n",PopFrontDeQueue(head));
	display();
	printf("%d\n",PopBackDeQueue(head));
	display();
	printf("%d\n",PopBackDeQueue(head));
	display();
	printf("%d\n",PopBackDeQueue(head));
	display();
}
	
