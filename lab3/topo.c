#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

void main()
{
	int n,i,j,a[100][100],rem[100],flag=0,t=0,ind;
	float t1;
	struct timeval begin,end;
	printf("\nEnter order of matrix\t");
	scanf("%d",&n);
	printf("\nEnter Adjencency matrix\t");

	for(i=0;i<n;i++)
	{
		rem[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j)
			if(a[i][j]!=0)
			{
				printf("\n self loop detected \n");
				exit(0);
			}
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j && a[i][j]==a[j][i] && a[i][j]==1)
			{
				printf("\n undirected graph\n");
				exit(0);
			}




	gettimeofday(&begin,NULL);
	while(flag==0)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			if(rem[i]==0)
			{
				ind=0;
				for(j=0;j<n;j++)
				{
					if(!(rem[j]==1 || a[j][i]==0))
					{
						ind=1;
						break;
					}
				}
				if(ind==0)
				{
					flag=0;
					printf("%d--->",i+1);
					t++;
					rem[i]=1;
				}
			}
		}
	}
	gettimeofday(&end,NULL);
	t1=-(begin.tv_usec-end.tv_usec);
	if(t==n)
		printf("\nTopology is possible and time took is %f\n",t1);
	else
		printf("NOT possible\n");
}
