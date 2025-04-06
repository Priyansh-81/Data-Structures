#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(node* start) {
    int value;
    printf("Enter value (-1 to stop): ");
    scanf("%d", &value);
    if (value == -1)
        return NULL;
    start = (node*)malloc(sizeof(node));
    start->data = value;
    start->next = create(start->next);
    return start;
}

void traverse(node* start) {
    if (start == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", start->data);
    traverse(start->next);
}

int main() {
    node* start = NULL;
    start = create(start);
    printf("Linked list: ");
    traverse(start);
    return 0;
}
