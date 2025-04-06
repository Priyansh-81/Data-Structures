#include<stdio.h>
#include<stdlib.h>
/*Let list1 = (x1, x2…..xn) and list2= (y1, y2…..ym). Write a function to merge list1 and
list2 to obtain list3 = (x1, y1, x2, y2….xm,ym,xm+1…xn) for m<=n; and list3=(x1,
y1,x2,y2…..xn, yn, xn+1….xm) for m>n. */
typedef struct node{
    int info;
    struct node* next;
}node;

node* insertend(node* start);
void traverse(node* start);
node* merge(node* start1,node* start2);

int main(){
    node* l1start=NULL;
    node* l2start=NULL;
    int m,n;

    printf("Creating first list:\n");
    printf("Inserting the elements at the end\n");
    printf("Enter the value m:\n");
    scanf("%d",&m);
    int i=0;
    int j=0;
    while(i<m){
        l1start=insertend(l1start);
        i++;
    }
    printf("First list is :\t");
    traverse(l1start);

    printf("Creating second list:\n");
    printf("Inserting the elements at the end\n");
    printf("Enter the value n:\n");
    scanf("%d",&n);
    while(j<n){
        l2start=insertend(l2start);
        j++;
    }
    printf("Second list is :\t");
    traverse(l2start);

    node* l3start=merge(l1start,l2start);
    printf("Merged list is\n");
    traverse(l3start);
    return 0;
}
node* insertend(node* start){
    node* temp=(node*)malloc(sizeof(node));
    printf("enter the element\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }

    node* cur=start;
    while(cur!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
    return start;
}

void traverse(node* start){
    if(start==NULL){
        printf("Empty list\n");
        return;
    }
    node* cur=start;
    while(cur!=NULL){
        printf("%d\t",cur->info);
        cur=cur->next;
    }
    printf("\n");
}

node* merge(node* start1, node* start2) {
    node *start3 = NULL, *last = NULL;
    node *cur1 = start1;
    node *cur2 = start2;

    // Alternate nodes from both lists until one list is exhausted
    while (cur1 != NULL && cur2 != NULL) {
        // Add a node from list1
        node* temp1 = (node*)malloc(sizeof(node));
        temp1->info = cur1->info;
        temp1->next = NULL;

        if (start3 == NULL) {
            start3 = temp1;
            last = start3;
        } else {
            last->next = temp1;
            last = temp1;
        }
        cur1 = cur1->next;

        // Add a node from list2
        node* temp2 = (node*)malloc(sizeof(node));
        temp2->info = cur2->info;
        temp2->next = NULL;

        last->next = temp2;
        last = temp2;

        cur2 = cur2->next;
    }

    // If list1 has remaining nodes, add them
    while (cur1 != NULL) {
        node* temp = (node*)malloc(sizeof(node));
        temp->info = cur1->info;
        temp->next = NULL;

        last->next = temp;
        last = temp;
        cur1 = cur1->next;
    }

    // If list2 has remaining nodes, add them
    while (cur2 != NULL) {
        node* temp = (node*)malloc(sizeof(node));
        temp->info = cur2->info;
        temp->next = NULL;

        last->next = temp;
        last = temp;
        cur2 = cur2->next;
    }

    return start3;
}
