#include<stdio.h>
#define MAX 100

struct stack {
int arr[MAX];
int top;
};
struct stack s;

void push(int c){
if(s.top==MAX-1){
    return;
}
s.arr[++s.top]=c;
}

int pop(){
if(s.top==-1){
    return -999;
}
return s.arr[s.top--];
}

void display()
{
    printf("Answer is %d",s.arr[s.top]);
}

void eval(char pfix[])
{
    for(int i=0;pfix[i]!='\0';i++)
    {
        if(pfix[i]=='*'||pfix[i]=='/'||pfix[i]=='+'||pfix[i]=='-')
        {
            int op2=pop();
            int op1=pop();

            switch (pfix[i])
            {
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '/':
                push(op1/op2);
                break;
            default:
                break;
            }
        }
        else
        {
            push(pfix[i]-'0');
        }
    }
}

int main()
{
    s.top=-1;
    printf("Enter an expression to evaluate\n");
    char exp[MAX];
    gets(exp);
    eval(exp);
    display();
    return 0;
}

