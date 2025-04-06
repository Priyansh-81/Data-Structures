#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int info;
    struct node* rcl;
    struct node* lcl;
} node;

void inorder(node* root) {
    if (!root)
        return;
    inorder(root -> lcl);
    printf("%d ", root -> info);
    inorder(root -> rcl);
}

void postorder(node* root) {
    if (!root)
        return;
    postorder(root -> lcl);
    postorder(root -> rcl);
    printf("%d ", root -> info);
}

void preorder(node* root) {
    if (!root)
        return;
    printf("%d ", root -> info);
    preorder(root -> lcl);
    preorder(root -> rcl);
}

int print_parent(node* root, int ele) {
    if (!root)
        return 0;
    if (root)
        if (root -> info == ele)
            return 1;
    int found1 = 0, found2 = 0;
    if (root -> lcl) {
        if (root -> lcl -> info == ele) {
            printf("%d ", root -> info);
            return 1;
        }
        else
            found1 = print_parent(root -> lcl, ele);
    }
    if (root -> rcl) {
        if (root -> rcl -> info == ele) {
            printf("%d ", root -> info);
            return 1;
        }
        else
            found2 = print_parent(root -> rcl, ele);
    }
    return found1 || found2;
}

/** Returns the depth of the binary tree
 * @param root The root of the binary tree
 * @param curdepth The current depth of the binary tree
 * @return The depth of the binary tree
 */
int depth(node* root, int curdepth) {
    if (!root)
        return curdepth - 1;
    int ldepth, rdepth;
    ldepth = depth(root -> lcl, curdepth + 1);
    rdepth = depth(root -> rcl, curdepth + 1);
    return (ldepth > rdepth)?ldepth:rdepth;
}

/** Prints the ancestors of the entered element in the binary tree
 * @param root The root of the binary tree
 * @param ele The element to print the ancestors of
 * @return 0 if the element is not found in the tree, 1 if found
 */
int print_ancestors(node* root, int ele) {
    if (!root)
        return 0;
    if (root)
        if (root -> info == ele)
            return 1;
    if (root -> lcl) {
        int found = print_ancestors(root -> lcl, ele);
        if (found) {
            printf("%d ", root -> info);
            return 1;
        }
    }
    if (root -> rcl) {
        int found = print_ancestors(root -> rcl, ele);
        if (found) {
            printf("%d ", root -> info);
            return 1;
        }
    }
    return 0;
}

/** Returns the number of leaf nodes in the binary tree
 * @param root The root of the binary tree
 * @return The number of leaf nodes in the binary tree
 */
int leaves(node* root) {
    if (!root)
        return 0;
    int lleaves, rleaves;
    lleaves = leaves(root -> lcl);
    rleaves = leaves(root -> rcl);
    if (lleaves + rleaves == 0)
        return 1;
    else
        return lleaves + rleaves;
}

/** Inserts an element into the binary tree
 * @param root The root of the binary tree
 * @param ele The element to insert
 * @return The updated root node of the binary tree(useful during first insert)
 */
node* insert(node* root, int ele) {
    if (!root) {
        root = malloc(sizeof(*root));
        root -> lcl = root -> rcl = NULL;
        root -> info = ele;
        return root;
    }
    node* temp;
    if (!root -> lcl || !root -> rcl) {
        temp = malloc(sizeof(*temp));
        temp -> info = ele;
        temp -> lcl = temp -> rcl = NULL;
    }
    if (!root -> lcl) {
        root -> lcl = temp;
        return root;
    }
    if (!root -> rcl) {
        root -> rcl = temp;
        return root;
    }
    if (leaves(root -> lcl) <= leaves(root -> rcl))
        insert(root -> lcl, ele);
    else
        insert(root -> rcl, ele);
    return root;
}

/** Prints the tree horizontally
 * @param root The root of the binary tree
 * @param depth The current depth of the root
 */
void print_tree(node* root, int curdepth) {
    if (!root)
        return;
    print_tree(root -> rcl, curdepth + 1);
    for (int i = 0; i < curdepth; i++)
        printf("\t");
    printf("%d\n", root -> info);
    print_tree(root -> lcl, curdepth + 1);
}

int main() {
    printf("1. Insert element\n2. Print tree\n3. Traverse inorder\n"
           "4. Traverse postorder\n5. Traverse preorder\n"
           "6. Print parent\n7. Print depth\n8. Print ancestors\n"
           "9. Count leaf nodes\n10. Exit\nEnter choice: ");
    int ch;
    scanf("%d", &ch);
    node* root = NULL;
    while (1) {
        int ele, found = 1;
        switch (ch) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        case 2: print_tree(root, 0); break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            preorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter element: ");
            scanf("%d", &ele);
            found = print_parent(root, ele);
            if (found)
                printf("\n");
            break;
        case 7:
            printf("Depth is: %d\n", depth(root, 0));
            break;
        case 8:
            printf("Enter element: ");
            scanf("%d", &ele);
            found = print_ancestors(root, ele);
            if (found)
                printf("\n");
            break;
        case 9:
            printf("Leaf nodes: %d\n", leaves(root));
            break;
        case 10: return 0;
        default: printf("Invalid choice\n");
        }
        if (!found)
            printf("Element not found\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
    }
}
