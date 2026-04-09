#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

int main() {
    int V, E;
    int u, v, start;

    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // ADD EDGE
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    // SORT ADJ LIST
    for (int i = 0; i < V; i++) {
        Node *ptr1, *ptr2;
        for (ptr1 = adjList[i]; ptr1 != NULL; ptr1 = ptr1->next) {
            for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
                if (ptr1->vertex > ptr2->vertex) {
                    int temp = ptr1->vertex;
                    ptr1->vertex = ptr2->vertex;
                    ptr2->vertex = temp;
                }
            }
        }
    }

    // DFS (using stack instead of recursion)
    scanf("%d", &start);

    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int curr = stack[top--];

        if (!visited[curr]) {
            printf("%d ", curr);
            visited[curr] = 1;

            // push in reverse order to maintain sorted order
            Node* temp = adjList[curr];
            int tempArr[MAX_VERTICES], k = 0;

            while (temp != NULL) {
                if (!visited[temp->vertex])
                    tempArr[k++] = temp->vertex;
                temp = temp->next;
            }

            for (int i = k - 1; i >= 0; i--) {
                stack[++top] = tempArr[i];
            }
        }
    }

    return 0;
}
