#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int main() {
    int requests[MAX_REQUESTS];
    int num_requests;
    int head_position;
    int total_head_mov = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &num_requests);
    if (num_requests <= 0 || num_requests > MAX_REQUESTS) {
        printf("Invalid number of requests\n");
        return 1;
    }

    printf("Enter the current head position: ");
    scanf("%d", &head_position);

    printf("Enter the requests (0 to 199): ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    // Sort the requests in ascending order
    for (int i = 0; i < num_requests - 1; i++) {
        for (int j = 0; j < num_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Find the index of the head position in the sorted requests array
    int head_index = 0;
    while (head_index < num_requests && requests[head_index] < head_position) {
        head_index++;
    }

    // SCAN Disk Scheduling Algorithm - Moving towards the end (Right)
    printf("\nSCAN Disk Scheduling Order:\n");
    printf("Head -> ");
    for (int i = head_index; i < num_requests; i++) {
        total_head_mov += abs_diff(head_position, requests[i]);
        head_position = requests[i];
        printf("%d -> ", head_position);
    }

    // Move the head to the end of the disk
    total_head_mov += abs_diff(head_position, 199);
    head_position = 199;
    printf("199 -> ");

    // SCAN Disk Scheduling Algorithm - Moving towards the beginning (Left)
    for (int i = head_index - 1; i >= 0; i--) {
        total_head_mov += abs_diff(head_position, requests[i]);
        head_position = requests[i];
        printf("%d -> ", head_position);
    }

    printf("End\n");
    printf("Total head movement: %d\n", total_head_mov);

    return 0;
}
