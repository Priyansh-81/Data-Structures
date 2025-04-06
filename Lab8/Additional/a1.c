#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

node* append(node* head, int data) {
    node* temp = createNode(data);
    if (head == NULL) {
        return temp;
    }
    node* last = head;
    while (last->next) last = last->next;
    last->next = temp;
    temp->prev = last;
    return head;
}

int exists(node* head, int data) {
    node* temp = head;
    while (temp) {
        if (temp->data == data) return 1;
        temp = temp->next;
    }
    return 0;
}

node* unionLists(node* head1, node* head2) {
    node* result = NULL;
    node* temp = head1;
    while (temp) {
        result = append(result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp) {
        if (!exists(result, temp->data)) result = append(result, temp->data);
        temp = temp->next;
    }
    return result;
}

node* intersectLists(node* head1, node* head2) {
    node* result = NULL;
    node* temp = head1;
    while (temp) {
        if (exists(head2, temp->data) && !exists(result, temp->data)) result = append(result, temp->data);
        temp = temp->next;
    }
    return result;
}

void printList(node* head) {
    node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, data;
    node* head1 = NULL;
    node* head2 = NULL;

    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n1);
    printf("Enter the elements for the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        head1 = append(head1, data);
    }

    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n2);
    printf("Enter the elements for the second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        head2 = append(head2, data);
    }

    node* unionResult = unionLists(head1, head2);
    node* intersectionResult = intersectLists(head1, head2);

    printf("Union of lists: ");
    printList(unionResult);
    printf("Intersection of lists: ");
    printList(intersectionResult);

    return 0;
}
