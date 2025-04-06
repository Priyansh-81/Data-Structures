#include<stdio.h>

void add(int m, int a[][m], int b[][m]);
void mul(int m, int a[][m], int b[][m]);

int main() {
    int m;
    printf("Enter the dimensions of the square matrices: ");
    scanf("%d", &m);

    int a[m][m], b[m][m];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    add(m, a, b);
    mul(m, a, b);

    return 0;
}

void add(int m, int a[][m], int b[][m]) {
    int result[m][m];
    printf("Addition of matrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void mul(int m, int a[][m], int b[][m]) {
    int result[m][m];
    printf("Multiplication of matrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}