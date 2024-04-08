#include<stdio.h>
int p[20], c[20][20], pm[20][20];
int mcm(int i, int j)
{
    int k,r,min=9999,pp;
    if(i==j)
        return 0;
    else
    {
        for(k=i;k<j;k++)
        {
            r=mcm(i,k)+mcm(k+1,j)+(p[i-1]*p[k]*p[j]);
            if(r<min)
            {
                min=r; pp=k;
            }
            c[i][j]=min; pm[i][j]=pp;
        }
    }
    return min;
}
int main()
{
    int n,a,i,j,result;
    printf("Enter number of matrices:");
    scanf("%d",&n);
    printf("Enter orders:");
    for(a=0;a<=n;a++)
        scanf("%d",&p[a]);
    i=1;j=n;
    result=mcm(i,j);
    printf("Number of minimum matrix multiplication required:%d\n",result);
    printf("Cost Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
    printf("Parenthersis Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",pm[i][j]);
        printf("\n");
    }
    return 0;
}