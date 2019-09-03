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
struct ListNode *GetKPlusOneThNode(int k,struct ListNode *head)
{
	struct ListNode *Kth;
	int i=0;
	if(!head)
	{
		return head;
	}
	for(i=0,Kth = head;Kth && i<k;i++,Kth=Kth->next);
	if(i==k && Kth!=NULL)
	{
		return Kth;
	}
	return head->next;
}
int HasKNodes(struct ListNode *head,int k)
{
	int i=0;
	for(i=0;head && i<k;i++,head = head->next);
	if(i==k)
		return 1;
	return 0;
}
struct ListNode *ReverseBlockOfKNodesInLinkedList(struct ListNode *head,int k)
{
	struct ListNode *current = head,*temp,*next,*newHead;
	int i;
	if(k==0 || k==1)
	{
		return head;
	}
	if(HasKNodes(current,k-1))
	{
		newHead = GetKPlusOneThNode(k-1,current);
	}
	else
	{
		newHead = head;
	}
	while(current && HasKNodes(current,k))
	{
		temp = GetKPlusOneThNode(k,current);
		i = 0;
		while(i<k)
		{
			next = current->next;
			current->next = temp;
			temp = current;
			current = next;
			i++;
		}
	}
	return newHead;
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
	insertion();
	display(head);
	insertion();
	display(head);
	head = ReverseBlockOfKNodesInLinkedList(head,3);
	display(head);
}

