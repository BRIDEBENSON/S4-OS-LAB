#include<stdio.h>
struct process
{
    int pid,at,bt,wt,tat,rt,ct;
    int completed;
}p[10];
int n;
int q[10]; //queue
int front=-1,rear=-1;
void enqueue(int i)
{
    if(rear==10)
        printf("overflow");
    rear++;
    q[rear]=i;
    if(front==-1)
        front=0;
}
int dequeue()
{
    if(front==-1)
        printf("underflow");
    int temp=q[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return temp;
}
int isInQueue(int i)
{
    int k;
    for(k=front;k<=rear;k++)
    {
        if(q[k]==i)
            return 1;
    }
    return 0;
}
void sortByArrival()
{
    struct process temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
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

void main()
{
    int i,j,time=0,sum_bt=0,tq;
    float avgwt=0;
    printf("Enter no of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the process ID, arrival time and burst time of process %d: ",i+1);
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].completed=0;
        sum_bt+=p[i].bt;
    }
    printf("\nEnter the time quantum:");
    scanf("%d",&tq);
    sortByArrival();
    enqueue(0);
    printf("Process execution order: ");
    for(time=p[0].at;time<sum_bt;)
    {
        i=dequeue();
        if(p[i].rt<=tq)
        {
            time+=p[i].rt;
            p[i].rt=0;
            p[i].completed=1;
            p[i].ct=time;
            printf(" P%d ",p[i].pid);
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            for(j=0;j<n;j++)
            {
                if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
        }
        else
        {
            time+=tq;
            p[i].rt-=tq;
            printf(" P%d ",p[i].pid);
            for(j=0;j<n;j++)
            {
                if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);
        }
    }
    printf("\nName\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time");
    float avgtat=0;
    for(i=0;i<n;i++)
    {
        avgtat+=p[i].tat;
        avgwt+=p[i].wt;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\nAverage TurnAround time:%f\n",avgtat/n);
    printf("\nAverage Waiting time:%f\n",avgwt/n);
}
