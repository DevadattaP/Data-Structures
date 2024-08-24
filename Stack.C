#include<stdio.h>
#include<conio.h>
#define max 3
int stack[max],top=-1;
void push(int stack[],int value)
{
    if(top==max-1)
        printf("\nStack overflow\n");
    else
    {
        top++;
        stack[top]=value;
    }
}
int pop(int stack[])
{
    int value;
    if(top==-1)
    {
        printf("\nStack underflow\n");
        return -1;
    }
    else
    {
        value=stack[top];
        top--;
        return value;
    }
}
void display(int stack[])
{
    int i;
    if(top==-1)
        printf("\nStack is empty\n");
    else
    {
        for(i=top;i>=0;i--)
            printf("\n%d ",stack[i]);
        printf("\n");
    }
}
int peek(int stack[])
{
    if(top==-1)
    {
        printf("\nStack is empty\n");
        return -1;
    }
    else
        return stack[top];
}
int main()
{
    int value,option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. push");
        printf("\n 2. pop");
        printf("\n 3. display");
        printf("\n 4. peek");
        printf("\n 5. exit");
        printf("\n Enter your option ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:printf("\nEnter number to push on stack ");
                    scanf("%d",&value);
                    push(stack,value);
                    break;
            case 2:value=pop(stack);
                    if (value!=-1)
                        printf("\nThe value deleted is %d",value);
                    break;
            case 3:value=peek(stack);
                    if (value!=-1)
                        printf("\nThe value stored at the top of stack is %d",value);
                    break;
            case 4:display(stack);
                    break;
        }
    } while (option!=5);
    return 0;
}