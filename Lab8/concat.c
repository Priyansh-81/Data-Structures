#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
    struct node* prev;
} node;

node* insertend(node* start);
node* readlist(node* start);
node* concat(node* start1, node* start2);
void traverse(node* start);

int main() {
    node* X1 = NULL;
    node* X2 = NULL;

    printf("Enter the first list\n");
    X1 = readlist(X1);

    printf("Enter the second list\n");
    X2 = readlist(X2);

    printf("First list is\n");
    traverse(X1);
    printf("Second list is\n");
    traverse(X2);

    // Performing concatenation operation
    X1 = concat(X1, X2);

    printf("The concatenated list is \n");
    traverse(X1);

    return 0;
}

node* readlist(node* start) {
    char ch;
    while (1) {
        printf("Add element?\ny to continue\nn to break\n");
        scanf(" %c", &ch);

        if (ch == 'y' || ch == 'Y') {
            start = insertend(start);
        } else {
            break;
        }
    }
    return start;
}

node* insertend(node* start) {
    node* temp = (node*)malloc(sizeof(node));

    printf("Enter the element to be inserted\n");
    scanf("%d", &temp->info);
    temp->next = temp->prev = NULL;

    if (start == NULL) {
        return temp;
    }

    node* cur = start;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return start;
}

void traverse(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    node* cur = start;
    while (cur != NULL) {
        printf("%d\t", cur->info);
        cur = cur->next;
    }
    printf("\n");
}

node* concat(node* start1, node* start2) {
    if (start1 == NULL) {
        return start2;
    }
    if (start2 == NULL) {
        return start1;
    }
    node* cur = start1;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = start2;
    start2->prev = cur;

    return start1;
}

