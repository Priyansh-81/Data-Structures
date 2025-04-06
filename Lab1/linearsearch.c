#include<stdio.h>
int main()
{
    printf("Enter the number of elements in array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        {
            printf("Enter %d element\n",i+1);
            scanf("%d",&arr[i]);
        }
    int ele;
    printf("Enter the element to search for\n");
    scanf("%d",&ele);
    int pos=0;
    for(int i=0;i<n;i++)
        {
            if(arr[i]==ele)
                {
                    printf("Element found at %d position.\n",(i+1));
                    pos=1;
                    break;
                }
        }
    if (pos!=1)
        {
            printf("Element not found!\n");
        }
    printf("\nThank You!\n");
    return 0;
}
