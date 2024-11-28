#include <stdio.h>
#define MAX_SIZE 100
int a[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE]; 
int queue[MAX_SIZE]; 
int front = 0, rear = 0, size = MAX_SIZE;
int n; 
void enqueue(int item) {
    if (rear != size) {
        if (front == 0 && rear == 0) {
            front = 1;
        }
        rear++;
        queue[rear] = item;
    }
}
int dequeue() {
    if (front == 0 && rear == 0) {
        return -1; // Empty queue
    } else if (front == rear) {
        int item = queue[front];
        front = 0;
        rear = 0;
        return item;
    } else {
        return queue[front++];
    }
}
void bfsMatrix() {
    int v;
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &v);
    enqueue(v);
    visited[v] = 1;
    while (front != 0 && rear != 0) {
        v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}
int main() {
    int u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0; 
        }
        visited[i] = 0; 
    }
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
   bfsMatrix(); 
    return 0;
}
