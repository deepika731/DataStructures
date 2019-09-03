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
void InsertionSort(int A[],int n)
{
	int i,j,min,temp,v;
	for(i=1;i<=n-1;i++)
	{
		v = A[i];
		j = i;
		while(A[j-1]>v && j>=1)
		{
			A[j] = A[j-1];
			j--;
		}
		A[j] = v;
	}
	display(A,n);
}

int main()
{
	int A[5] = {3,5,2,8,1};
	InsertionSort(A,5);
}
