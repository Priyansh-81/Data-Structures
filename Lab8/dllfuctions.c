/*
Write a menu driven program to perform the following on a doubly linked list
i.) Insert an element at the rear end of the list
ii.) Delete an element from the rear end of the list
iii.) Insert an element at a given position of the list
iv.) Delete an element from a given position of the list
v.) Insert an element after another element
vi.) Insert an element before another element
vii.) Traverse the list
viii.) Reverse the list
Write a program to c */

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node* next;
    struct node* prev;
} node;

node* insertrear(node* start);
node* deleterear(node * start);
node* insertatposition(node* start);
node* deleteatposition(node* start);
node* insertafter(node* start);
node* insertbefore(node* start);
void traverse(node* start);
node* reverse(node* start);

int main() {
    node* start = NULL;
    int ch;
    printf("\nMenu\n");
    printf("1. Insert at Rear\n");
    printf("2. Delete from Rear\n");
    printf("3. Insert at Position\n");
    printf("4. Delete at Position\n");
    printf("5. Insert after Element\n");
    printf("6. Insert before Element\n");
    printf("7. Traverse\n");
    printf("8. Reverse\n");
    printf("0. Exit\n");
    while (1) {

        printf("Enter choice:\t");
        scanf("%d", &ch);
        if(ch==0){
            break;
        }

        switch (ch) {
            case 1:
                start = insertrear(start);
                break;
            case 2:
                start = deleterear(start);
                break;
            case 3:
                start = insertatposition(start);
                break;
            case 4:
                start = deleteatposition(start);
                break;
            case 5:
                start = insertafter(start);
                break;
            case 6:
                start = insertbefore(start);
                break;
            case 7:
                traverse(start);
                break;
            case 8:
                start = reverse(start);
                printf("List reversed\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

node* insertrear(node* start) {
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter element to be inserted: ");
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

node* deleterear(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    node* cur = start;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    if (cur== NULL) {
        free(cur);
        return NULL;
    }

    cur->prev->next = NULL;
    free(cur);

    return start;
}

node* insertatposition(node* start) {
    printf("Enter the position where you want to insert: ");
    int pos;
    scanf("%d", &pos);

    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &temp->info);
    temp->next = temp->prev = NULL;

    if (start == NULL && pos == 1) {
        return temp;
    }

    node* cur = start;
    int count = 1;

    while (cur != NULL && count < pos - 1) {
        cur = cur->next;
        count++;
    }

    if (cur == NULL && pos > 1) {
        printf("Invalid position\n");
        free(temp);
        return start;
    }

    if (cur == NULL) {
        start = temp;
    } else {
        temp->next = cur->next;
        if (cur->next != NULL) {
            cur->next->prev = temp;
        }
        cur->next = temp;
        temp->prev = cur;
    }

    return start;
}

node* deleteatposition(node* start) {
    printf("Enter the position to delete: ");
    int pos;
    scanf("%d", &pos);

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    node* cur = start;
    int count = 1;

    while (cur != NULL && count < pos) {
        cur = cur->next;
        count++;
    }

    if (cur == NULL) {
        printf("Invalid position\n");
        return start;
    }

    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    } else {
        start = cur->next;
    }

    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }

    free(cur);

    return start;
}

node* insertafter(node* start) {
    printf("Enter the element after which you want to insert: ");
    int ele;
    scanf("%d", &ele);

    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &temp->info);
    temp->next = temp->prev = NULL;

    node* cur = start;

    while (cur != NULL && cur->info != ele) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Element not found\n");
        free(temp);
        return start;
    }

    temp->next = cur->next;
    temp->prev = cur;

    if (cur->next != NULL) {
        cur->next->prev = temp;
    }

    cur->next = temp;

    return start;
}

node* insertbefore(node* start) {
    printf("Enter the element before which you want to insert: ");
    int ele;
    scanf("%d", &ele);

    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &temp->info);
    temp->next = temp->prev = NULL;

    node* cur = start;

    while (cur != NULL && cur->info != ele) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Element not found\n");
        free(temp);
        return start;
    }

    temp->next = cur;
    temp->prev = cur->prev;

    if (cur->prev != NULL) {
        cur->prev->next = temp;
    } else {
        start = temp;
    }

    cur->prev = temp;

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

node* reverse(node* start) {
    if (start == NULL) {
        return start;
    }

    node* cur = start;
    node* temp = NULL;

    while (cur != NULL) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp != NULL) {
        start = temp->prev;
    }

    return start;
}
