#include<stdio.h>
int v,i,j,n;
int adj[20][20];
int queue[20],status[20],front=-1,rear=-1,temp;
void enqueue(int x)
{
    if(rear!=n)
    {
        if(front==-1 && rear ==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear++;
        queue[rear]=x;
    }
}
void bfs()
{
    for(j=0;j<n;j++)
        status[j]=1;
    enqueue(v-1);
    printf("\nB.F.S traversal order: ");
    printf("%d ",queue[front]+1);
    while(front!=-1 && rear!=-1)
    {
        temp=queue[front];
        front++;
        status[temp]=2;
        for(j=0;j<n;j++)
        {
            if(adj[temp][j]==1)
            {
                if(status[j]==1)
                {
                    status[j]=2;
                    enqueue(j);
                    printf("-> %d ",j+1);
                }
            }
        }
        status[temp]=3;
    }
}
int main()
{
    printf("\n Enter number of vertices: ");
    scanf("%d",&n);
    printf("\n Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    printf("\n Enter starting vertex: ");
    scanf("%d",&v);
    bfs();
    return 0;
}
