#include <stdio.h>

#define MAX 100

struct stack {
    char arr[MAX];
    int top;
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

void convert(char exp[], char out[]) {
    s.top = -1;
    int k = 0;
    char e1, e2;

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
}

int main() {
    char exp[MAX];
    char out[MAX];

    printf("Enter the expression: ");
    gets(exp);

    convert(exp, out);
    printf("The postfix expression is: %s\n", out);

    return 0;
}
