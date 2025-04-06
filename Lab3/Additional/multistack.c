#include<stdio.h>
#define max 100

struct multi{
int arr[max];
int top[10];
int b[10];
};

struct multi s;

void push();
void pop();
void peep();
void createStack();

int main()
{
    int ch;
    createStack();
    while(1)
    {
        printf("Select an operation\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        if(ch==4)
            break;
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        default:
            break;
        }
    }
    printf("\nThank You!\n");
    return 0;
}

void createStack()
{
    int n;
    printf("Enter the number of stacks you wanna create\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        s.top[i]=s.b[i]=((max/n)*i)-1;
    }
    s.b[n]=max-1;
}

void push()
{
    int n;
    printf("Enter the stack number 0,1,2...n you want to push element in\t");
    scanf("%d",&n);

    if(s.top[n]==s.b[n+1])
    {
        printf("Stack overflow case!\n");
        return;
    }
    printf("Enter the element you want to enter\n");
    int ele;
    scanf("%d",&ele);

    s.arr[++s.top[n]]=ele;
    return;
}

void pop()
{
    printf("Enter the stack number 0,1,2...n you want to pop from\t");
    int n;
    scanf("%d",&n);

    if(s.top[n]==s.b[n])
    {
        printf("Underflow condition\n");
        return;
    }
    printf("%d will be popper out.",s.arr[s.top[n]--]);
    return;
}

void peep()
{
    printf("Enter the stack number 0,1,2,3...n you want to display\n");
    int n;
    scanf("%d",&n);
    if(s.top[n]==s.b[n])
    {
        printf("Underflow condition\n");
        return;
    }
    for(int i=s.top[n];i>s.b[n];i--)
    {
        printf("%d\n",s.arr[i]);
    }
    return;
}
