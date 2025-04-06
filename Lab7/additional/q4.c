#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* push(node* top, int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = top;
    top = temp;
    return top;
}

node* pop(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    node* temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
    return top;
}

void displayStack(node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* enqueue(node* rear, int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    if (rear != NULL)
        rear->next = temp;
    return temp;
}

node* dequeue(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }
    node* temp = front;
    front = front->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
    return front;
}

void displayQueue(node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* stackTop = NULL;
    node* queueFront = NULL;
    node* queueRear = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n");
        printf("4. Enqueue to Queue\n5. Dequeue from Queue\n6. Display Queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                stackTop = push(stackTop, value);
                break;
            case 2:
                stackTop = pop(stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (queueFront == NULL)
                    queueFront = queueRear = enqueue(queueRear, value);
                else
                    queueRear = enqueue(queueRear, value);
                break;
            case 5:
                queueFront = dequeue(queueFront);
                if (queueFront == NULL)
                    queueRear = NULL;
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
