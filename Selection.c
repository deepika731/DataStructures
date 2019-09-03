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
void selection(int A[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
			{
				min = j;
			}
		}
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
	display(A,n);
}

int main()
{
	int A[5] = {3,5,2,8,1};
	selection(A,5);
}
