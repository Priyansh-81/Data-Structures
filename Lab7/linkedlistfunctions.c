#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} node;

node* insertbefore(node* start);
node* insertafter(node* start);
node* delete_ele(node* start);
node* insertbeginning(node* start);
void traverse(node* start);
node* reverse(node* start);
node* sort(node* start);
node* deletealternate(node* start);
node* insertsorted(node* start);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int op;
    printf("Hello\n");
    node* start = NULL;
    printf("Select the operation that has to be performed\n"
           "1.Insert at beginning\n"
           "2.Insert before a desired element\n"
           "3.Insert after the desired element\n"
           "4.Delete an element\n"
           "5.Traverse the list\n"
           "6.Reverse the list\n"
           "7.Sort the list (ascending)\n"
           "8.Delete every alternate element of the list\n"
           "9.Insert an element into the sorted list without disturbing the order of the list\n"
           "0. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &op);
        if (op == 0) {
            break;
        }
        switch (op) {
        case 1:
            start = insertbeginning(start);
            break;
        case 2:
            start = insertbefore(start);
            break;
        case 3:
            start = insertafter(start);
            break;
        case 4:
            start = delete_ele(start);
            break;
        case 5:
            traverse(start);
            break;
        case 6:
            start = reverse(start);
            break;
        case 7:
            start = sort(start);
            break;
        case 8:
            start = deletealternate(start);
            break;
        case 9:
            start = insertsorted(start);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

node* insertbeginning(node* start) {
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter element to enter\n");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        return start;
    }
    temp->next = start;
    start = temp;
    return start;
}

node* insertbefore(node* start) {
    printf("Enter the element you want to enter\n");
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter to insert:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL) {
        printf("Empty list\nInserting the first element\n");
        start = temp;
        return start;
    }

    node* prev = NULL;
    node* cur = start;
    int ele;
    printf("Enter the element you want to insert before:\t");
    scanf("%d", &ele);

    while (cur != NULL && cur->info != ele) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == start) {
        temp->next = start;
        start = temp;
        return start;
    }

    temp->next = cur;
    if (prev != NULL) {
        prev->next = temp;
    }

    return start;
}

node* insertafter(node* start) {
    if (start == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    node* cur = start;

    int ele;
    printf("Enter the element after which insertion is required\n");
    scanf("%d", &ele);

    while (cur != NULL && cur->info != ele) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Insertion failed\nElement not found\n");
        return start;
    }

    node* temp = (node*)malloc(sizeof(node));
    printf("Enter element to enter\n");
    scanf("%d", &temp->info);
    temp->next = NULL;

    temp->next = cur->next;
    cur->next = temp;
    return start;
}

node* delete_ele(node* start) {
    if (start == NULL) {
        printf("Empty list\nNothing to delete\n");
        return NULL;
    }
    int ele;
    printf("Enter the element you want to delete...\t");
    scanf("%d", &ele);
    node* prev = NULL;
    node* cur = start;

    while (cur != NULL && cur->info != ele) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Element not found\n Deletion unsuccessful\n");
        return start;
    }
    if (cur == start) {
        start = start->next;
        free(cur);
        return start;
    }
    prev->next = cur->next;
    free(cur);
    return start;
}

void traverse(node* start) {
    if (start == NULL) {
        printf("Empty list\n");
    } else {
        node* cur = start;
        while (cur != NULL) {
            printf("%d\t", cur->info);
            cur = cur->next;
        }
        printf("\n");
    }
}

node* reverse(node* start) {
    if (start == NULL) {
        printf("Empty list\n");
        return start;
    }
    node* p = start;
    node* r = NULL;
    node* q;

    q = p->next;
    while (q != NULL) {
        p->next = r;
        r = p;
        p = q;
        q = q->next;
    }
    p->next = r;
    start = p;
    return start;
}

node* sort(node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    node* i;
    node* j;
    for (i = start; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                swap(&i->info, &j->info);
            }
        }
    }

    return start;
}

node* insertsorted(node* start) {
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter element to insert:\n");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL || start->info >= temp->info) {
        temp->next = start;
        start = temp;
        return start;
    }

    node* cur = start;
    while (cur->next != NULL && cur->next->info < temp->info) {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;

    return start;
}

node* deletealternate(node* start) {
    if (start == NULL) {
        printf("Empty list\n");
        return NULL;
    }
    node* c1 = start;
    node* c2;
    while (c1 != NULL && c1->next != NULL) {
        c2 = c1->next;
        c1->next = c2->next;
        free(c2);
        c1 = c1->next;
    }
    return start;
}
