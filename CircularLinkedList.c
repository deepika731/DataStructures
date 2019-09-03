#include<stdio.h>
#include<stdlib.h>
struct CLLNode
{
	int data;
	struct CLLNode *next;
};
struct CLLNode *head = NULL;
void display()
{
	struct CLLNode *current;
	current = head;
	while(current->next != head)
	{
		printf("%d->",current->data);
		current = current->next;
	}
		printf("%d->",current->data);
	printf("\n");
}
void insertion()
{
	struct CLLNode *current,*newnode;
	int data;
	newnode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data = data;
	newnode->next = newnode;
	printf("1.insertion at the beginning\n2.insertion at given position\n3.insertion at the end\nenter your choice:");
	int ch;
	scanf("%d",&ch);
	if(ch==1)
	{
		if(head == NULL)
		{
			head = newnode;
			head->next = head;
		}
		else
		{
			newnode->next = head;
			current = head;
			while(current->next!=head)
			{
				current =current->next;
			}
			current->next = newnode;
			head = newnode;
			
			
		}
	}
	else if(ch == 2)
	{
		int p,k=1;
		printf("enter position:");
		scanf("%d",&p);
		current = head;
		while(current->next != head)
		{
			k++;
			if(p==k)
			{
				break;
			}
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
	else if(ch==3)
	{
		current = head;
		while(current->next != head)
		{
			current = current->next;
		}
		newnode->next = head;
		current->next = newnode;
	}
}
void deletion()
{
	struct CLLNode *current;
	int ch,p,k=1;
	printf("1.deletion at the beginning\n2.deletion at given position\n3.deletion at the end\nenter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		current = head;
		while(current->next != head)
		{
			current = current->next;
		}
		head = head->next;
		current->next = head;
	}
	else if(ch==2)
	{
		printf("enter position:");
		scanf("%d",&p);
		current = head;
		while(current->next != head)
		{
			k++;
			if(k==p)
			{
				break;
			}
			current = current->next;
		}
		current->next = current->next->next;
	}
	else if(ch==3)
	{
		current = head;
		while(current->next->next != head)
		{
			current = current->next;
		}
		current->next = head;
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
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
}
			
