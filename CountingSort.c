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
void CountingSort(int A[],int n,int B[],int k)
{
	int C[k],i,j;
	for(i=0;i<k;i++)
	{
		C[i] = 0;
	}
	display(C,15);
	for(j=0;j<n;j++)
	{
		C[A[j]] = C[A[j]]+1;
	}
	display(C,15);
	for(i=1;i<k;i++)
	{
		C[i] = C[i]+C[i-1];
	}
	display(C,15);
	for(j=n-1;j>=0;j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]]-1;
	}
	display(C,15);
}
int main()
{
	int A[5] = {3,5,2,8,1},B[5];
	CountingSort(A,5,B,15);
	display(B,5);
}
