#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct StackNode {
    Node* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, Node* treeNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = stack->top;
    stack->top = newStackNode;
}

Node* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    StackNode* temp = stack->top;
    Node* treeNode = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    return treeNode;
}

Node* buildExpressionTree(char* postfix) {
    Stack* stack = createStack();
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        Node* newNode = createNode(ch);
        if (ch >= '0' && ch <= '9') {
            push(stack, newNode);
        } else {
            newNode->right = pop(stack);
            newNode->left = pop(stack);
            push(stack, newNode);
        }
    }
    return pop(stack);
}

int evaluate(Node* root) {
    if (!root) return 0;
    if (root->data >= '0' && root->data <= '9') return root->data - '0';
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    Node* root = buildExpressionTree(postfix);
    printf("Result of evaluation: %d\n", evaluate(root));
    return 0;
}
