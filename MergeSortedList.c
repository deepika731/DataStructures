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
struct ListNode *MergeSortedList(struct ListNode *a,struct ListNode *b)
{
	struct ListNode *result = NULL;
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	if(a->data<=b->data)
	{
		result = a;
		result->next = MergeSortedList(a->next,b);
	}
	else
	{
		result = b;
		result->next = MergeSortedList(a,b->next);
	}
	return result;
}
struct ListNode *MergeSortIterative(struct ListNode *head1,struct ListNode *head2)
{
	struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *temp;
	newNode->next = NULL;
	temp = newNode;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		}
		else
		{
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}
	if(head1!=NULL)
	{
		temp->next = head1;
	}
	else
	{
		temp->next = head2;
	}
	temp = newNode->next;
	free(newNode);
	return temp;	
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
	result = MergeSortIterative(a,b);
	display(result);
}

