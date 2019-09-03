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
void addListNumbers(struct ListNode *list1,struct ListNode *list2,int *carry,struct ListNode **result)
{
	int sum;
	if(!list1)
	{
		return;
	}
	addListNumbers(list1->next,list2->next,carry,result);
	struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	sum = list1->data+list2->data+(*carry);
	*carry = sum/10;
	sum = sum%10;
	temp->data = sum;
	temp->next = (*result);
	*result = temp;
	return;
}
void addRemainingNumbers(struct ListNode *list1,int *carry,struct ListNode **result,int diff)
{
	int sum =0;
	if(!list1 || diff==0)
	{
		return;
	}
	addRemainingNumbers(list1->next,carry,result,diff);
	struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	sum = list1->data+(*carry);
	*carry = sum/10;
	sum = sum%10;
	temp->data = sum;
	temp->next = (*result);
	*result = temp;
	return;
}
void addListNumbersWrapper(struct ListNode *list1,struct ListNode *list2,int *carry,struct ListNode **result)
{
	int List1Length=0,List2Length=0,diff=0;
	struct ListNode *current = list1;
	while(current)
	{
		current = current->next;
		List1Length++;
	}
	current = list2;
	while(current)
	{
		current = current->next;
		List2Length++;
	}
	if(List1Length<List2Length)
	{
		current = list1;
		list1 = list2;
		list2 = current;
	}
	diff = abs(List1Length-List2Length);
	current = list1;
	while(diff--)
	{
		current = current->next;
	}
	addListNumbers(current,list2,carry,result);
	diff = abs(List1Length-List2Length);
	addRemainingNumbers(list1,carry,result,diff);
	if(*carry)
	{
		struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->next = (*result);
		*result = temp;
	}
	return;
}
	
int main()
{
	struct ListNode *a=NULL,*b=NULL,*result=NULL;
	int *carry;
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
	addListNumbersWrapper(a,b,carry,&result);
	display(result);
}

