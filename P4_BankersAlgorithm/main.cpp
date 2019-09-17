#include<stdio.h>
#include<stdlib.h>
const int MAX=10;
int allocation[MAX][MAX],max[MAX][MAX],available[MAX],work[MAX],need[MAX][MAX],finish[MAX],safe[MAX],m,n;
void input()
{
	int i,j;
	printf("Enter no. of resource types: ");
	scanf("%d",&m);
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	printf("Enter the available resources vector :\n");
	for(i=0;i<m;i++)
		scanf("%d",&available[i]);
	printf("Enter the allocation matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);
	printf("Enter the MAX matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);
}
void calc_need()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-allocation[i][j];
}
void disp_need()
{
	int i,j;
	printf("Content of NEED matrix :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",need[i][j]);
		printf("\n");
	}
}
int isNeedLessThanWork(int i)
{
	int j;
	for(j=0;j<m;j++)
		if(need[i][j]>work[j])
			return 0;
	return 1;
}
int safety()
{
	int i,j,k=0;
	for(i=0;i<m;i++)
		work[i]=available[i];
	for(i=0;i<n;i++)
		finish[i]=0;
	while(1)
	{
		for(i=0;i<n;i++)
		{
			if(!finish[i] && isNeedLessThanWork(i))
			{
				for(j=0;j<m;j++)
					work[j]=work[j]+allocation[i][j];
				finish[i]=1;
				safe[k++]=i;
				break;
			}
		}
		if(i==n)
		{
			for(j=0;j<n;j++)
				if(!finish[j])
					return 0;
			return 1;
		}
	}
}
int main()
{
	int i,isSafe=0;
	input();
	calc_need();
	disp_need();
	isSafe=safety();
	if(isSafe)
	{
		printf("\nThe Safe Sequence is\n");
		for(i=0;i<n;i++)
			printf("P%d\n",safe[i]);
	}
	else
		printf("No safe sequence exists.");
	return 0;
}
