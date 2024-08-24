#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *next;
};
struct node *top = NULL;
struct node *display(struct node *top)
{
  struct node *ptr;
  ptr=top;
  if(ptr==NULL)
	printf("\nStack is Empty\n");
  else
  {
    printf("\nElements on stack\n");
    while(ptr!=NULL)
    {
      printf("%d\n",ptr -> data);
      ptr=ptr -> next;
    }
  }
  return top;
};
struct node *push(struct node *top,int val)
{
  struct node *new_node;
  new_node =(struct node *) malloc(sizeof(struct node));
  new_node -> data =val;
  if(top==NULL)
	new_node -> next =NULL;
  else
	new_node -> next = top;

  top=new_node;
  return top;
};
struct node *pop(struct node *top)
{
  struct node *ptr;
  if(top==NULL)
  {
    printf("\nSTACK UNDERFLOW\n");
  }
  else
  {
    ptr=top;
    top=top->next;
    free(ptr);
  }
  return top;
};
void peek(struct node *top)
{
  int val;
  if(top==NULL)
	printf("\nStack is Empty\n");
  else
  {
	val=top->data;
	printf("Element on top of stack: %d ",val);
  }
}
void main()
{
  int option,num;
  clrscr();
  do
  {
    printf("\n\n***** Main Menu *****");
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.PEEK");
    printf("\n4.DISPLAY");
    printf("\n5.EXIT");
    printf("\n********************************\n");
    printf("\nEnter an option: ");
    scanf("%d",&option);
    switch(option)
    {
      case 1: printf("Enter element to push: ");
		scanf("%d",&num);
		top = push(top,num);
		break;
      case 2:top = pop(top);
		break;
      case 3:peek(top);
		break;
      case 4:top = display(top);
		break;
      case 5: printf("\nPress ENTER to exit\n");
		break;
      default: printf("\nEnter valid option\n");
		break;
    }
  }while(option!=5);
  getch();
}