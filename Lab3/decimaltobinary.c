#include<stdio.h>
#define max 100

struct Stack {
    int top;
    int arr[max];
};

struct Stack s;

void push(int);
void pop();
void peek();

int main() {
    s.top = -1;

    int num, base;
    printf("Enter the number: \n");
    scanf("%d", &num);
    printf("Enter the base for conversion: \n");
    scanf("%d", &base);

    if (num == 0) {
        push(0);
    } else {
        while (num > 0) {
            int remainder = num % base;
            if (base == 6) {
                remainder += 55;
            }
            push(remainder);
            num = num / base;
        }
    }

    printf("Conversion is: ");
    peek();  // Display the elements in the correct order
    printf("\nThank You!\n");

    return 0;
}

void push(int ele) {
    if (s.top == max - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s.arr[++s.top] = ele;
}

void pop() {
    if (s.top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    s.top--;
}

void peek() {
    if (s.top == -1) {
        printf("Underflow condition\n");
        return;
    }
    // Display elements 
    for (int i = s.top; i >= 0; i--) {
        if (s.arr[i] >= 10) {  // Assuming the base is hexadecimal
            printf("%c", s.arr[i]);
        } else {
            printf("%d", s.arr[i]);
        }
    }
}
