#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int a[5000];
int partition(int l,int h)
{
	int temp,i,j,pivot;
	pivot = a[l];
	i = l;
	j = h;
	while(i<=j)
	{
		while(a[i]<=pivot && i<=h)
			i++;
		while(a[j]>pivot && j>=l)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
		}
	}
	return j;
}
void quicksort(int l,int h)
{
	if(l<h)
	{
		int j = partition(l,h);
		quicksort(l,j-1);
		quicksort(j+1,h);
	}
}
void main()
{
	int p,q,m,n;
	FILE *fp;
	float t1;
	struct timeval begin,end;
	int iter[100],num[100];
	fp=fopen("quick.txt","w");
	printf("\nEnter number of iterations :\n");
	scanf("%d",&m);
	if(m<0)
	{
		printf("enter positive no only\n");
		exit(0);
	}
	for(q=0;q<m;q++)
	{
		printf("\nEnter the number of elements\n");
		scanf("%d",&n);
	if(n<0)
	{
		printf("enter positive no only\n");
		exit(0);
	}

		printf("\nBefore Sorting:");
		for(p=0;p<n;p++)
		{
			a[p] = rand()%100;
			printf("%d ",a[p]);

		}
		printf("\n----------------------------------------------------------------------------------------------\n");
		gettimeofday(&begin,NULL);
		quicksort(0,n-1);
		gettimeofday(&end,NULL);
		printf("\nAfter sorting:");
		for(p=0;p<n;p++)
		{
			printf("%d ",a[p]);
		}
		printf("\n----------------------------------------------------------------------------------------------\n");
		t1 = end.tv_usec - begin.tv_usec;
		iter[q]=t1;
		num[q]=n;
		printf("\nTime taken is %1.2f",t1);
		fprintf(fp,"%d \t %1.2f \n",n,t1);
	}
	printf("\n----------------------------------------------------------------------------------------------");
	printf("\nsl.no\t\t|\tNo.of elements\t|\tTime taken");
	printf("\n----------------------------------------------------------------------------------------------\n");
	for(int pq=0;pq<m;pq++)
	{
		int slno=pq+1;
		printf("%d \t\t|\t %d \t\t|\t %d\n",slno,num[pq],iter[pq]);
	}
		fclose(fp);
	printf("\n----------------------------------------------------------------------------------------------\n");

}


