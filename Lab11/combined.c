#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* lcl;
    struct node* rcl;
}node;

node* root = NULL;

node* createnode(int value) {
    struct node* newnode = ( node*)malloc(sizeof( node));
    newnode->info = value;
    newnode->lcl = newnode->rcl = NULL;
    return newnode;
}

struct node* search(struct node* root, int value) {
    if (root == NULL || root->info == value) {
        return root;
    }
    if (value < root->info) {
        return search(root->lcl, value);
    }
    return search(root->rcl, value);
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createnode(value);
    }
    if (value < root->info) {
        root->lcl = insert(root->lcl, value);
    } else if (value > root->info) {
        root->rcl = insert(root->rcl, value);
    }
    return root;
}

struct node* inOrderPredecessor(struct node* root) {
    root = root->lcl;
    while (root->rcl != NULL) {
        root = root->rcl;
    }
    return root;
}

struct node* deletenode(struct node* root, int value) {
    struct node* inPre;
    if (root == NULL) {
        return NULL;
    }
    if (value < root->info) {
        root->lcl = deletenode(root->lcl, value);
    } else if (value > root->info) {
        root->rcl = deletenode(root->rcl, value);
    } else {
        if (root->lcl == NULL && root->rcl == NULL) {
            free(root);
            return NULL;
        } else if (root->lcl == NULL) {
            struct node* temp = root->rcl;
            free(root);
            return temp;
        } else if (root->rcl == NULL) {
            struct node* temp = root->lcl;
            free(root);
            return temp;
        }
        inPre = inOrderPredecessor(root);
        root->info = inPre->info;
        root->lcl = deletenode(root->lcl, inPre->info);
    }
    return root;
}

void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->lcl);
        printf("%d ", root->info);
        inOrderTraversal(root->rcl);
    }
}

int main() {
    int choice, value;
    struct node* temp;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the tree.\n", value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deletenode(root, value);
                printf("Deleted %d from the tree.\n", value);
                break;

            case 4:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
