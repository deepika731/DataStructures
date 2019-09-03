#include<stdio.h>
#include<stdlib.h>
struct ArrayQueue
{
	int front,rear;
	int *array;
	int capacity;
};
struct ArrayQueue *Queue(int size)
{
	struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
	if(!Q)
	{
		return NULL;
	}
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if(!Q->array)
	{
		return NULL;
	}
	return Q;
}
int IsEmptyQueue(struct ArrayQueue *Q)
{
	return (Q->front == -1);
}
int IsFullQueue(struct ArrayQueue *Q)
{
	return ((Q->rear + 1)%Q->capacity == Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
	return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
void EnQueue(struct ArrayQueue *Q,int data)
{
	if(IsFullQueue(Q))
	{
		printf("Queue overflow\n");
	}
	else
	{
		Q->rear = (Q->rear +1)%Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front == -1)
		{
			Q->front = Q->rear;
		}
	}
}
int DeQueue(struct ArrayQueue *Q)
{
	int data = 0;
	if(IsEmptyQueue(Q))
	{
		printf("Queue underflow");
		return -1;
	}
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
		{
			Q->front = Q->rear = -1;
		}
		else
		{
			Q->front = (Q->front + 1)%Q->capacity;
		}
	}
	return data;
}
void DeleteQueue(struct ArrayQueue *Q)
{
	if(Q)
	{
		if(Q->array)
		{
			free(Q->array);
		}
		free(Q);
	}
	else
	{
		printf("Queue does not exist\n");
	}
}
void DisplayQueue(struct ArrayQueue *Q)
{
	if(Q->rear == Q->front)
	{
		printf("there are no elements in queue\n");
	}
	else
	{
		for(int i=0;i<Q->rear;i++)
		{
			printf("%d->",Q->array[i]);
		}
		printf("\n");
	}
}
	
int main()
{
	struct ArrayQueue *Q = NULL;
	Q = Queue(6);
	EnQueue(Q,1);
	DisplayQueue(Q);
	EnQueue(Q,2);
	DisplayQueue(Q);
	EnQueue(Q,3);
	DisplayQueue(Q);
	EnQueue(Q,4);
	DisplayQueue(Q);
	EnQueue(Q,5);
	DisplayQueue(Q);
	EnQueue(Q,6);
	DisplayQueue(Q);
	EnQueue(Q,7);
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DisplayQueue(Q);
	printf("%d\n",DeQueue(Q));
	DeleteQueue(Q);
	DisplayQueue(Q);
}
