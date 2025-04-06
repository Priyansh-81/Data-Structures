#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int rollNo;
    char grade;
} Student;

// Function prototypes
void readStudents(Student students[], int *n);
void displayStudents(Student students[], int n);
void sortStudentsByRollNo(Student students[], int n);

int main() {
    Student students[MAX];
    int n = 0;
    readStudents(students, &n);
    sortStudentsByRollNo(students, n);
    displayStudents(students, n);

    return 0;
}

//read
void readStudents(Student students[], int *n) {
    int i;

    printf("Enter the number of students: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
}

//display
void displayStudents(Student students[], int n) {
    int i;

    printf("\nStudent Information:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Grade: %c\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

//roll number sort
void sortStudentsByRollNo(Student students[], int n) {
    int i, j;
    Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (students[i].rollNo > students[j].rollNo) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
