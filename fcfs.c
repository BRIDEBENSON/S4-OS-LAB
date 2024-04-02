#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pid, at, bt, ct, tat, wt;
} 
p[20],temp;
int n;
void asort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
void fcfs()
{
float sum1=0, sum2=0;
asort();
p[0].ct=p[0].at+p[0].bt;
for(int i=0;i<n;i++)
{
	p[i+1].ct=p[i].ct+p[i+1].bt;
	p[i].tat=p[i].ct+p[i].at;
	p[i].wt=p[i].tat-p[i].bt;
	sum1=sum1+p[i].tat;
	sum2=sum2+p[i].wt;
}
printf("FCFS:\n");
printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++)
{
	printf("%d\t",p[i].pid);
	printf("%d\t",p[i].at);
	printf("%d\t",p[i].bt);
	printf("%d\t",p[i].ct);
	printf("%d\t",p[i].tat);
	printf("%d\t\n",p[i].wt);
}
	printf("avg TAT: %f",(sum1/n));
	printf("avg WT: %f",(sum2/n));
}
void main()
{
	printf("enter the no of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter the PID:");
		scanf("%d",&p[i].pid);
		printf("enter the arrival time:");
		scanf("%d",&p[i].at);
		printf("enter the burst time:");
		scanf("%d",&p[i].bt);
	}
	fcfs();
}
