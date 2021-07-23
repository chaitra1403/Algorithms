#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[10],count;
void queen(int,int);
int place(int,int);
void print(int);

int main()
{
	//void queen(int row,int n);
	int flag=1;
	while(flag==1)
	{
	int n;
	void queen(int row,int n);
	printf("Enter the Queen\n");
	scanf("%d",&n);
	if(n<0)
		printf("Enter positive no only\n");
	else if(n==0)
		printf("No queen\n");
	else if(n==1)
		printf("Traival solution\n");
	else if(n==2)
		printf("queens Killing each other\n");
	else if(n==3)
		{
		printf("Queen must be more than 3\n");
		printf("1 for countinue, 0 for exit\n");
		scanf("%d",&flag);
		if(flag==1)
			continue;
		else
			exit(0);
		}
	else
		queen(1,n);
	return 0;
	}//while
}

void queen(int row,int n )
{
	int column;
	for(column=1;column<=n;++column)
	{
		if(place(row,column))
		{
			board[row]=column;
			if(row==n)
				print(n);
			else
				queen(row+1,n);
		}
	}
}

int place(int row,int column)
{
	int i;
	for(i=1;i<=row-1;++i)
	{
		if(board[i]==column)
			return 0;
		else
			if(abs(board[i]-column)==abs(i-row))
				return 0;
	}
	return 1;


}

void print(int n)
{
	int i,j;
	printf("Solution=%d\n",++count);
	for(i=1;i<=n;++i)
		printf("\t%d",i);

	for(i=1;i<=n;++i)
	{	printf("\n\n%d",i);
		for(j=1;j<=n;++j)
		{	if(board[i]==j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}

printf("\n");
//for(i=1;i<=n;i++)
//printf("Queen %d placed in %d position\n",i,board[i]);
}

