#include <stdio.h>
#include <stdlib.h>
typedef struct Job {
    char id;
    int dead;
    int profit;
} Job;
int compare(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return job2->profit - job1->profit;
}
void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);
    int slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }
    char result[n];
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = arr[i].id;
                slot[j] = 1;
                break;
            }
        }
    }
    printf("Job Sequence for maximum profit: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", result[i]);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter job %d details (ID, Deadline, Profit): ", i + 1);
        scanf(" %c %d %d", &arr[i].id, &arr[i].dead, &arr[i].profit);
    }
    printJobScheduling(arr, n);
    return 0;
}
