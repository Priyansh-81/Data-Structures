
#include <stdio.h>

int main()
{
    printf("Enter the number of elements in the array\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted array\n");
    for(int i = 0; i < n; i++) {
        printf("Enter %d element\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search for\n");
    int key;
    scanf("%d", &key);

    int ll = 0;
    int ul = n - 1;
    int found = 0;
    while (ll <= ul)
    {
        int mp = (ll + ul) / 2;
        if (arr[mp] == key)
        {
            found = 1;
            break;
        }
        if (arr[mp] < key)
        {
            ll = mp + 1;
        }
        else
        {
            ul = mp - 1;
        }
    }
    if (found)
        {
            printf("Element found\n");
        }
    else
        {
            printf("Element not found\n");
        }
        printf("\nThank You!!\n");
        return 0;
    }
