#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int x[20];
bool place(int k, int i)
{
    int j;
    for(j=1;j<k;j++)
    {
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
            return false;
    }
    return true;
}
void print(int x[], int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n");
}
void nqueen(int k, int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i; 
            if(k==n)
                print(x,n);
            else 
                nqueen(k+1,n);
        }
    }
}
int main()
{
    int n;
    printf("Enter no. of queens (Not more than 8 Queens):");
    scanf("%d",&n);
    nqueen(1,n);
    return 0;
}