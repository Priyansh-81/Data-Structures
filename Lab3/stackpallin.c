#include<stdio.h>
#include<string.h>
#define MAX 100

struct Stack {
    char str[MAX];
    int top;
} s;

void push(char);
char pop();
char peep();
int isPalindrome(char[]);

int main() {
    char input[MAX];
    printf("Enter a string: ");
    gets(input);  // Note: `gets` is unsafe, consider using `fgets` in production code.

    s.top = -1;  // Initialize the stack top

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

void push(char c) {
    if (s.top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s.str[++s.top] = c;
}

char pop() {
    if (s.top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s.str[s.top--];
}

char peep() {
    if (s.top == -1) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s.str[s.top];
}

int isPalindrome(char input[]) {
    int i, len = strlen(input);

    // Push all characters of the string onto the stack
    for (i = 0; i < len; i++) {
        push(input[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (i = 0; i < len; i++) {
        if (pop() != input[i]) {
            return 0;  // false
        }
    }
    return 1;  // true
}
