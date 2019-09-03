#include<stdio.h>
#include<stdlib.h>
struct DynArrayQueue
{
	int front,rear;
	int *array;
	int capacity;
};
struct DynArrayQueue* CreateDynamicQueue()
{
	struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
	if(!Q)
	{
		return NULL;
	}
	Q->capacity = 1;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if(!Q->array)
	{
		return NULL;
	}
	return Q;
}
void ResizeQueue(struct DynArrayQueue *Q)
{
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = realloc(Q->array,Q->capacity);
	if(!Q->array)
	{
		printf("Memory Error\n");
	}
	if(Q->front > Q->rear)
	{
		for(int i = 0;i<Q->front;i++)
		{
			Q->array[i+size] = Q->array[i];
		}
	}
	Q->rear = Q->rear + size;
}
int IsEmptyDynQueue(struct DynArrayQueue *Q)
{
	return (Q->front == -1);
}
int IsFullDynQueue(struct DynArrayQueue *Q)
{
	return ((Q->rear +1)%Q->capacity == Q->front);
}
int DynQueueSize(struct DynArrayQueue *Q)
{
	return ((Q->front-Q->rear+1+Q->front)%Q->capacity);
}
void EnQueue(struct DynArrayQueue *Q,int data)
{
	if(IsFullDynQueue(Q))
	{
		ResizeQueue(Q);
	}
	Q->rear = (Q->rear + 1)%Q->capacity;
	Q->array[Q->rear] = data;
	if(Q->front == -1)
	{
		Q->front = Q->rear;
	}
}	
int DeQueue(struct DynArrayQueue *Q)
{
	int data = 0;
	if(IsEmptyDynQueue(Q))
	{
		printf("Queue is empty\n");
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
void DisplayQueue(struct DynArrayQueue *Q)
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
void DeleteQueue(struct DynArrayQueue *Q)
{
	if(Q)
	{
		if(Q->array)
		{
			free(Q->array);
		}
		free(Q);
	}
}
int main()
{
	struct DynArrayQueue *Q = NULL;
	Q = CreateDynamicQueue();
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
