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
struct ListNode* ReverseLinkedList(struct ListNode *head)
{
	struct ListNode *temp = NULL,*nextNode = NULL;
	while(head)
	{
		nextNode = head -> next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp;
}
void MiddleElement()
{
	struct ListNode *slowptr,*fastptr,*temp1,*temp2,*temp;
	int c = 0;
	slowptr =  head;
	fastptr = head;
	while(fastptr->next!=NULL)
	{
		slowptr = slowptr->next;
		c++;
		fastptr = fastptr->next->next;
	}
	c = c+2;
	printf("count - %d\n",c);
	temp = slowptr->next;
	slowptr->next = ReverseLinkedList(temp);
	temp1 = head;
	temp2 = slowptr->next;
	
	while(temp2->next!=NULL)
	{
		struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->data = temp2->data;
		newNode->next = temp1->next;
		temp1->next = newNode;
		temp1 = temp1->next->next;
		temp2 = temp2->next;
	}
	struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->data = temp2->data;
	newNode->next = temp1->next;
	temp1->next = newNode;
	slowptr->next = NULL;
	display();	
}
void PrintListFromEnd(struct ListNode *head)
{
	while(!head)
	{
		return;
	}
	PrintListFromEnd(head->next);
	printf("%d->",head->data);
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
	MiddleElement();
	

}

