#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
};
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}
void push(int stack[], int *top, int item) {
    stack[++(*top)] = item;
}
int pop(int stack[], int *top) {
    return stack[(*top)--];
}
void dfsList(struct Graph* graph, int startVertex) {
    int stack[MAX_VERTICES];
    int top = -1;
    push(stack, &top, startVertex);
    while (top != -1) {
        int v = pop(stack, &top);
        if (graph->visited[v] == 0) {
            printf("%d ", v);
            graph->visited[v] = 1;
        }
        struct Node* temp = graph->adjList[v];
        while (temp != NULL) {
            if (graph->visited[temp->vertex] == 0) {
                push(stack, &top, temp->vertex);
            }
            temp = temp->next;
        }
    }
}
int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);    
    printf("DFS Traversal starting from vertex 0:\n");
    dfsList(graph, 0);
    printf("\n");
    return 0;
}
