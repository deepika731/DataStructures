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
void deletion()
{
	struct ListNode *current,*previous;
	if(head == NULL)
	{
		printf("there are no nodes to delete\n");
	}
	else
	{
		int ch,p,k=1;
		printf("1.deletion at the head\n2.delete at the given position\n3.deletion at the end\nenter your choice:");
		scanf("%d",&ch);
		if(ch == 1)
		{
			head = head->next;
		}
		else if(ch==2)
		{
			printf("enter position:");
			scanf("%d",&p);
			if(p==1)
			{
				head = head->next;
			}
			else
			{
				current = head;
				while(current->next !=NULL)
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
			
		}
		else if(ch==3)
		{
			if(head->next == NULL)
			{
				head = NULL;
			}
			else
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
	
		
}
void FindNthNodeEnd()
{
	int length=0,i;
	struct ListNode *current;
	current = head;
	while(current!=NULL)
	{
		length++;
		current = current->next;
	}
	int n;
	printf("enter position:\t");
	scanf("%d",&n);
	current = head;
	i = 0;
	if(n>length)
	{
		printf("no such position exist\n");
	}
	else
	{
		while(current != NULL)
		{
			i++;
			if(i==length-n+1)
			{
				printf("the element in %d position from the end is %d\n",n,current->data);
				break;
			}
			current = current->next;
		}
	}
	
}
void FindNthNode()
{
	struct ListNode *ptemp,*pnthnode;
	int n;
	printf("enter postion:\t");
	scanf("%d",&n);
	ptemp = head;
	pnthnode = head;
	int i = 0;
	while(ptemp!=NULL)
	{
		if(i>=n)
		{
			pnthnode = pnthnode->next;
		}	
		ptemp = ptemp->next;
		i++;
	}
	printf("the node at position %d from the end is %d\n",n,pnthnode->data);
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
	/*deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();
	deletion();
	display();*/
	FindNthNode();

}

