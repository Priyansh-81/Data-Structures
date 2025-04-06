#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure definition
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element to the stack
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1; // Return -1 when stack is empty
    }
}

// Queue structure definition using two stacks
typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    initStack(&(q->stack1));
    initStack(&(q->stack2));
}

// Enqueue operation (push to stack1)
void enqueue(Queue *q, int value) {
    push(&(q->stack1), value);
}

// Dequeue operation (pop from stack2)
int dequeue(Queue *q) {
    // If both stacks are empty, queue is empty
    if (isEmpty(&(q->stack1)) && isEmpty(&(q->stack2))) {
        printf("Queue underflow\n");
        return -1;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty(&(q->stack2))) {
        while (!isEmpty(&(q->stack1))) {
            int temp = pop(&(q->stack1));
            push(&(q->stack2), temp);
        }
    }

    // Pop the element from stack2, which is the front of the queue
    return pop(&(q->stack2));
}

// Main function to demonstrate queue operations
int main() {
    Queue q;
    initQueue(&q);

    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 10
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 20

    // Enqueue more elements
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Dequeue the remaining elements
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 30
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 40
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 50

    // Try to dequeue from an empty queue
    printf("Dequeued: %d\n", dequeue(&q)); // Should print "Queue underflow"

    return 0;
}