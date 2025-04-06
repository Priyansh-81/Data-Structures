#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Global stack definition
char stack[MAX][MAX];  // Stack to store operands and expressions
int top = -1;          // Top pointer for the stack

// Push a string onto the stack
void push(char *str) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    } else {
        printf("Stack overflow\n");
    }
}

// Pop a string from the stack
char* pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return NULL;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[]) {
    int len = strlen(prefix);

    // Traverse the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char current = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(current)) {
            char operand[2] = {current, '\0'};
            push(operand);
        }
        // If the character is an operator
        else if (isOperator(current)) {
            // Pop two operands from the stack
            char *op1 = pop();
            char *op2 = pop();

            // Create a new string: op1 + op2 + operator
            char temp[MAX];
            snprintf(temp, MAX, "%s%s%c", op1, op2, current);

            // Push the new postfix expression onto the stack
            push(temp);
        }
    }

    // The final element in the stack is the postfix expression
    printf("Postfix expression: %s\n", pop());
}

// Main function to take input and call the conversion function
int main() {
    char prefix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}