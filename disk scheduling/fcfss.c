
#include <stdio.h>
#include <stdlib.h>
#define n 100

int main() {
    int request[n];
    int num_requests;
    int head_position;
    int total_head_mov=0;
    printf("Enter the number of requests:");
    scanf("%d",&num_requests);
    if(num_requests<=0 || num_requests>n){
        printf("Invalid request");
        return 1;
    }
    printf("Enter the current head position:");
    scanf("%d",&head_position);
    printf("Enter the requests(0 to 199)");
    for(int i=0;i<num_requests;i++){
        scanf("%d",&request[i]);
    }
    printf("\nFCFS Disk Scheduling Order:\n");
    printf("Head -> ");

    for(int i=0;i<num_requests;i++){
        printf("%d->",request[i]);
        total_head_mov+=abs(head_position-request[i]);
        head_position=request[i];
    }
    printf("Total head movement %d",total_head_mov);

    return 0;
}
