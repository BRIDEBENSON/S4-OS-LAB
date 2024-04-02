
#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100
int abs_diff(int a,int b){
    return(a>b)?(a-b):(b-a);
}

int main() {
    int request[MAX_REQUESTS];
    int num_requests;
    int head_position;
    int total_head_mov=0;
    printf("Enter the number of requests:");
    scanf("%d",&num_requests);
    if(num_requests<=0 || num_requests>MAX_REQUESTS){
        printf("Invalid request");
        return 1;
    }
    printf("Enter the current head position:");
    scanf("%d",&head_position);
    printf("Enter the requests(0 to 199)");
    for(int i=0;i<num_requests;i++){
        scanf("%d",&request[i]);
    }
    printf("\nSSTF Disk Scheduling Order:\n");
    printf("Head -> ");
    int visited[MAX_REQUESTS]={0};
    int visit_count=0;
    while(visit_count<num_requests){
        int shortest_dist=9999;
        int next_request=-1;
        for(int i=0;i<num_requests;i++){
            if(!visited[i]){
                int dist=abs_diff(head_position,request[i]);
                if(dist<shortest_dist){
                    shortest_dist=dist;
                    next_request=i;
                }
            }
        }
        visited[next_request]=1;
        visit_count++;
        total_head_mov+=shortest_dist;
        head_position=request[next_request];
        printf("%d->",head_position);
    }
   
   
    printf("Total head movement %d",total_head_mov);

    return 0;
}
