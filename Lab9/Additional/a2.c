#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int coeff, int exp) {
    node* temp = (node*)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = temp->prev = temp;
    return temp;
}

node* insert(node* head, int coeff, int exp) {
    node* temp = createNode(coeff, exp);
    if (head == NULL) {
        return temp;
    }
    node* last = head->prev;
    last->next = temp;
    temp->prev = last;
    temp->next = head;
    head->prev = temp;
    return head;
}

void add(node* poly1, node* poly2, node** result) {
    node* temp1 = poly1->next;
    node* temp2 = poly2->next;

    while (temp1 != poly1 && temp2 != poly2) {
        if (temp1->exp == temp2->exp) {
            *result = insert(*result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            *result = insert(*result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            *result = insert(*result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != poly1) {
        *result = insert(*result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        *result = insert(*result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
}

void printPolynomial(node* head) {
    node* temp = head->next;
    while (temp != head) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;
    node* result = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients and exponents for the first polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly1 = insert(poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients and exponents for the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly2 = insert(poly2, coeff, exp);
    }

    add(poly1, poly2, &result);
    printf("Result of addition: ");
    printPolynomial(result);

    return 0;
}
