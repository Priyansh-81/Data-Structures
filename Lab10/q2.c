#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct node {
    int value;
    struct node* lcl;
    struct node* rcl;
}node ;

// Function to create a new node
node* createnode(int value) {
    struct node* newnode = (node*)malloc(sizeof(node));
    newnode->value = value;
    newnode->lcl = newnode->rcl = NULL;
    return newnode;
}

node* insert( node* root, int value) {
    // Base case: If the tree is empty, create a new node
    if (root == NULL) {
        return createnode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->value) {
        root->lcl = insert(root->lcl, value);
    } else if (value > root->value) {
        root->rcl = insert(root->rcl, value);
    }

    // Return the unchanged root node
    return root;
}

// Function to print the tree structure
void printTree(node* root, int space) {
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process rcl child first
    printTree(root->rcl, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Process lcl child
    printTree(root->lcl, space);
}

// Menu-driven program
int main() {
    node* root = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Print the tree structure\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a node
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("node inserted.\n");
                break;

            case 2:
                // Print the tree structure
                printf("Tree structure:\n");
                printTree(root, 0);
                printf("\n");
                break;

            case 3:
                // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
