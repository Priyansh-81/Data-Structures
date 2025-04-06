#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* lcl;
    struct node* rcl;
} node;

node* createNode(int info) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->info = info;
    newNode->lcl = newNode->rcl = NULL;
    return newNode;
}

int areEqual(node* root1, node* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->info == root2->info) &&
           areEqual(root1->lcl, root2->lcl) &&
           areEqual(root1->rcl, root2->rcl);
}

node* insert(node* root, int info) {
    if (root == NULL) return createNode(info);
    if (info < root->info)
        root->lcl = insert(root->lcl, info);
    else
        root->rcl = insert(root->rcl, info);
    return root;
}

void buildTree(node** root) {
    int n, info;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &info);
        *root = insert(*root, info);
    }
}

int main() {
    node* tree1 = NULL;
    node* tree2 = NULL;

    printf("Build first tree:\n");
    buildTree(&tree1);

    printf("Build second tree:\n");
    buildTree(&tree2);

    if (areEqual(tree1, tree2))
        printf("The trees are equal.\n");
    else
        printf("The trees are not equal.\n");

    return 0;
}
