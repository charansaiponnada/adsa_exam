#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t %d\n", i, dist[i]);
    }
}
void dijkstra(int graph[][10], int V, int src) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}
int main() {
    int V, E, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][10];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;  // Initialize all values to 0
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // For undirected graph
    }
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, V, src);
    return 0;
}
