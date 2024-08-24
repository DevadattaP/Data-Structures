#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 100
float stack[max];
int top=-1;
void push(float stack[],float val)
{
    if(top==max-1)
    {
        printf("\nStack overflow");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
float pop()
{
    float val;
    if(top==-1)
    {
        printf("\nStack underflow");
        exit(1);
    }
    else
    {
        val=stack[top];
        top--;
    }
    return val;
}
void main()
{
    char postfix[100];
    float op1,op2;
    int i=0;
    printf("\nEnter postfix expression: ");
    gets(postfix);
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            push(stack,postfix[i]-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
            {
                case '+':push(stack,op1+op2);
                        break;
                case '-':push(stack,op1-op2);
                        break;
                case '*':push(stack,op1*op2);
                        break;
                case '/':push(stack,op1/op2);
                        break;
                case '%':push(stack,(int)(op1)%(int)(op2));
                        break;
                default:printf("\nInvalid expression...");
                        exit(1);
            }
        }
        i++;
    }
    printf("\nEvaluated expression is : %f\n",stack[0]);
    getch();
}
