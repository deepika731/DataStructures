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
void ShellSort(int A[],int n)
{
	int i,j,min,temp,v,h;
	for(h=1;h<=n/9;h=(3*h)+1);
	printf("%d\n",h);
	for(;h>0;h = h/3)
	{
		for(i=h+1;i<=n-1;i++)
		{
			v = A[i];
			j = i;
			while(j>h && A[j-h]>v)
			{
				A[j] = A[j-h];
				j = j-h;
			}
			A[j] = v;
		}
	}
	display(A,n);
}

int main()
{
	int A[5] = {3,5,2,8,1};
	ShellSort(A,5);
}
