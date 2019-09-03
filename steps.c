#include<stdio.h>
int steps(int n)
{
	if(n==0)
	{
		return 1;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		return steps(n-1)+steps(n-2);
	}
}
		
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",steps(n));
}
