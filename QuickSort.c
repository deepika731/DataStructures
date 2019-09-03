#include<stdio.h>
#include<stdlib.h>
void display(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}
int Partition(int A[],int low,int high)
{
	int left,right,pivot_item = A[low],temp;
	left = low;
	right = high;
	while(left<right)
	{
		while(A[left]<=pivot_item)
		{
			left++;
		}
		while(A[right]>pivot_item)
		{
			right--;
		}
		if(left<right)
		{
			temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
	}
	A[low] = A[right];
	A[right] = pivot_item;
	return right;
}
void QuickSort(int A[],int low,int high)
{
	int pivot;
	if(high>low)
	{
		pivot = Partition(A,low,high);
		QuickSort(A,low,pivot);
		QuickSort(A,pivot+1,high);
	}
}

int main()
{
	int A[5] = {3,5,2,8,1},temp[5];
	QuickSort(A,0,5);
	display(A,5);
}
