 #include <stdio.h>

int length(char arr[]);
void concat(char str1[], char str2[]);
int comparison(char str1[], char str2[]);
void insert();
void del();

/* Write a program to perform the following string operations without using string handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a substring
e.) to delete a substring */

int main() {
    int ch;
    printf("1. Length\n2. Concatenation\n3. Comparison\n4. Insert\n5. Delete\n");
    scanf("%d", &ch);
    fflush(stdin);  // Clear input buffer after reading integer

    switch (ch) {
        case 1: {
            printf("Enter string to calculate length\n");
            char str[100];
            gets(str);
            printf("There are %d characters in the entered string\n", length(str));
            break;
        }
        case 2: {
            printf("Enter string 1\n");
            char str1[100];
            gets(str1);
            printf("Enter string 2\n");
            char str2[100];
            gets(str2);
            concat(str1, str2);
            printf("Concatenated string: %s\n", str1);
            break;
        }
        case 3: {
            printf("Enter string 1\n");
            char str3[100];
            gets(str3);
            printf("Enter string 2\n");
            char str4[100];
            gets(str4);
            int result = comparison(str3, str4);
            if (result == 0) {
                printf("Both the strings are equal\n");
            } else if (result > 0) {
                printf("1st string is bigger\n");
                puts(str3);
            } else {
                printf("2nd string is bigger\n");
                puts(str4);
            }
            break;
        }
        case 4: {
            insert();
            break;
        }
        case 5: {
            del();
            break;
        }
        default: {
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}

// Function to calculate the length of a string
int length(char arr[]) {
    int count = 0;
    while (arr[count] != '\0') {
        count++;
    }
    return count;
}

// Function to concatenate two strings
void concat(char str1[], char str2[]) {
    int len1 = length(str1);
    int len2 = length(str2);
    for (int i = 0; i <= len2; i++) {
        str1[len1 + i] = str2[i];
    }
}

// Function to compare two strings
int comparison(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to insert a substring into a string
void insert() {
    char str[100];
    char sub[50];
    int pos;

    printf("Enter the main string\n");
    gets(str);
    printf("Enter the substring to be inserted\n");
    gets(sub);
    printf("Enter the position for insertion\n");
    scanf("%d", &pos);

    int lenStr = length(str);
    int lenSub = length(sub);

    // Shift the main string to make space for the substring
    for (int i = lenStr - 1; i >= pos; i--) {
        str[i + lenSub] = str[i];
    }

    // Insert the substring
    for (int i = 0; i < lenSub; i++) {
        str[pos + i] = sub[i];
    }

    printf("String after insertion: %s\n", str);
}

// Function to delete a substring from a string
void del() {
    char str[100];
    char del[50];

    printf("Enter the main string\n");
    gets(str);
    printf("Enter the substring to be deleted\n");
    gets(del);

    int lenStr = length(str);
    int lenDel = length(del);
    int found = 0;

    for (int i = 0; i <= lenStr - lenDel; i++) {
        int j;
        for (j = 0; j < lenDel; j++) {
            if (str[i + j] != del[j]) {
                break;
            }
        }
        if (j == lenDel) {  // Substring found
            found = 1;
            for (int k = i; k <= lenStr - lenDel; k++) {
                str[k] = str[k + lenDel];
            }
            str[lenStr - lenDel] = '\0';  // Null-terminate the string after deletion
            break;
        }
    }

    if (found) {
        printf("String after deletion: %s\n", str);
    } else {
        printf("Substring not found\n");
    }
}
