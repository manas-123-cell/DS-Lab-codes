#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node* head = NULL;
    int choice, num;

    while (1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &num);

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = num;
            newNode->next = NULL;
            newNode->prev = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            printf("Inserted successfully\n");
        }

        else if (choice == 2) {
            scanf("%d", &num);

            if (head == NULL) {
                printf("List is empty\n");
            } else {
                struct Node* temp = head;

                while (temp != NULL && temp->data != num) {
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Number %d not found\n", num);
                } else {
                    if (temp == head) {
                        head = temp->next;
                        if (head != NULL)
                            head->prev = NULL;
                    } else {
                        if (temp->prev != NULL)
                            temp->prev->next = temp->next;
                        if (temp->next != NULL)
                            temp->next->prev = temp->prev;
                    }
                    free(temp);

                    // Display after deletion
                    struct Node* t = head;
                    if (head == NULL) {
                        printf("List is empty\n");
                    } else {
                        while (t != NULL) {
                            printf("%d ", t->data);
                            t = t->next;
                        }
                        printf("\n");
                    }
                }
            }
        }

        else if (choice == 3) {
            struct Node* temp = head;

            if (head == NULL) {
                printf("List is empty\n");
            } else {
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
        }

        else if (choice == 4) {
            if (head == NULL) {
                printf("List is empty\n");
            } else {
                struct Node* temp = NULL;
                struct Node* current = head;

                while (current != NULL) {
                    temp = current->prev;
                    current->prev = current->next;
                    current->next = temp;
                    current = current->prev;
                }

                if (temp != NULL) {
                    head = temp->prev;
                }

                struct Node* t = head;
                while (t != NULL) {
                    printf("%d ", t->data);
                    t = t->next;
                }
                printf("\n");
            }
        }

        else if (choice == 5) {
            int n, x;
            scanf("%d", &n);

            if (n == 0) {
                printf("Second list is empty\n");
            } else {
                struct Node* head2 = NULL;
                struct Node* last2 = NULL;

                for (int i = 0; i < n; i++) {
                    scanf("%d", &x);

                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = x;
                    newNode->next = NULL;
                    newNode->prev = NULL;

                    if (head2 == NULL) {
                        head2 = newNode;
                        last2 = newNode;
                    } else {
                        last2->next = newNode;
                        newNode->prev = last2;
                        last2 = newNode;
                    }
                }

                if (head == NULL) {
                    head = head2;
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = head2;
                    head2->prev = temp;
                }

                struct Node* t = head;
                while (t != NULL) {
                    printf("%d ", t->data);
                    t = t->next;
                }
                printf("\n");
            }
        }

        else if (choice == 6) {
            printf("Exit\n");
            exit(0);
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
