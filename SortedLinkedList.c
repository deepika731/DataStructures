#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode *next;
};
struct ListNode *head=NULL;
void display()
{
	struct ListNode *current;
	current = head;
	if(head == NULL)
	{
		printf("there are no nodes to display\n");
	}
	else
	{
		while(current!=NULL)
		{
			printf("%d->",current->data);
			current = current->next;
		}
		printf("\n");
	}
}
		
void insertion()
{
	int ch;
	int data,p;
	struct ListNode *newnode,*current,*previous;
	newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data = data;
	newnode->next = NULL;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		current = head;
		while(current!=NULL)
		{
			if(head->data > data)
			{
				newnode -> next = head;
				head = newnode;
				break;
			}
			else if(current->data < data && current->next != NULL && current->next->data > data)
			{
				newnode->next = current ->next;
				current->next = newnode;
				break;
			}
			else if(current->data < data && current->next == NULL)
			{
				current->next = newnode;
			}
			else
			{
				current = current -> next;
			}
		}
	}
			
}

int main()
{
	display();
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	DeleteDuplicates();
	display();
}

