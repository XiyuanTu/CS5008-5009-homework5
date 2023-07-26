#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 10

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph (adjacency list)
void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to perform breadth-first search on the graph
void bfs(Node* adjList[], int startVertex) {
    bool visited[MAX_VERTICES] = {false};

    // Initialize the queue for BFS
    Node* queue = createNode(startVertex);
    visited[startVertex] = true;

    printf("BFS Order: ");

    while (queue != NULL) {
        int currentVertex = queue->vertex;
        printf("%d ", currentVertex);

        // Dequeue the current vertex
        Node* temp = queue;
        queue = queue->next;
        free(temp);

        // Explore adjacent vertices and enqueue them
        Node* neighbor = adjList[currentVertex];
        while (neighbor != NULL) {
            int adjVertex = neighbor->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                Node* newQueueNode = createNode(adjVertex);
                newQueueNode->next = NULL;

                // Find the last node in the queue
                Node* lastNode = queue;
                while (lastNode && lastNode->next)
                    lastNode = lastNode->next;

                if (lastNode)
                    lastNode->next = newQueueNode;
                else
                    queue = newQueueNode;
            }
            neighbor = neighbor->next;
        }
    }

    printf("\n");
}

int main() {
    // Graph represented as an adjacency list
    Node* adjList[MAX_VERTICES] = {NULL};

    // Adding edges to the graph
    
    addEdge(adjList, 0, 3);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 6);
    addEdge(adjList, 4, 7);
    addEdge(adjList, 5, 8);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 7, 8);

    bfs(adjList, 0); // Start BFS from vertex 0

    return 0;
}
