#include<stdio.h>
#include<conio.h>
#define max 5
int queue[max],front=-1,rear=-1;
void insert(int queue[],int val)
{
    if (rear == max-1)
        printf("\nQueue overflow\n");
    else if((front==-1)&&(rear==-1))
    {
        front=0;
        rear=0;
        queue[rear]=val;
    }
    else 
    {
        rear++;
        queue[rear]=val;
    }
}
int delete(int queue[])
{
    int val;
    if((front==-1) || (front>rear))
    {
        printf("\nQueue underflow\n");
        return -1;
    }
    else 
    {
        val=queue[front];
        front++;
        if(front>rear)
        {
            front =-1;
            rear=-1;
        }
        return val;
    }
}
int peek(int queue[])
{
    if((front==-1) || (front>rear))
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
        return(queue[front]);
}
void display(int queue[])
{
    int i;
    if((front==-1) || (front>rear))
        printf("\nQueue is empty\n");
    else 
    {
        for(i=front; i<=rear; i++)
            printf("\n%d", queue[i]);
        printf("\n");
    }
}
void main()
{
    int val,option;
    do{
        printf("\n***** OPTION MENU *****");
        printf("\n1.Insert element in queue");
        printf("\n2. Delete element from queue");
        printf("\n3.View first element in queue");
        printf("\n4.View all elements in queue");
        printf("\n5.EXIT");
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter element to insert: ");
                    scanf("%d", &val);
                    insert(queue, val);
                    break;
            case 2: val =delete(queue);
                    if(val!=-1)
                        printf("Deleted element: %d", val);
                    break;
            case 3: val =peek(queue);
                    if(val!=-1)
                        printf("First element: %d", val);
                    break;
            case 4: display(queue);
                    break;
        }
    }while(option!=5);
    getch();
}