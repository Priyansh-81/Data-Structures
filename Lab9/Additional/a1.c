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

void multiply(node* poly1, node* poly2, node** result) {
    node* temp1 = poly1->next;
    while (temp1 != poly1) {
        node* temp2 = poly2->next;
        while (temp2 != poly2) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            *result = insert(*result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
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

    multiply(poly1, poly2, &result);
    printf("Result of multiplication: ");
    printPolynomial(result);

    return 0;
}
