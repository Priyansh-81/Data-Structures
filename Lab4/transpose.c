#include<stdio.h>
#define MAX 100

typedef struct spmatrix{
int r,c,v;
}spmatrix;

void read(spmatrix arr[]);
void trans(spmatrix arr[],spmatrix arrt[]);
void ftrans(spmatrix arr[],spmatrix arrt[]);

void read(spmatrix arr[]){
int m,n;
printf("Enter the order of the matrix\n");
scanf("%d%d",&m,&n);
int i,j,ele,k=1;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        printf("Enter %d,%d element ",i,j);
        scanf("%d",&ele);

        if(ele==0){
            continue;
        }
        arr[k].r=i;
        arr[k].c=j;
        arr[k].v=ele;
        k++;
    }
}
arr[0].r=m;
arr[0].c=n;
arr[0].v=k-1;
}

void trans(spmatrix arr[],spmatrix arrt[])
{
    arrt[0].r=arr[0].c;
    arrt[0].c=arr[0].r;
    arrt[0].v=arr[0].v;
    int i,j,k=1;
    for(i=0;i<arr[0].c;i++)
    {
        for(j=1;j<=arr[0].v;j++)
        {
            if(arr[j].c==i){
                arrt[k].r=arr[j].c;
                arrt[k].c=arr[j].r;
                arrt[k].v=arr[j].v;
                k++;
            }
        }
    }
}
void ftrans(spmatrix arr[],spmatrix arrt[])
{
    arrt[0].r=arr[0].c;
    arrt[0].c=arr[0].r;
    arrt[0].v=arr[0].v;
    int sp[arr[0].c];
    int rT[arr[0].c];
    int k;
    
    for(int i=0;i<arr[0].c;i++)
    {
        rT[i]=0;
    }
    for(int i=1;i<=arr[0].v;i++)
    {
        rT[arr[i].c]++;
    }
    sp[0]=1;
    for(int i=1;i<arr[0].c;i++)
    {
        sp[i]=rT[i-1]+sp[i-1];
    }
    for(int i=1;i<=arr[0].v;i++)
    {
        k=sp[arr[i].c]++;
        arrt[k].r=arr[i].c;
        arrt[k].c=arr[i].r;
        arrt[k].v=arr[i].v;
    }

}
int main()
{
    spmatrix S[MAX],T[MAX],F[MAX];

    read(S);
    trans(S,T);
    printf("Using normal transpose method\n");
    for(int i=0;i<=S[0].v;i++){
        printf("%d\t%d\t%d\n",T[i].r,T[i].c,T[i].v);
    }
    ftrans(S,F);
    printf("Using fast transpose method\n");
    for(int i=0;i<=S[0].v;i++){
        printf("%d\t%d\t%d\n",F[i].r,F[i].c,F[i].v);
    }
    printf("Thank you!\n");
}
