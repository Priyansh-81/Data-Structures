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

    if(ch==1){
        int smallest,pos;
        for(int i=0;i<n-1;i++){
            pos=i;
        smallest=arr[pos];
            for(int j=i+1;j<n;j++){
                if(arr[j]<smallest){
                    //smallest=arr[j];
                    pos=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }

    }
    if(ch==2){
        int largest,pos;
        for(int i=0;i<n-1;i++){
            pos=i;
        largest=arr[pos];
            for(int j=i+1;j<n;j++){
                if(arr[j]>largest){
                    //largest=arr[j];
                    pos=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
            
        }

    }
    printf("Sorted array in ascending order is\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\nThank You!\n");
}
