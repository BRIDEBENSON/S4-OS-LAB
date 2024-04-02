#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pid;
	int pri;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};
void swap(int i, int j,struct process p[20])
{
	struct process temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}
void atsort(struct process p[20],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (p[i].at>p[j].at)
				swap(i,j,p);
		}
	}
}
void pidsort(struct process p[20],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (p[i].at>p[j].at && p[i].pid>p[j].pid)
				swap(i,j,p);
		}
	}
}
void prisort(struct process p[20],int i,int n,int ict)
{
	int a,b;
	for(int a=i+1;a<n;a++)
	{
		for(b=a;b<n;b++)
		{
			if (p[a].at<=ict && p[b].at<=ict)
			{

				if(p[a].pri>p[b].pri)
					swap(a,b,p);
			}
		}
	}
}
void prisch(struct process p[20], int n)
{
	atsort(p,n);
	pidsort(p,n);
	int ict =p[0].at;
	for(int i=0;i<n;i++)
	{
		if(ict<p[i].at)
			p[i].ct=p[i].at+p[i].bt;
		else
			p[i].ct=ict+p[i].bt;
		ict=p[i].ct;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		prisort(p,i,n,ict);
	}
}
void main()
{
	struct process p[20];
	int n;
	float avwt,avtat;
	float twt=0,ttat=0;
	printf("enter the no of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the PID of p%d:",i+1);
		scanf("%d",&p[i].pid);
		printf("enter the priority of p%d:",i+1);
		scanf("%d",&p[i].pri);
		printf("enter the AT of p%d:",i+1);
		scanf("%d",&p[i].at);
		printf("enter the BT of p%d:",i+1);
		scanf("%d",&p[i].bt);
	}
	prisch(p,n);
	printf("\nPID\tpriority\tAT\tBT\tCT\tTAT\tWT");
	for(int i=0;i<n;i++)
	{
		twt+=p[i].wt;
		ttat+=p[i].tat;
		printf("\n%d\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].pri,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	
	}
	avwt=twt/(float)n;
	avtat=ttat/(float)n;
	printf("\nAvg TAT: %f",avtat);
	printf("Avg WT: %f",avwt);
}
