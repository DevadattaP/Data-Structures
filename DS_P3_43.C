#include<stdio.h>
#include<conio.h>
#define max 3
int stack[max], top=-1, value, choice;
void push(int stack[],int value)
{
  if(top==max-1)
	printf("\n Stack is already full\n");
  else
  {	top++;
	stack[top]=value;
  }
}
int pop(int stack[])
{
  if(top==-1)
  {	printf("\n Stack is empty\n");
	return -1;
  }
  else
  {     value = stack[top];
	top--;
	return(value);
  }
}
int peek(int stack[])
{
  if(top==-1)
  {	printf("\n Stack is empty\n");
	return -1;
  }
  else
	return(stack[top]);

}
void display(int stack[])
{
  int i;
  if(top==-1)
	printf("\n Stack is empty\n");
  else
  {     printf("\nPrinting stack...\n");
	for(i=top;i>=0;i--)
		printf("\n%d",stack[i]);
	printf("\n");
  }
}
int main()
{ clrscr();
  do{
	printf("\n Choice Menu ");
	printf("\n 1.Push ");
	printf("\n 2.Pop ");
	printf("\n 3.Peek ");
	printf("\n 4.Print ");
	printf("\n 5.Exit ");
	printf("\n Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\n Enter number to push: ");
			scanf("%d",&value);
			push(stack,value);
			break;
		case 2: value=pop(stack);
			if(value != -1)
				printf("\nDeleted value is %d\n",value);
			break;
		case 3: value=peek(stack);
			if(value != -1)
				printf("\nTop value is %d\n",value);
			break;
		case 4: display(stack);
			break;
	}
  } while(choice != 5);
  getch();
  return 0;
}