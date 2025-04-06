#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* createNode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

node* append(node* head, int value) {
    node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    node* last = head;
    while (last->next) last = last->next;
    last->next = temp;
    return head;
}

node* reverseList(node* head) {
    node* prev = NULL;
    node* curr = head;
    while (curr) {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* addLists(node* head1, node* head2) {
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    node* result = NULL;
    int carry = 0;

    while (head1 || head2 || carry) {
        int sum = carry;
        if (head1) {
            sum += head1->value;
            head1 = head1->next;
        }
        if (head2) {
            sum += head2->value;
            head2 = head2->next;
        }
        carry = sum / 10;
        result = append(result, sum % 10);
    }

    return reverseList(result);
}

void printList(node* head) {
    node* temp = head;
    while (temp) {
        printf("%d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char num1[1000], num2[1000];
    node *head1 = NULL, *head2 = NULL;

    printf("Enter the first long integer: ");
    scanf("%s", num1);
    printf("Enter the second long integer: ");
    scanf("%s", num2);

    for (int i = 0; i < strlen(num1); i++) {
        head1 = append(head1, num1[i] - '0');
    }
    for (int i = 0; i < strlen(num2); i++) {
        head2 = append(head2, num2[i] - '0');
    }

    node* result = addLists(head1, head2);
    printf("Result of addition: ");
    printList(result);

    return 0;
}
