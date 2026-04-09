#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_OPS 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int main() {
    int opCount;
    scanf("%d", &opCount);

    Node *root = NULL;

    char outputs[MAX_OPS][50];
    int outIndex = 0;

    int op, key;

    for (int i = 0; i < opCount; i++) {
        scanf("%d", &op);

        if (op == 1 || op == 2 || op == 3)
            scanf("%d", &key);

        // INSERT
        if (op == 1) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = key;
            newNode->left = newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                Node* temp = root;
                Node* parent = NULL;

                while (temp != NULL) {
                    parent = temp;
                    if (key < temp->data)
                        temp = temp->left;
                    else if (key > temp->data)
                        temp = temp->right;
                    else
                        break;
                }

                if (key < parent->data)
                    parent->left = newNode;
                else if (key > parent->data)
                    parent->right = newNode;
            }
        }

        // DELETE
        else if (op == 2) {
            Node* parent = NULL;
            Node* curr = root;

            // search node
            while (curr != NULL && curr->data != key) {
                parent = curr;
                if (key < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if (curr != NULL) {
                // case: 2 children
                if (curr->left != NULL && curr->right != NULL) {
                    Node* p = curr;
                    Node* succ = curr->right;

                    while (succ->left != NULL) {
                        p = succ;
                        succ = succ->left;
                    }

                    curr->data = succ->data;
                    curr = succ;
                    parent = p;
                }

                // case: 0 or 1 child
                Node* child;
                if (curr->left != NULL)
                    child = curr->left;
                else
                    child = curr->right;

                if (parent == NULL) {
                    root = child;
                } else if (parent->left == curr) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }

                free(curr);
            }
        }

        // SEARCH
        else if (op == 3) {
            Node* temp = root;
            bool found = false;

            while (temp != NULL) {
                if (temp->data == key) {
                    found = true;
                    break;
                } else if (key < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }

            if (found)
                strcpy(outputs[outIndex++], "found");
            else
                strcpy(outputs[outIndex++], "not found");
        }
    }

    for (int i = 0; i < outIndex; i++) {
        printf("%s\n", outputs[i]);
    }

    return 0;
}
