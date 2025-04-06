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
    printf("SELECT 1 for Ascending and 2 for Descending\n");
    int ch;
    scanf("%d",&ch);

    //sorting using bubble sort
    if(ch==1)
        {//ascending order
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n-i-1;j++){
                    if(arr[j]<arr[i]){
                        int temp=arr[j];
                        arr[j]=arr[i];
                        arr[i]=temp;
                    }
                }
            }
        }
    else if(ch==2)
    {//descending order
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }



    printf("The altered array is\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}
