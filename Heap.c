#include<stdio.h>
#include<stdlib.h>
struct Heap
{
	int *array;
	int count;
	int capacity;
	int heap_type;
};
struct Heap* CreateHeap(int capacity,int heap_type)
{
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	h ->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int)*h->capacity);
	return h;
}
int Parent(struct Heap* h,int i)
{
	if(i<=0 || i>=h->count)
	{
		return -1;
	}
	return i-1/2;
}
int leftChild(struct Heap *h,int i)
{
	int left = 2*i+1;
	if(left >= h->count)
	{
		return -1;
	}
	return left;
}
int rightChild(struct Heap *h,int i)
{
	int right = 2*i+2;
	if(right >= h->count)
	{
		return -1;
	}
	return right;
}
int GetMaximum(struct Heap *h)
{
	if(h->count == 0)
	{
		return -1;
	}
	return h->array[0];
}
void PercolateDown(struct Heap *h,int i)
{
	int l,r,max,temp;
	l = leftChild(h,i);
	r = rightChild(h,i);
	if(l!=-1 && h->array[l]>h->array[i])
	{
		max = l;
	}
	else
	{
		max = i;
	}
	if(r!=-1 && h->array[r] > h->array[max])
	{
		max = r;
	}
	if(max!=i)
	{
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
	}
	PercolateDown(h,max);
}
int DeleteMax(struct Heap *h)
{
	int data;
	if(h->count==0)
	{
		return -1;
	}
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--;
	PercolateDown(h,0);
	return data;
}
int Insert(struct Heap *h,int data)
{
	int i;
	/*if(h->count == h->capacity)
	{
		ResizeHeap(h);
	}*/
	h->count++;
	i = h->count-1;
	while(i>=0 && data > h->array[(i-1)/2])
	{
		h->array[i] = h->array[(i-1)/2];
		i = i-1/2;
	}
	h->array[i] = data;
}
/*void ResizeHeap(struct Heap *h)
{
	int *array_old = h->array;
	h->array = (int *)malloc(sizeof(int)*h->capacity*2);
	for(int i=0;i<h->capacity;i++)
	{
		h->array[i] = array_old[i];
	}
	h->capacity*=2;
	free(array_old);
}*/
void DestroyHeap(struct Heap *h)
{
	if(h==NULL)
	{
		return;
	}
	free(h->array);
	free(h);
	h=NULL;
}
void display(struct Heap* h)
{
	for(int i=0;i<h->count;i++)
	{
		printf("%d->",h->array[i]);
	}
	printf("\n");
}
int main()
{
	struct Heap* h;
	h = CreateHeap(10,1);
	Insert(h,1);
	Insert(h,2);
	Insert(h,3);
	Insert(h,4);
	display(h);
}

