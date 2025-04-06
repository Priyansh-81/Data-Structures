//Write a program to input an infix expression and convert into its equivalent prefix
//form and display. Operands can be single character.

#include <stdio.h>
#include<string.h>
#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
}s;

void push(char c) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s.arr[++(s.top)] = c;
}

char pop() {
    if (s.top == -1) {
        return '\0';
    }
    return s.arr[(s.top)--];
}

int precedence(char a) {
    if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    } else {
        return 0;
    }
}

int isempty() {
    return s.top == -1;
}

// Function to reverse a string
void reverse(char exp[]) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Convert infix to prefix
void convertToPrefix(char exp[], char out[]) {
    s.top = -1;
    int k = 0;
    char e1, e2;

    // Reverse the infix expression
    reverse(exp);

    // Replace '(' with ')' and vice versa
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }

    // Infix to Postfix logic (on reversed string)
    for (int i = 0; exp[i] != '\0'; i++) {
        e1 = exp[i];
        switch (e1) {
            case '(':
                push(e1);
                break;
            case ')':
                while ((e2 = pop()) != '(') {
                    out[k++] = e2;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isempty() && precedence(e1) <= precedence(s.arr[s.top])) {
                    out[k++] = pop();
                }
                push(e1);
                break;
            default:
                out[k++] = e1;
                break;
        }
    }

    while (!isempty()) {
        out[k++] = pop();
    }
    out[k] = '\0';

    // Reverse the result to get the prefix expression
    reverse(out);
}

int main() {
    char exp[MAX], out[MAX];

    printf("Enter the infix expression: ");
    gets(exp);

    convertToPrefix(exp, out);

    printf("The prefix expression is: %s\n", out);

    return 0;
}