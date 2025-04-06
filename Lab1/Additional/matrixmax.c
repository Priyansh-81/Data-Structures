#include<stdio.h>
int max(int i,int j);
int main()
{
    int m,n;
    printf("Enter the degree mXn of the matrix :\n");
    scanf("%d%d",&m,&n);
    int mat[m][n],arr[m][n];
    printf("Enter the elements of matrix 1\n");
    for(int i=0;i<m;i++)
        {
            printf("Enter row %d elements",i+1);
            for(int j=0;j<n;i++)
                {
                    scanf("%d",&mat[i][j]);
                }
        }
    printf("Enter the elements of matrix 2\n");
    for(int i=0;i<m;i++)
        {
            printf("Enter row %d elements",i+1);
            for(int j=0;j<n;i++)
                {
                    scanf("%d",&arr[i][j]);
                }
        }

    int result[m][n];
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    result[i][j]=max(mat[i][j],arr[i][j]);
                }
        }
}
int max(int i,int j)
{
    if(i>j){
        return i;
    }
    else{
        return j;
    }
}
