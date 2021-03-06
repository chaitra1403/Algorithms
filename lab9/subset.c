#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
int inc[50],w[50],sum,n;
void sumset(int i,int wt,int total);
int promising(int i,int wt,int total)
{
	return(((wt+total)>=sum)&&((wt==sum)||(wt+w[i+1]<=sum)));
}
void main()
{
	int k,l,i,j,n,temp,total=0;
	printf("\n Enter how many numbers:\n");
	scanf("%d",&n);
	printf("\n Enter %d numbers:\n",n);
	for (i=0;i<n;i++)
	{
                scanf("%d",&w[i]);
		total+=w[i];
        }


	for(k=0;k<n;k++)
	{
		for(l=k+1;l<n;l++)
		{
			if(w[k]==w[l])
			{
				printf("Enter only unique values \n");
				exit(0);
			}
		}
	}

	printf("\n Input the sum value to create sub set:\n");
        scanf("%d",&sum);
        

        	if((total<sum))
		{
        		printf("\n Subset construction is not possible\n");
			exit(0);
		}
	
	
		if(w[0]>sum)
			printf("subset not possible\n\n");
		else
		{
                	for (i=0;i<n;i++)
                		inc[i]=0;
                		printf("\n The solution using backtracking is:\n");
                		sumset(-1,0,total);
        	}
}
			
		
	

void sumset(int i,int wt,int total)
{
        int j;
        if(promising(i,wt,total))
	{
                if(wt==sum)
		{
			printf("The possible solution is");
                        printf("\n");
                        for (j=0;j<=i;j++)
                            if(inc[j])
                             printf("%d\t",w[j]);
			printf("\n");
                }
		else
		{
                        inc[i+1]=TRUE;
                        sumset(i+1,wt+w[i+1],total-w[i+1]);
                        inc[i+1]=FALSE;
                        sumset(i+1,wt,total-w[i+1]);
                }
        }
}

