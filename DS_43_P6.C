#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int num;
struct node
{
  int data;
  struct node *next;
};
struct node *start = NULL;
struct node *create_l_l(struct node *start)
{
  struct node *new_node, *ptr;
  ptr=start;
  printf("\nEnter -1 to terminate");
  printf("\nEnter data: ");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node =(struct node *) malloc(sizeof(struct node));
    new_node -> data =num;
    new_node -> next =NULL;
    if(ptr==NULL)
    {
      ptr=new_node;
      start=ptr;
    }
    else
    {
      while((ptr->next)!=NULL)
      {
	ptr=ptr->next;
      }
      ptr -> next = new_node;
      ptr = new_node;
    }
    printf("\nEnter -1 to terminate");
    printf("\nEnter data: ");
    scanf("%d",&num);
  }
  if(start!=NULL)
	printf("\nLinked List created");
  return start;
};
struct node *display_l_l(struct node *start)
{
  struct node *ptr;
  ptr=start;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
    printf("\nElements in linked list:\nStart ");
    while(ptr!=NULL)
    {
      printf("---> %d ",ptr -> data);
      ptr=ptr -> next;
    }
  }
  return start;
};
struct node *in_beg(struct node *start)
{
  struct node *new_node;
  if(start==NULL)
  {
    printf("\nNo linked list available....\nCreating linked list...\n");
    start=create_l_l(start);
  }
  else
  {
  printf("\nEnter data to insert at begining: ");
  scanf("%d",&num);
  new_node=(struct node *) malloc(sizeof(struct node *));
  new_node -> data =num;
  new_node -> next = start;
  start=new_node;
  }
  return start;
};
struct node *in_end(struct node *start)
{
  int num;
  struct node *new_node, *ptr;
  if(start==NULL)
  {
    printf("\nNo linked list available....\nCreating linked list...\n");
    start=create_l_l(start);
  }
  else
  {
  ptr=start;
  printf("Enter data: ");
  scanf("%d",&num);
  new_node = (struct node *) malloc(sizeof( struct node *));
  new_node ->data = num;
  new_node ->next = NULL;
  while(ptr->next !=NULL)
  {
    ptr = ptr->next;
  }
  ptr ->next=new_node;
  }
  return start;
};
struct node *in_bef(struct node *start)
{
  int num,val;
  struct node *new_node, *ptr, *preptr;
  if(start==NULL)
  {
    printf("\nNo linked list available....\nCreating linked list...\n");
    start=create_l_l(start);
  }
  else
  {
  printf("Enter data: ");
  scanf("%d",&num);
  printf("Enter value before which node is to be inserted: ");
  scanf("%d",&val);
  new_node = (struct node *) malloc(sizeof( struct node *));
  new_node ->data = num;
  if(val==start->data)
  {
    new_node -> next = start;
    start=new_node;
  }
  else
  {
  ptr =start;
  while(ptr->data !=val)
  {
    preptr =ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  }
  }
  return start;
};
struct node *in_aft(struct node *start)
{
  int num,val;
  struct node *new_node, *ptr,*preptr;
  if(start==NULL)
  {
    printf("\nNo linked list available....\nCreating linked list...\n");
    start=create_l_l(start);
  }
  else
  {
  printf("Enter data: ");
  scanf("%d",&num);
  printf("Enter value after which node is to be inserted: ");
  scanf("%d",&val);
  new_node = (struct node *) malloc(sizeof( struct node *));
  new_node ->data = num;
  ptr =start;
  while(preptr->data !=val)
  {
    preptr =ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  }
  return start;
};
struct node *del_beg(struct node *start)
{
  struct node *ptr;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr=start;
  start=start->next;
  free(ptr);
  }
  return start;
};
struct node *del_end(struct node *start)
{
  struct node *ptr,*preptr;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr=start;
  while(ptr->next !=NULL)
  {
    preptr =ptr;
    ptr=ptr->next;
  }
  preptr->next =NULL;
  free(ptr);
  }
  return start;
};
struct node *del_aft(struct node *start)
{
  int val;
  struct node *ptr,*preptr;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr=start;
  printf("Enter value after which node is to be deleted: ");
  scanf("%d",&val);
  while(preptr->data !=val)
  {
    preptr =ptr;
    ptr=ptr->next;
  }
  preptr->next=ptr->next;
  free(ptr);
  }
  return start;
};
struct node *del_node(struct node *start)
{
  int val;
  struct node *ptr,*preptr;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr=start;
  printf("Enter value to be deleted: ");
  scanf("%d",&val);
  if(val==start->data)
  {
    ptr=start;
    start=start->next;
    free(ptr);
  }
  else
  {
    while(ptr->data !=val)
    {
      preptr =ptr;
      ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    }
  }
  return start;
};
struct node *del_l_l(struct node *start)
{
  struct node *ptr;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr=start;
  while(ptr!=NULL)
  {
    printf("\n%d deleted",ptr->data);
    start=del_beg(ptr);
    ptr=start;
  }
  }
  return start;
};
struct node *sort_l_l(struct node *start)
{
  int temp;
  struct node *ptr1,*ptr2;
  if(start==NULL)
  {
    printf("\nLinked list is EMPTY\n");
  }
  else
  {
  ptr1=start;
  if(ptr1!=NULL)
  {
    while(ptr1->next !=NULL)
    {
      ptr2=ptr1->next;
      while(ptr2!=NULL)
      {
	if(ptr1->data >ptr2->data)
	{
	  temp=ptr1->data;
	  ptr1->data=ptr2->data;
	  ptr2->data=temp;
	}
	ptr2=ptr2->next;
      }
      ptr1=ptr1->next;
    }
  }
  }
  return start;
};
int main()
{
  int option;
  do
  {
    printf("\n\n***** Main Menu *****");
    printf("\n1.Create a list");
    printf("\n2.Display the list");
    printf("\n3.Add node at begining");
    printf("\n4.Add node at end");
    printf("\n5.Add node before given node");
    printf("\n6.Add node after given node");
    printf("\n7.Delete node at begining");
    printf("\n8.Delete node at end");
    printf("\n9.Delete node after given node");
    printf("\n10.Delete given node");
    printf("\n11.Delete entire list");
    printf("\n12.Sort list");
    printf("\n13.Exit");
    printf("\n********************************\n");
    printf("\nEnter an option: ");
    scanf("%d",&option);
    switch(option)
    {
      case 1:start = create_l_l(start);
		break;
      case 2:start = display_l_l(start);
		break;
      case 3:start = in_beg(start);
		break;
      case 4:start = in_end(start);
		break;
      case 5:start = in_bef(start);
		break;
      case 6:start = in_aft(start);
		break;
      case 7:start = del_beg(start);
		break;
      case 8:start = del_end(start);
		break;
      case 9:start = del_aft(start);
		break;
      case 10:start = del_node(start);
		break;
      case 11:start = del_l_l(start);
		break;
      case 12:start = sort_l_l(start);
		break;
      case 13: printf("\nPress ENTER to exit\n");
		break;
      default: printf("\nEnter valid option\n");
		break;
    }
  }while(option!=13);
  getch();
  return 0;
}