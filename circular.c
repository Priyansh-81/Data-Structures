#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} node;


node* insertend(node* start) {
    node* temp = (node*)malloc(sizeof(node));

    printf("Enter the element to insert\n");
    scanf("%d", &temp->info);

    temp->next = temp;

    if (start == NULL) {
        return temp;
    }

    node* cur = start;
    while (cur->next != start) {
        cur = cur->next;
    }

    cur->next = temp;
    temp->next = start;
    return start;
}


node* insertbeginning(node* last) {
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the node to be inserted\n");
    scanf("%d", &temp->info);
    temp->next = temp;

    if (last == NULL) {
        return temp;
    }

    temp->next = last->next;
    last->next = temp;
    return last;
}


void traverse(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    node* cur = start;
    do {
        printf("%d\t", cur->info);
        cur = cur->next;
    } while (cur != start);
    printf("\n");
}


int main() {
    node* start = NULL;
    node* last = NULL;
    int ch;

    while (1) {
        printf("Enter the choice\n1. Insert at beginning\n2. Insert at end\n3. Traverse\n4. Quit\n");
        scanf("%d", &ch);

        if (ch == 4) {
            printf("Thank you!\n");
            break;
        }

        switch (ch) {
            case 1:
                last = insertbeginning(last);
                if (start == NULL) {
                    start = last->next;
                }
                break;
            case 2:
                start = insertend(start);
                if (last == NULL) {
                    last = start;
                }
                break;
            case 3:
                traverse(start);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
