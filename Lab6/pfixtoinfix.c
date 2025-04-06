#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX][MAX];
}s;

char* pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return s.arr[s.top--];
}

void push(char c[]) {
    if (s.top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(s.arr[++s.top], c);
}

void reverse(char exp[]) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void toInfix(char Pfix[]) {
    s.top = -1;  // Initialize stack top
    reverse(Pfix);
    for (int i = 0; Pfix[i] != '\0'; i++) {
        char op1[MAX], op2[MAX], ope[2];  // Changed size of ope to 2
        char res[MAX];
        ope[0] = Pfix[i];
        ope[1] = '\0';  // Ensure it is a null-terminated string

        if (ope[0] == '+' || ope[0] == '-' || ope[0] == '/' || ope[0] == '*') {
            // Pop two operands
            strcpy(op1, pop());
            strcpy(op2, pop());

            // Form the infix expression
            strcpy(res, "(");
            strcat(res, op1);
            strcat(res, ope);
            strcat(res, op2);
            strcat(res, ")");

            // Push the resulting infix expression back onto the stack
            push(res);
        } else {
            // Operand: Push directly to the stack
            push(ope);
        }
    }
}

int main() {
    s.top = -1;
    char pfix[MAX];

    printf("Enter a prefix expression to convert it to infix expression: \n");
    fgets(pfix, MAX, stdin);
    // Remove newline character added by fgets
    pfix[strcspn(pfix, "\n")] = 0;

    toInfix(pfix);

    printf("The infix form is: \n%s\n", s.arr[s.top]);

    return 0;
}