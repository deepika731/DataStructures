#include<stdio.h>
#include<stdlib.h>
struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};
struct BinaryTree *root;
void PreOrder(struct BinaryTree *root)
{
	if(root)
	{
		printf("%d->",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PreOrderNonRecursive(struct BinaryTree *root)
{
	struct Stack *S = CreateStack();
	while(1)
	{
		while(root)
		{
			printf("%d->",root->data);
			Push(S,root);
			root = root->left;
		}
		if(IsEmptyStack(S))
		{
			break;
		}
		root = Pop(S);
		root = root -> right;
	}
	DeleteStack(S);
}
void InOrder(struct BinaryTree *root)
{
	if(root)
	{
		InOrder(root->left);
		printf("%d->",data);
		InOrder(root->right);
	}
}
void InOrderNonRecursive(struct BinaryTree *root)
{
	struct Stack *S = CreateStack();
	while(1)
	{
		while(root)
		{
			Push(S,root);
			root = root->left;
		}
		if(IsEmptyStack(S))
		{
			break;
		}
		root = Pop(S);
		printf("%d->",root->data);
		root = root->right;
	}
	DeleteStack(S);
}
void PostOrder(struct BinaryTree *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d->",root->data);
	}
}
void PostOrderNonRecursive(struct BinaryTree *root)
{
	struct Stack *S = CreateStack();
	do
	{
		while(root)
		{
			Push(S,root);
			root = root->left;
		}
		while(root==NULL && !IsEmptyStack(S))
		{
			root = Top(S);
			if(root->right == NULL || root->right == previous)
			{
				printf("%d->",root->data);
			}
			Pop(S);
			previous = root;
			root = NULL;
			else
			{
				root = root->right;
			}
		}
	}while(!IsEmptyStack(S));
	DeleteStack(S);
}
void LeverOrder(struct BinaryTree *root)
{
	struct BinaryTree *temp;
	struct Queue *Q = CreateQueue();
	if(!root)
		return;
	EnQueue(Q,root);
	while(!IsEmptyQueue(Q))
	{
		temp = DeQueue(Q);
		printf("%d->",temp->data);
		if(temp->left)
		{
			EnQueue(Q,temp->left);
		}
		if(temp->right)
		{
			EnQueue(Q,temp->right);
		}
	}
	DeleteQueue(Q);
}
int FindMax(struct BinaryTree *root)
{
	int root_val,right,left,max = 0;
	if(root!=NULL)
	{
		root_val = root->data;
		left = FindMax(root->left);
		right = Findmax(root->right);
		if(left>right);
		{
			max = left;
		}
		else
		{
			max = right;
		}
		if(root_val>max)
		{
			max = root_val;
		}
	}
	return max;
}
void InsertInBinaryTree(struct BinaryTree *root,int data)
{
	struct Queue *Q;
	struct BinaryTree *temp,*newNode;
	newNode = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
	newNode->left = newNode->right = NULL;
	if(!root)
	{
		root = newNode;
	}
	else
	{
		Q = CreateQueue();
		EnQueue(Q,root);
		while(!IsEmptyQueue(Q))
		{
			temp = DeQueue(Q);
			if(temp->left)
			{
				EnQueue(Q,temp->left);
			}
			else
			{
				temp->left = newNode;
				DeleteQueue(Q);
			}
			if(temp->right)
			{
				EnQueue(Q,temp->right);
			}
			else
			{
				temp->right = newNode;
				DeleteQueue(Q);
			}
		}
		DeleteQueue(Q);
	}
}
