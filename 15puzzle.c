#include<stdio.h>
void solution(int puzzle[4][4], int shade[])
{
    int i,j,small=0,x=0,r[16],k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(puzzle[i][j]==0)
                puzzle[i][j]=16;
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            r[k]=puzzle[i][j];
            k++;
        }
    }
    for(k=0;k<16;k++)
    {
        if(r[k]>r[k+1])
            small++;
        if(r[k]==16 && shade[k]==1)
            x=1;
    }
    if((small+x)%2==0)
        printf("Puzzle matrix is solvable\n");
    else
        printf("Puzzle matrix is not solvable at all\n");
}
int main()
{
    int puzzle[4][4],i,j,temp;
    int shade[16] = {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};
    printf("Enter values between 1 to 16:");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&temp);
            if(temp==16)
                puzzle[i][j]=0;
            else
                puzzle[i][j]=temp;
        }
    }
    printf("Puzzle matrix is:\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d\t",puzzle[i][j]);
        printf("\n");
    }  
    solution(puzzle,shade); 
    return 0;
}