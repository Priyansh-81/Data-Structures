//Write a program to evaluate prefix expression. The input to the program is a prefix
//expression.
#include <stdio.h>
#include <string.h>
#define MAX 100

struct stack {
    int arr[MAX];
    int top;
};
struct stack s;

void push(int c) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s.arr[++s.top] = c;
}

int pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return -999;
    }
    return s.arr[s.top--];
}

void eval(char pfix[]) {
    int len = strlen(pfix);

    // Traverse from the end (right to left)
    for (int i = len - 1; i >= 0; i--) {
        if (pfix[i] == '*' || pfix[i] == '/' || pfix[i] == '+' || pfix[i] == '-') {
            // Pop two operands
            int op1 = pop();
            int op2 = pop();

            // Apply the operator and push the result
            switch (pfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        } else {
            // If the character is a digit, push it as an integer
            push(pfix[i] - '0');
        }
    }
}

int main() {
    s.top = -1;
    char exp[MAX];

    printf("Enter a prefix expression to evaluate: ");
    gets(exp);

    eval(exp);

    // Display the result, which will be the only value in the stack
    printf("The result of the prefix expression is: %d\n", pop());

    return 0;
}

