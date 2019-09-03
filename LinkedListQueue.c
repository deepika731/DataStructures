#include<stdio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *next;
};
struct Queue *head=NULL;
void EnQueue(int data)
{
	struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
	struct Queue *current;
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		current = head;
		while(current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}
int DeQueue()
{
	if(head == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		int data;
		data = head->data;
		head = head->next;
		return data;
	}
}
void DeQueueAll()
{
	if(head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		head = NULL;	
	}
}
int isEmpty()
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int peak()
{
	if(head == NULL)
	{
		return -1;
	}
	else
	{
		return head->data;
	}
}

void display()
{
	struct Queue *current;
	if(head == NULL)
	{
		printf("the queue is empty\n");
	}
	else
	{
		current = head;
		while(current!=NULL)
		{
			printf("%d->",current->data);
			current = current->next;
		}
		printf("\n");
	}
}
int main()
{
	EnQueue(1);
	display();
	EnQueue(2);
	display();
	EnQueue(3);
	display();
	EnQueue(4);
	display();
	EnQueue(5);
	display();
	printf("%d\n",DeQueue());
	display();
	printf("%d\n",DeQueue());
	display();
	if(isEmpty())
	{
		printf("the queue is empty\n");
	}
	else
	{
		printf("the queue is not empty\n");
	}
	printf("%d\n",peak());
	DeQueueAll();
	display();
}
	

