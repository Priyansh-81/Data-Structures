#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
    struct node* prev;
} node;

node* insertend(node* start){
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element to be inserted..\n");
    scanf("%d", &temp->info);
    temp->next = temp;
    temp->prev = temp;

    if(start == NULL){
        printf("Inserting the first element of the list:\n");
        return temp;
    }

    start->prev->next = temp;
    temp->prev = start->prev;
    temp->next = start;
    start->prev = temp;
    return start;
}

node* delete(node* start, int delele){
    if(start == NULL){
        printf("Nothing to delete, list is already empty.\n");
        return start;
    }

    node* cur = start;
    if(cur->info == delele){
        if(cur->next == cur){
            free(cur);
            return NULL;
        }

        start = start->next;
        start->prev = cur->prev;
        cur->prev->next = start;
        free(cur);
        return start;
    }


    do{
        if(cur->info == delele){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            return start;
        }
        cur = cur->next;
    } while(cur != start);

    printf("Element %d not found in the list.\n", delele);
    return start;
}


void display(node* start){
    if(start == NULL){
        printf("The list is empty.\n");
        return;
    }

    node* temp = start;
    do{
        printf("%d ", temp->info);
        temp = temp->next;
    } while(temp != start);
    printf("\n");
}

int main() {
    node* start = NULL;
    int choice, value;

    while(1) {
        printf("1. Insert at end\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice==4)
            break;
        switch(choice) {
            case 1:
                start = insertend(start);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                start = delete(start, value);
                break;
            case 3:
                display(start);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
