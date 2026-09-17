```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    int vertices;
    struct Node **adjList;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjList[i];

        printf("%d: ", i);

        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }
}

void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];

    while (temp != NULL) {
        if (visited[temp->vertex] == 0)
            DFS(graph, temp->vertex, visited);

        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int start) {
    int visited[graph->vertices];
    int queue[graph->vertices];

    int front = 0;
    int rear = 0;

    for (int i = 0; i < graph->vertices; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        struct Node* temp = graph->adjList[vertex];

        while (temp != NULL) {
            if (visited[temp->vertex] == 0) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 5;

    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printf("Adjacency List:\n");
    displayGraph(graph);

    int visited[vertices];

    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(graph, 0, visited);

    printf("\nBFS: ");
    BFS(graph, 0);

    return 0;
}
```
