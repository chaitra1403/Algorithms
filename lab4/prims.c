#include<stdio.h>
void main()
{
	int cost[10][10],visited[10]={0},ne=1,flag=1;
	int i,j,a,b,u,v,n,s,min,mincost=0,count=0;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	printf("\n Enter the Cost matrix:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	s=1;
	visited[s]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min && visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n Edge %d(%d,%d) cost is %d",ne++,a,b,min);
			mincost+= min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Total minimum cost is %d\n",mincost);
}
