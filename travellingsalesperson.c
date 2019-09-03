#include<stdio.h>
int n=4;
int dist[10][10] = {
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
};
int dp[16][4];
int VISITED_ALL = (1<<4)-1;
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int tsp(int mask,int pos)
{
	if(mask == VISITED_ALL)
	{
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1)
	{
		return dp[mask][pos];
	}
	int ans = 1000;
	for(int city =0;city<n;city++)
	{
		if((mask&(1<<city))==0)
		{
			int newCity = dist[pos][city] + tsp(mask|(1<<city),city);
			ans = min(ans,newCity);
		}
	}
	return dp[mask][pos] = ans;
	
}
int main()
{
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j] = -1;
		}
	}
	printf("%d\n",tsp(1,0));
}
