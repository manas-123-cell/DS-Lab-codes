#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;

GNODE graph[20];

int main() {
    int N, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        graph[i] = NULL;

    while (1) {
        printf("\n1.Insert Edge\n2.Delete Edge\n3.Insert Vertex\n4.Delete Vertex\n5.Print\n6.Exit\n");
        scanf("%d", &choice);

        // PRINT
        if (choice == 5) {
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
        }

        // INSERT EDGE
        else if (choice == 1) {
            int src, dest;
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);

            if (src < 1 || src > N || dest < 1 || dest > N) {
                printf("Invalid vertex\n");
                continue;
            }

            GNODE newnode = (GNODE)malloc(sizeof(struct node));
            newnode->vertex = dest;
            newnode->next = NULL;

            if (graph[src] == NULL) {
                graph[src] = newnode;
            } else {
                GNODE temp = graph[src];
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newnode;
            }
        }

        // DELETE EDGE
        else if (choice == 2) {
            int src, dest;
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);

            if (src < 1 || src > N || dest < 1 || dest > N) {
                printf("Invalid vertex\n");
                continue;
            }

            GNODE curr = graph[src], prev = NULL;

            while (curr != NULL) {
                if (curr->vertex == dest) {
                    if (prev == NULL)
                        graph[src] = curr->next;
                    else
                        prev->next = curr->next;

                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }

        // INSERT VERTEX
        else if (choice == 3) {
            int edges, v;

            N++;
            graph[N] = NULL;

            scanf("%d", &edges);
            for (int i = 0; i < edges; i++) {
                scanf("%d", &v);

                GNODE newnode = (GNODE)malloc(sizeof(struct node));
                newnode->vertex = N;
                newnode->next = NULL;

                if (graph[v] == NULL)
                    graph[v] = newnode;
                else {
                    GNODE temp = graph[v];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }

            scanf("%d", &edges);
            for (int i = 0; i < edges; i++) {
                scanf("%d", &v);

                GNODE newnode = (GNODE)malloc(sizeof(struct node));
                newnode->vertex = v;
                newnode->next = NULL;

                if (graph[N] == NULL)
                    graph[N] = newnode;
                else {
                    GNODE temp = graph[N];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }
        }

        // DELETE VERTEX
        else if (choice == 4) {
            int v;
            printf("Enter vertex to delete: ");
            scanf("%d", &v);

            if (v < 1 || v > N) {
                printf("Invalid vertex\n");
                continue;
            }

            GNODE temp = graph[v];
            while (temp != NULL) {
                GNODE t = temp;
                temp = temp->next;
                free(t);
            }
            graph[v] = NULL;

            for (int i = 1; i <= N; i++) {
                GNODE curr = graph[i], prev = NULL;

                while (curr != NULL) {
                    if (curr->vertex == v) {
                        if (prev == NULL)
                            graph[i] = curr->next;
                        else
                            prev->next = curr->next;

                        GNODE t = curr;
                        curr = curr->next;
                        free(t);
                    } else {
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }

            for (int i = v; i < N; i++)
                graph[i] = graph[i + 1];

            graph[N] = NULL;
            N--;

            for (int i = 1; i <= N; i++) {
                GNODE t = graph[i];
                while (t != NULL) {
                    if (t->vertex > v)
                        t->vertex--;
                    t = t->next;
                }
            }
        }

        else if (choice == 6) {
            printf("Exit\n");
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
