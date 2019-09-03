#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode *next;
};
struct ListNode *head=NULL;
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
	printf("1.insertion at the starting\n2.insertion at the given position\n3.insertion at the ending\nenter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(head == NULL)
		{
			head = newnode;
			head->next = NULL;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	else if(ch==2)
	{
		int k = 1;
		if(head == NULL)
		{
			head = newnode;
			head->next = NULL;
		}
		else
		{
			printf("enter position:");
			scanf("%d",&p);
			if(p==1)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				current = head;
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
		if(head == NULL)
		{
			head = newnode;
			head->next = NULL;
		}
		else
		{
			current = head;
			while(current->next!=NULL)
			{
				
				current = current->next;
			}
			current->next = newnode;
			newnode->next = NULL;
			
		}
	}
			
}
struct ListNode *ReversePairRecursive(struct ListNode *head)
{
	struct ListNode *temp;
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		head->next->next = ReversePairRecursive(head->next->next);
		return head;
	}
}
struct ListNode *ReversePairIterative(struct ListNode *head)
{
	struct ListNode *temp1=NULL,*temp2=NULL,*current = head;
	while(current!=NULL && current->next != NULL)
	{
		if(temp1!=NULL)
		{
			temp1->next->next = current->next;
		}
		temp1 = current->next;
		current->next = current->next->next;
		temp1->next = current;
		if(temp2 == NULL)
		{
			temp2 = temp1;
		}
		current = current->next;
	}
	return temp2;
}
int main()
{
	display(head);
	insertion();
	display(head);
	insertion();
	display(head);
	insertion();
	display(head);
	insertion();
	display(head);
	head = ReversePairIterative(head);
	display(head);
	
}

