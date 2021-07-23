#include<stdio.h>
#include<sys/time.h>
#include<string.h>
char str[1000],pat[10];

int string_match()
{
	int n,m,i,j;
	n=strlen(str);
	m=strlen(pat);
	for(i=0;i<=(n-m);i++)
	{
		j=0;
		while(j<m && str[i+j]==pat[j])
		{
			j++;
			if(j==m)
				return i;
		}
	}
	return -1;
}

void main()
{
	int n,pos,k,ch,num[100],m;
	float t1,t2,best[100],worst[100];
	struct timeval begin,end;
	FILE *f;
	f=fopen("Best.txt","w");
	//f1=fopen("Worst.txt","w");
	for(k=0;k<3;k++)
	{
		printf("\nEnter string:");
		gets(str);
		printf("\nenter pattern for best case:");
		gets(pat);
		n=strlen(str);
		num[k]=n;
		gettimeofday(&begin,NULL);
		pos=string_match();
		gettimeofday(&end,NULL);
		if(pos!=-1)
                	printf("\n Found at position %d",pos+1);
		else
			printf("\n Not Found!");
		t1=end.tv_usec-begin.tv_usec;
		printf("\n enter pattern for worst case:");
                gets(pat);
                gettimeofday(&begin,NULL);
                pos=string_match();
                gettimeofday(&end,NULL);
		if(pos!=-1)
                	printf("\n Found at position %d",pos+1);
		else
			printf("\n Not Found!");
                t2=end.tv_usec-begin.tv_usec;
		best[k]=t1;
		worst[k]=t2;
		printf("\n timetaken by %d length is  %1.2f and %1.2f",n,t1,t2);
		fprintf(f,"%d \t %1.2f \t %1.2f \n",n,t1,t2);
	//	fprintf(f1,"%d \t %1.2f \t %1.2f \n",n,t2);
	}
	fclose(f);
//	fclose(f1);

	printf("\n----------------------------------------------------------------------------------------------");
	printf("\nsl.no\t\t|length of pattern\t|bestcase\t|worstcase");
	printf("\n----------------------------------------------------------------------------------------------\n");
	for(int pq=0;pq<3;pq++)
	{
		int slno=pq+1;
		printf("%d \t\t|\t %d \t\t|\t %f \t\t|\t %f\n",slno,num[pq],best[pq],worst[pq]);
	}
	printf("\n----------------------------------------------------------------------------------------------\n");

}
