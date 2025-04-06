#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node array[MAX];
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Initialize each list as empty by setting heads to NULL
    for (int i = 0; i < vertices; i++) {
        graph->array[i].vertex = i;
        graph->array[i].next = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addUndirectedEdge(struct Graph* graph, int u, int v) {
    // Add an edge from u to v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = graph->array[u].next;
    graph->array[u].next = newNode;

    // Add an edge from v to u (since it's undirected)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = graph->array[v].next;
    graph->array[v].next = newNode;
}

// Function to add an edge to a directed graph
void addDirectedEdge(struct Graph* graph, int u, int v) {
    // Add an edge from u to v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = graph->array[u].next;
    graph->array[u].next = newNode;
}

// Function to perform BFS on the graph
void bfs(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};  // Array to keep track of visited vertices
    int queue[MAX];           // Queue for BFS
    int front = 0, rear = 0;  // Queue pointers

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Visit all the neighbors of the current vertex
        struct Node* temp = graph->array[currentVertex].next;
        while (temp) {
            int adjVertex = temp->vertex;

            // If the adjacent vertex hasn't been visited, visit and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Helper function for DFS (recursive)
void dfsHelper(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recursively visit all unvisited neighbors
    struct Node* temp = graph->array[vertex].next;
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsHelper(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS on the graph
void dfs(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};  // Array to keep track of visited vertices

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfsHelper(graph, startVertex, visited);
    printf("\n");
}

// Main function
int main() {
    int vertices, choice, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices > MAX) {
        printf("Number of vertices exceeded the limit!\n");
        return 0;
    }

    struct Graph* graph = createGraph(vertices);

    printf("Enter the graph type:\n1. Undirected Graph\n2. Directed Graph\n");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u -> v): ");
        scanf("%d %d", &u, &v);

        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid edge. Please enter valid vertices.\n");
            i--;  // Decrement i to repeat the input for this edge
            continue;
        }

        if (choice == 1) {
            addUndirectedEdge(graph, u, v);
        } else if (choice == 2) {
            addDirectedEdge(graph, u, v);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);
    dfs(graph, startVertex);

    return 0;
}
