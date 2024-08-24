#include<stdio.h>
int adj[20][20],reach[20],n;
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
        if(adj[v][i] && !reach[i])
        {
            printf("\n %d -> %d",v,i);
            dfs(i);
        }
}
int main()
{
    int i,j,v,count=0;
    printf("\n Enter number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        reach[i]=0;
        for(j=1;j<=n;j++)
            adj[i][j]=0;
    }
    printf("\n Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    printf("\n Enter starting vertex: ");
    scanf("%d",&v);
    dfs(v);
    printf("\n");
    for(i=1;i<=n;i++)
        if(reach[i])
            count++;
    if(count==n)
        printf("\nGraph is connected");
    else
        printf("\nGraph is disconnected");
    return 0;
}
