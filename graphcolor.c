#include<stdio.h>
int m,x[]={0,0,0,0},G[50][50];
void print(int x[], int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("Color of vertex %d:%d    ",i,x[i]);
    }
    printf("\n");
    printf("\n");
}
void nextvalue(int k,int n)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<=n;j++)
        {
            if((G[k][j]!=0) && (x[k]==x[j]))
                break;
        }
        if(j==n+1)
            return;
    }
}
void mcoloring(int k, int n)
{
    while(1)
    {
        nextvalue(k,n);
        if(x[k]==0)
            return ;
        if(k==n)
            print(x,n);
        else 
            mcoloring(k+1,n);
    }
}
int main()
{
    int i,j,n;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter no. of colors available:");
    scanf("%d",&m);
    printf("Enter the adjacency matrix of the graph:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    }
    printf("Chromatic number of each vertex:\n",n);
    mcoloring(1,n);
}