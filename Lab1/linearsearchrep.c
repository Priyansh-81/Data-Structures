#include<stdio.h>

void linearSearch(int arr[],int,int,int result[],int *resultSize);

int main() {
    
    int size;
    printf("Enter the number of elements in the array!\n");
    scanf("%d",&size);
           
    int arr[size];
    
    printf("Enter the elements of the array!\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ele;
    printf("Enter the element to search for \t");
    scanf("%d",&ele);
    int result[size];  // Array to store the indices of target
    int resultSize;  // Variable to store the size of result array

    linearSearch(arr, size, ele, result, &resultSize);

    if (resultSize > 0) 
    {
        printf("Element %d found at positions: ", ele);
        
        for (int i = 0; i < resultSize; i++)
        {
            printf("%d ", result[i]+1);
        }
        
        printf("\n");
    }
    else
    {
        printf("Element %d not found in the array\n", ele);
    }

    return 0;
}


void linearSearch(int arr[], int size, int ele, int result[], int *resultSize)
{
    *resultSize = 0;  // initial size of the array 0
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            result[*resultSize] = i;  // Store the index of the element that has to be searched
            (*resultSize)++;  // Increment the result size
        }
    }
}
