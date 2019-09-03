#include<stdio.h>
int main()
{
	int n,m,w[100],p[100],i,j;
	float pbw[100];
	printf("enter the total number of objects:");
	scanf("%d",&n);
	printf("enter the bag capacity:");
	scanf("%d",&m);
	printf("enter the weigths of the objects:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("enter the profits of the objects:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		pbw[i] = (float)p[i]/w[i];
	}
	//printf("\n");
	int temp1=0,temp2=0;
	float temp3=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(pbw[i]<pbw[i+1])
			{
				temp1 = pbw[i];
				pbw[i] = pbw[i+1];
				pbw[i+1] = temp1;
				temp2 = p[i];
				p[i] = p[i+1];
				p[i+1] = temp2;
				temp3 = w[i];
				w[i] = w[i+1];
				w[i+1] = temp3;
			}
		}
	}
	/*
	printf("profits:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",p[i]);
	}
	printf("weights:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",w[i]);
	}
	printf("profit/weights:\n");
	for(i=0;i<n;i++)
	{
		printf("%f\t",pbw[i]);
	}*/
	float max_profit = 0,fraction_obj;
	for(i=0;i<n;i++)
	{
		if(m>0 && w[i]<m)
		{
			max_profit = max_profit + p[i];
			m = m-w[i];
		}
		else
		{
			fraction_obj = i;
			break;
		}
	}
	if(m>0)
	{
		max_profit+=m*((float)p[i]/w[i]);
	}
	printf("maximum profit is = %f\n",max_profit);				
}
	
	
