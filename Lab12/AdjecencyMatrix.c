#include<stdio.h>
#define MAX 10

void directededge(int mat[MAX][MAX], int u,int v){
    mat[u][v]=1;
}

void undirectededge(int mat[MAX][MAX],int u,int v){
    mat[u][v]=1;
    mat[v][u]=1;
}

int main(){
    int mat[MAX][MAX];
    int vertex;
    printf("Enter the number of vertex: ");
    scanf("%d",&vertex);

    if(vertex>MAX){
        printf("Number of vertices exeeded the number that was initially thought of!");
        return 0;
    }

    //first initialize the matrix
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            mat[i][j]=0;
        }
    }

    //then we ask the use what are we doing
    printf("Enter the Graph type\n1. Undirected Graph\n2. Directed Graph\n");
    int choice;
    scanf("%d",&choice);

    printf("Enter the number of edges\n");
    int edge,u,v;
    scanf("%d",&edge);

    for(int i=0;i<edge;i++){
        printf("Enter the edge(u->v) :");
        scanf("%d%d",&u,&v);

        if(u>=vertex||v>=vertex){
            printf("Invalid edge\n Not possible\n");
            i--;
            continue;
        }

        if(choice==1){
            undirectededge(mat,u,v);
        }else if(choice==2){
            directededge(mat,u,v);
        }else{
            printf("Invalid choice!\n");
        }
    }

    //printing the matrix
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
