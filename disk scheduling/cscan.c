
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
    int total_head_movement = 0;

    printf("Enter the number of disk requests (max %d): ", MAX_REQUESTS);
    scanf("%d", &num_requests);

    if (num_requests <= 0 || num_requests > MAX_REQUESTS) {
        printf("Invalid number of requests. Please try again.\n");
        return 1;
    }

    printf("Enter the starting head position (0 to 199): ");
    scanf("%d", &head_position);

    printf("Enter %d disk requests (track positions from 0 to 199):\n", num_requests);
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    // Sorting the requests in ascending order
    for (int i = 0; i < num_requests - 1; i++) {
        for (int j = 0; j < num_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // Finding the index where head_position should be inserted in the sorted array
    int insert_index = 0;
    while (insert_index < num_requests && requests[insert_index] <= head_position) {
        insert_index++;
    }

    // C-SCAN Disk Scheduling Algorithm - Moving the head from left to right
    printf("\nC-SCAN Disk Scheduling Order (Left to Right):\n");
    printf("Head -> ");

    for (int i = insert_index; i < num_requests; i++) {
        printf("%d -> ", requests[i]);
        total_head_movement += abs_diff(head_position, requests[i]);
        head_position = requests[i];
    }

    total_head_movement += abs_diff(head_position, 199); // Move the head to the right-most track

    // Move the head back to the left-most track (track 0)
    head_position = 0;
    printf("0 -> ");

    // C-SCAN Disk Scheduling Algorithm - Moving the head from right to left
    for (int i = 0; i < insert_index; i++) {
        printf("%d -> ", requests[i]);
        total_head_movement += abs_diff(head_position, requests[i]);
        head_position = requests[i];
    }

    printf("End\n");
    printf("Total Head Movement: %d\n", total_head_movement);

    return 0;
}
