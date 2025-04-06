#include<stdio.h>
#define MAX 100

struct Queue{
int arr[MAX];
int f,r;
}s;

void enque()
{
    if(s.r==MAX-1)
    {
        printf("Queue is already full\n");
        return;
    }
    int ele;
    printf("Enter the element that you want to enque:\t");
    scanf("%d",&ele);

    s.arr[++s.r]=ele;
}

void deque()
{
    if(s.f==s.r)
    {
        printf("The queue is empty nothing to deque:\t");
        return;
    }
    printf("%d will be dequed.\n",s.arr[++s.f]);
}
void display()
{
    if(s.f==s.r){
        printf("Queue is already empty\nNothing to Display\n");
        return;
    }
    for(int i=s.f+1;i<=s.r;i++)
    {
        printf("%d\t",s.arr[i]);
    }
    printf("\n");
}

int main()
{
    s.f=-1;
    s.r=-1;
    int ch;
    while(1)
    {
        printf("Enter choice\n1.enque\n2.deque\n3.display\n4.exit\n");
        scanf("%d",&ch);
        if(ch==4)
            break;
        switch(ch)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
    printf("\nThank You!\n");
    return 0;
}
