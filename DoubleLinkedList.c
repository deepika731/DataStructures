#include<stdio.h>
#include<stdlib.h>
struct DLLNode
{
	int data;
	struct DLLNode *next,*prev;
};
struct DLLNode *head = NULL;
void display()
{
	struct DLLNode *current;
	current = head;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current = current->next;
	}
	printf("\n");
}
void insertion()
{
	struct DLLNode *current,*previous,*newnode;
	newnode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
	int data,ch;
	printf("enter data:");
	scanf("%d",&data);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	printf("1.interstion at beginning\n2.insertion at the given position\n3.insertion at the end\nenter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(head==NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}
	else if(ch==2)
	{
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			int p,k;
			printf("enter position:");
			scanf("%d",&p);
			k = 1;
			current = head;
			while(current->next!=NULL)
			{
				k++;
				if(k==p)
				{
					break;
				}
				current = current->next;
			}
			newnode->next = current->next;
			newnode->prev = current;
			current->next->prev = newnode;
			current->next = newnode;
		}
	}
	else if(ch==3)
	{
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			current = head;
			while(current->next!=NULL)
			{
				current = current->next;
			}
		}
		current->next = newnode;
		newnode->prev = current;
		newnode->next = NULL;
	}
}
void deletion()
{
	struct DLLNode *current;
	if(head==NULL)
	{
		printf("there are no nodes to delete\n");
	}
	else
	{
		printf("1.deletion at beginning\n2.deletion at given position\n3.deletion at the end\nenter your choice:");
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			head = head->next;
			head->prev = NULL;
		}
		else if(ch==2)
		{
			printf("enter position:");
			int p,k;
			scanf("%d",&p);
			k = 1;
			current = head;
			while(current->next!=NULL)
			{
				k++;
				if(k==p)
				{
					break;
				}
				current = current->next;
			}
			current->next = current->next->next;
			current->next->prev = current;
		}
		else if(ch==3)
		{
			current = head;
			while(current->next->next!=NULL)
			{
				current = current->next;
			}
			current->next = NULL;
		}
	}
}			
int main()
{
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	insertion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	
}
