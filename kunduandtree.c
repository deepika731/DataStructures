#include<stdio.h>
int n=5;
int col[10][10];
int kundu(int n)
{
	int count = 0;
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
								
				if(col[i][j] == 'r' && col[j][k] == 'r')
				{
					//printf("(%d,%d,%d)\n",i,j,k);
					count++;
				}
			}
		}
		
	}

	return count;
	
}
int main()
{
	int l,k1,k2;
	char k3[1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)	
		{
			col[i][j] = '0';
		}
	}
	scanf("%d",&l);
	for(int i=0;i<l;i++)
	{
		scanf("%d",&k1);
		scanf("%d",&k2);
		scanf("%s",k3);
		col[k1][k2] = k3[0];
	}
	
	int k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			k = 0;
			for(int t=i;t<j;t++)
			{
				if(col[t][t+1] == 'r')
				{
					k = 1;
				}
			}
			if(k==1)
			{
				col[i][j] = 'r';
			}
		}
	}
	printf("%d",kundu(5));
}
			
