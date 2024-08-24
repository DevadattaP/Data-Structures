#include <stdio.h>
#include <conio.h>
#define max 5
int queue[max], front =-1, rear =-1;
void insert(int val)
{
    if ((front == 0 && rear == max-1)||(rear==front-1))
        printf("\nQUEUE OVERFLOW\n");
    else if (front ==-1 && rear ==-1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else if ((front != 0)&&(rear == max-1))
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}
int delet()
{
    int val;
    if ((front ==-1)&&(rear ==-1))
    {
        printf("\nQUEUE UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = queue[front];
        if (front == rear)
        {
            front = -1;
            rear =-1;
        }
        else if (front == max-1)
                front = 0;
        else
                front++;
    }
    return val;
}
int peek()
{
    if ((front ==-1)&&(rear ==-1))
    {
        printf("\n QUEUE IS EMPTY\n");
        return -1;
    }
    else
        return (queue[front]);
}
void display()
{
    int i;
    printf("\n");
    if ((front ==-1)&&(rear ==-1))
        printf("\n QUEUE IS EMPTY\n");
    else
    {
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("\n%d", queue[i]);
        }
        else
        {
                for (i = front; i <=max-1; i++)
                    printf("\n%d", queue[i]);
                for (i = 0; i <= rear; i++)
                    printf("\n%d", queue[i]);
        }
        printf("\n");
    }
}
void main()
{
    int option, val;
    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert element in queue");
        printf("\n 2. Delete element from queue");
        printf("\n 3. View first element in queue");
        printf("\n 4. View all elements queue");
        printf("\n 5. EXIT");
        printf("\n Enter an option : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:printf("\n Enter the number to insert : ");
                    scanf("%d", &val);
                    insert(val);
                    break;
            case 2:val = delet();
                    if (val !=-1)
                        printf("\n Deleted number is : %d\n", val);
                    break;
            case 3:val = peek();
                    if (val !=-1)
                        printf("\n The first number is : %d\n", val);
                    break;
            case 4:display();
                    break;
        }
    } while (option != 5);
    getch();
}
