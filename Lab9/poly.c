#include <stdio.h>
#include <stdlib.h>

typedef struct term {

    double coeff;
    int exp;
    struct term* next;
} term;

term* get_polynomial() {
    printf("Enter number of terms: ");
    int terms;
    scanf("%d", &terms);
    term* prev, *poly_head;
    for (int i = 1; i <= terms; i++) {
        double co;
        int ex;
        printf("Enter coefficient %d: ", i);
        scanf("%lf", &co);
        printf("Enter exponent %d: ", i);
        scanf("%d", &ex);
        term* temp = malloc(sizeof(*temp));
        temp -> coeff = co;
        temp -> exp = ex;
        if (i == 1) {
            poly_head = temp;
            prev = poly_head;
        }
        else {
            prev -> next = temp;
            prev = prev -> next;
        }
    }
    return poly_head;
}

void print_poly(term* poly_head) {
    term* cur = poly_head;
    for (; cur; cur = cur -> next) {
        if (cur -> coeff > 0)
            printf(" +%gx^", cur -> coeff);
        else if (cur -> coeff == 0)
            continue;
        else
            printf(" -%gx^", (-cur -> coeff));
        printf("%d", cur -> exp);
    }
    printf("\n");
}


term* add_poly(term* poly1, term* poly2) {
    term* cur1 = poly1, *cur2 = poly2, *sum_head, *prev;
    int i = 0;
    while (cur1 && cur2) {
        i++;
        term* temp = malloc(sizeof(*temp));
        if (cur1 -> exp > cur2 -> exp) {
            temp -> coeff = cur1 -> coeff;
            temp -> exp = cur1 -> exp;
            if (i == 1) {
                sum_head = temp;
                prev = sum_head;
            }
            prev -> next = temp;
            prev = temp;
            cur1 = cur1 -> next;
            continue;
        }
        if (cur1 -> exp < cur2 -> exp) {
            temp -> coeff = cur2 -> coeff;
            temp -> exp = cur2 -> exp;
            if (i == 1) {
                sum_head = temp;
                prev = sum_head;
            }
            prev -> next = temp;
            prev = temp;
            cur2 = cur2 -> next;
            continue;
        }
        temp -> coeff = cur1 -> coeff + cur2 -> coeff;
        if (temp -> coeff == 0) {
            free(temp);
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
            continue;
        }
        temp -> exp = cur1 -> exp;
        prev -> next = temp;
        prev = temp;
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    if (!cur2)
        cur2 = cur1;
    while (cur2) {
        term* temp = malloc(sizeof(*temp));
        temp -> coeff = cur2 -> coeff;
        temp -> exp = cur2 -> exp;
        prev -> next = temp;
        prev = temp;
        cur2 = cur2 -> next;
    }
    return sum_head;
}

int main() {
    term* poly1, * poly2, * sum;
    printf("Enter polynomial 1:\n");
    poly1 = get_polynomial();
    printf("Enter polynomial 2:\n");
    poly2 = get_polynomial();
    printf("Polynomial 1 is: ");
    print_poly(poly1);
    printf("Polynomial 2 is: ");
    print_poly(poly2);
    sum = add_poly(poly1, poly2);
    printf("The sum is: ");
    print_poly(sum);
    return 0;
}
