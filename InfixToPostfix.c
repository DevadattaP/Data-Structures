#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
void push(char stack[],char val)
{
    if(top==max-1)
	    printf("\nStack OVERFLOW");
    else
    {	
        top++;
	    stack[top]=val;
    }
}
char pop(char stack[])
{
    char val=' ';
    if(top==-1)
	    printf("\nStack UNDERFLOW");
    else
    {	
        val=stack[top];
	    top--;
    }
    return val;
}
int getpriority(char op)
{
    if(op=='/'||op=='*'||op=='%')
	    return 1;
    else if(op=='+'||op=='-')
	    return 0;
}
void infixtopostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {	
            push(stack,source[i]);
	        i++;
        }
        else if(source[i]==')')
        {	
            while((top!=-1)&&(stack[top]!='('))
	        {	
                target[j]=pop(stack);
		        j++;
	        }
	        if(top==-1)
	        {
        	    printf("\nIncorrect Expression.");
		        exit(1);
	        }
	        temp=pop(stack);
	        i++;
        }
        else if(isdigit(source[i])||isalpha(source[i]))
        {	
            target[j]=source[i];
	        j++;
	        i++;
        }
        else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
        {	
            while((top!=-1)&&(stack[top]!='(')&&(getpriority(stack[top])>getpriority(source[i])))
	        {	
                target[j]=pop(stack);
		        j++;
	        }
	        push(stack,source[i]);
	        i++;
        }
        else
        {	
            printf("\nIncorrect element in expression");
	        exit(1);
        }
    }
    while((top!=-1)&&(stack[top]!='('))
    {	
        target[j]=pop(stack);
	    j++;
    }
    target[j]='\0';
}
void main()
{
    char infix[100],postfix[100];
    system("cls");
    printf("\nEnter infix expression: ");
    gets(infix);
    strcpy(postfix,"");
    infixtopostfix(infix,postfix);
    printf("\nPostfix expression is: ");
    puts(postfix);
    getch();
}