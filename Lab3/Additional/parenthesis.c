#include<stdio.h>

#define MAX 100

// Function to check if the parentheses are balanced
int checkParentheses(const char *expr) {
    char stack[MAX];
    int top = -1;  // Stack initialization

    for (int i = 0; expr[i] != '\0'; i++) {
        // If opening parenthesis, push onto stack
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            if (top >= MAX - 1) {
                return 0;  // Stack overflow (unbalanced)
            }
            stack[++top] = expr[i];
        }
        // If closing parenthesis, check for matching opening one
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1) {
                return 0;  // No matching opening parenthesis
            }
            char topChar = stack[top--];  // Pop from stack

            // Check if the popped character matches the current closing parenthesis
            if ((expr[i] == ')' && topChar != '(') ||
                (expr[i] == '}' && topChar != '{') ||
                (expr[i] == ']' && topChar != '[')) {
                return 0;  // Mismatch found
            }
        }
    }

    // If stack is empty at the end, parentheses are balanced
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkParentheses(expr)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}