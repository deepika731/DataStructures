#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode *next;
};
//struct ListNode *head=NULL;
void display(struct ListNode *head)
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
		
void insertion(struct ListNode **head)
{
	int ch;
	int data,p;
	struct ListNode *newnode,*current,*previous;
	newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	printf("enter data:");
	scanf("%d",&data);
	newnode->data = data;
	newnode->next = NULL;
	printf("1.insertion at the starting\n2.insertion at the given position\n3.insertion at the ending\nenter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(*head == NULL)
		{
			*head = newnode;
			(*head)->next = NULL;
		}
		else
		{
			newnode->next = *head;
			(*head) = newnode;
		}
	}
	else if(ch==2)
	{
		int k = 1;
		if(*head == NULL)
		{
			*head = newnode;
			(*head)->next = NULL;
		}
		else
		{
			printf("enter position:");
			scanf("%d",&p);
			if(p==1)
			{
				newnode->next = *head;
				*head = newnode;
			}
			else
			{
				current = *head;
				while(current->next!=NULL)
				{
					k++;
					if(k==p)
					{
						break;
					}
					current = current->next;
					previous = current;
				}
				newnode->next = current->next;
				current->next = newnode;
			}
		}
	}
	else if(ch==3)
	{
		if(*head == NULL)
		{
			*head = newnode;
			(*head)->next = NULL;
		}
		else
		{
			current = *head;
			while(current->next!=NULL)
			{
				
				current = current->next;
			}
			current->next = newnode;
			newnode->next = NULL;
			
		}
	}
			
}
void CommonElements(struct ListNode *a,struct ListNode *b)
{
	struct ListNode *current1,*current2,*current3=NULL,*result=NULL;
	for(current1 = a;current1->next!=NULL;current1 = current1->next)
	{
		for(current2 = b;current2->next!=NULL;current2 = current2->next)
		{
			if(current1->data == current2->data)
			{
				if(result == NULL)
				{
					struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
					newNode->data = current1->data;
					newNode->next = NULL;
					result = newNode;
					current3 = result;
				}
				else
				{
					struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
					newNode->data = current1->data;
					newNode->next = NULL;
					current3->next = newNode;
					current3 = current3->next;
				}
			}
		}
	}
	if(current1->data == current2->data)
	{
		struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->data = current1->data;
		newNode->next = NULL;
		current3->next = newNode;
		current3 = current3->next;
	}
	display(result);
}
	
int main()
{
	struct ListNode *a=NULL,*b=NULL,*result=NULL;
	insertion(&a);
	display(a);
	insertion(&a);
	display(a);
	insertion(&a);
	display(a);
	insertion(&a);
	display(a);
	insertion(&a);
	display(a);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	insertion(&b);
	display(b);
	CommonElements(a,b);
	
}

