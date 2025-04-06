#include<stdio.h>
#define MAX 100

struct circularq{
int f,r;
int arr[MAX];
int count}s;

void enque(int);
void deque(int);
void display(int);


void enque(int queuesize){
    if(s.count==queuesize)
    {
        printf("The queue is full\n");
        return;
    }
    int ele;
    printf("Enter the element you want to enque\n");
    scanf("%d",&ele);
    s.r=s.r+1%queuesize;
    s.arr[s.r]=ele;
    s.count++;
}

void deque(int queuesize){
    if(s.count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    s.f=s.f+1%queuesize;
    printf("%d is removed\n",s.arr[s.f]);
    s.count--;
}

void display(int queuesize){
    if(s.count==0)
    {
        printf("The queue is empty, nothing to display\n");
        return;
    }
    for(int i=(s.f+1)%queuesize;i!=(s.r+1)%queuesize;i=(i+1)%queuesize)
    {
        printf("%d\t",s.arr[i]);
    }
}
int main()
{
    s.f=-1;
    s.r=-1;
    s.count=0;
    int queuesize;
    printf("enter the size of the queue\n");
    scanf("%d",&queuesize);
    int ch;
    while(1)
    {
        printf("\nEnter choice\n1.enque\n2.deque\n3.display\n4.exit\n");
        scanf("%d",&ch);
        if(ch==4)
            break;
        switch(ch)
        {
        case 1:
            enque(queuesize);
            break;
        case 2:
            deque(queuesize);
            break;
        case 3:
            display(queuesize);
            break;
        default:
            break;
        }
    }
    printf("\nThank You!\n");
    return 0;
}
