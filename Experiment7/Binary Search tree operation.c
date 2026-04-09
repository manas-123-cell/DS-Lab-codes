#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // INSERT
        if (choice == 1) {
            printf("Data: ");
            scanf("%d", &data);

            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->val = data;
            newNode->left = newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                struct TreeNode* temp = root;
                struct TreeNode* parent = NULL;

                while (temp != NULL) {
                    parent = temp;
                    if (data < temp->val)
                        temp = temp->left;
                    else
                        temp = temp->right;
                }

                if (data < parent->val)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
        }

        // INORDER
        else if (choice == 2) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack[100];
                int top = -1;
                struct TreeNode* curr = root;

                while (curr != NULL || top != -1) {
                    while (curr != NULL) {
                        stack[++top] = curr;
                        curr = curr->left;
                    }
                    curr = stack[top--];
                    printf("%d ", curr->val);
                    curr = curr->right;
                }
                printf("\n");
            }
        }

        // PREORDER
        else if (choice == 3) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack[100];
                int top = -1;

                stack[++top] = root;

                while (top != -1) {
                    struct TreeNode* node = stack[top--];
                    printf("%d ", node->val);

                    if (node->right)
                        stack[++top] = node->right;
                    if (node->left)
                        stack[++top] = node->left;
                }
                printf("\n");
            }
        }

        // POSTORDER
        else if (choice == 4) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack1[100];
                struct TreeNode* stack2[100];
                int top1 = -1, top2 = -1;

                stack1[++top1] = root;

                while (top1 != -1) {
                    struct TreeNode* node = stack1[top1--];
                    stack2[++top2] = node;

                    if (node->left)
                        stack1[++top1] = node->left;
                    if (node->right)
                        stack1[++top1] = node->right;
                }

                while (top2 != -1) {
                    printf("%d ", stack2[top2--]->val);
                }
                printf("\n");
            }
        }

        // DELETE
        else if (choice == 5) {
            printf("Delete: ");
            scanf("%d", &data);

            struct TreeNode* parent = NULL;
            struct TreeNode* curr = root;

            // find node
            while (curr != NULL && curr->val != data) {
                parent = curr;
                if (data < curr->val)
                    curr = curr->left;
                else
                    curr = curr->right;
            }

            if (curr == NULL) {
                printf("Value not found\n");
            } else {
                // case: 2 children
                if (curr->left != NULL && curr->right != NULL) {
                    struct TreeNode* p = curr;
                    struct TreeNode* succ = curr->right;

                    while (succ->left != NULL) {
                        p = succ;
                        succ = succ->left;
                    }

                    curr->val = succ->val;
                    curr = succ;
                    parent = p;
                }

                // case: 0 or 1 child
                struct TreeNode* child;
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

        // EXIT
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
