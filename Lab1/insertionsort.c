#include<stdio.h>
int main()
{
    printf("Enter the number of elements in the array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i< n;i++){
        printf("enter %d element\n",i+1);
        scanf("%d",&arr[i]);
    }

    //sorting started
    for(int j=1;j<n;j++){
        int i=j-1;
        int temp=arr[j];
        while(i>=0 && arr[i]>temp)
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=temp;

    }
    printf("\nSorted array is \n");
    for(int k=0;k<n;k++){
        printf("%d\t",arr[k]);
    }
    printf("\nThank You!\n");
}
