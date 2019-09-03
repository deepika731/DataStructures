#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};
struct Queue
{
	struct BinaryTreeNode *node;
	struct Queue *next;
};
struct Queue *Q = NULL;
struct BinaryTreeNode *root = NULL;
void EnQueue(struct BinaryTreeNode *node)
{
	struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
	newNode->node = node;
	newNode->next = NULL;
	if(Q == NULL)
	{
		Q = newNode;
	}
	else
	{
		struct Queue *current;
		current = Q;
		while(current->next!=NULL)
		{
			current = current -> next;
		}
		current->next = newNode;
	}
}
struct BinaryTreeNode* DeQueue()
{
	if(Q == NULL)
	{
		return NULL;
	}
	else
	{
		struct Queue *current;
		current = Q;
		Q = Q->next;
		return current->node;
	}
	
}
int IsEmptyQueue()
{
	if(Q == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void InsertInBinaryTree(int data)
{
	struct BinaryTreeNode *temp;
	struct BinaryTreeNode *newNode;
	newNode = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	else
	{
		EnQueue(root);
		while(!IsEmptyQueue())
		{
			temp = DeQueue();
			if(temp->left)
			{
				EnQueue(temp->left);
			}
			else
			{
				temp->left = newNode;
				Q = NULL;
				return;
			}
			if(temp->right)
			{
				EnQueue(temp->right);
			}
			else
			{
				temp->right = newNode;
				Q = NULL;
				return;
			}
		}
	}	
	Q = NULL;
}
void InOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		InOrder(root->left);
		printf("%d->",root->data);
		InOrder(root->right);
	}
}
void preOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		printf("%d->",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d->",root->data);
	}
}
void LevelOrder()
{
	struct BinaryTreeNode *temp;
	Q = NULL;
	if(root == NULL)
	{
		printf("there are no nodes to display\n");
	}
	else
	{
		EnQueue(root);
		while(!IsEmptyQueue())
		{
			temp = DeQueue();
			printf("%d->",temp->data);
			if(temp->left)
			{
				EnQueue(temp->left);
			}
			if(temp->right)
			{
				EnQueue(temp->right);
			}
		}
	}
	printf("\n");
}
int FindMax(struct BinaryTreeNode *root)
{
	int root_val,left,right,max = 0;
	if(root!=NULL)
	{
		root_val = root->data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left>right)
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
int FindInBinaryTree(struct BinaryTreeNode *root,int data)
{
	int temp;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		if(data == root->data)
		{
			return 1;
		}
		temp = FindInBinaryTree(root->left,data);
		if(temp!=0)
		{
			return temp;
		}
		else
		{
			return FindInBinaryTree(root->right,data);
		}
	}
}
int SizeOfBinaryTree(struct BinaryTreeNode *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		return (SizeOfBinaryTree(root->left) + 1 + (SizeOfBinaryTree(root->right)));
	}
}
void DeleteBinaryTree(struct BinaryTreeNode *root)
{
	if(root == NULL)
	{
		return;
	}
	DeleteBinaryTree(root->left);
	DeleteBinaryTree(root->right);
	free(root);
}
int HeightOfBinaryTree(struct BinaryTreeNode *root)
{
	int leftheight,rightheight;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		leftheight = HeightOfBinaryTree(root->left);
		rightheight = HeightOfBinaryTree(root->right);
		if(leftheight > rightheight)
		{
			return leftheight+1;
		}
		else
		{
			return rightheight+1;
		}
	}
}
int FindHeightOfBinaryTree(struct BinaryTreeNode *root)
{
	int level = 0;
	Q = NULL;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		EnQueue(root);
		EnQueue(NULL);
		while(!IsEmptyQueue())
		{
			root = DeQueue();
			if(root == NULL)
			{
				if(!IsEmptyQueue())
				{
					EnQueue(NULL);
				}
				level++;
			}
			else
			{
				if(root->left)
				{
					EnQueue(root->left);
				}
				if(root->right)
				{
					EnQueue(root->right);
				}
			}
		}
	}
	return level;
}
int NumberOfLeavesInBinaryTree(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	Q = NULL;
	int count = 0;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		EnQueue(root);
		while(!IsEmptyQueue())
		{
			temp = DeQueue();
			if(!temp->left && !temp->right)
			{
				count++;
			}
			else
			{
				if(temp->left)
				{
					EnQueue(temp->left);
				}
				if(temp->right)
				{
					EnQueue(temp->right);
				}
			}
		}
	}
	return count;
}
int main()
{
	InsertInBinaryTree(1);
	InsertInBinaryTree(2);
	InsertInBinaryTree(3);
	InsertInBinaryTree(4);
	InsertInBinaryTree(5);
	InsertInBinaryTree(6);
	InsertInBinaryTree(7);
	LevelOrder();
	InOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	printf("maximum element in the tree is:\t%d\n",FindMax(root));
	FindInBinaryTree(root,5)?printf("element found\n"):printf("element not found\n");
	printf("size of Binary Tree is:\t%d\n",SizeOfBinaryTree(root));
	//DeleteBinaryTree(root);
	//LevelOrder();
	printf("height of the binary tree is:\t%d\n",HeightOfBinaryTree(root));
	printf("height of the binary tree is:\t%d\n",FindHeightOfBinaryTree(root));
	printf("number of leaves in binsry tree is:\t%d\n",NumberOfLeavesInBinaryTree(root));
}
