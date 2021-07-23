#include<stdio.h>
#include<stdlib.h>
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][W+1];
   printf("\nprofit matrix\n");
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
	printf(" %d\t",K[i][j]);
       }
	printf("\n");
   }
   return K[n][W];
}
void main()
{
    int i, n, val[20], wt[20], W;
    printf("Enter size of knapsack:\t");
    scanf("%d", &W);
    	if(W<=0)
	{
		printf("\nvalues must not be negative\n");
		exit(0);
	}

    printf("Enter number of items:\t");
    scanf("%d", &n);
if(n<0)
{
	printf("\n values must not be negative\n");
	exit(0);
}
    printf("Enter value and weight of each items:\n");
    for(i = 0;i < n; ++i)
    {
    	scanf("%d%d", &val[i], &wt[i]);
    	if(val[i]<0 || wt[i]<0)
	{
		printf("\nvalues must not be negative\n");
		exit(0);
	}
	if(wt[i]>W)
	{
		printf("\nvalues must not be greater than knapsack weight\n");
		exit(0);
	}
    }
    printf("\nmaximum profit is %d\n", knapSack(W, wt, val, n));
}
