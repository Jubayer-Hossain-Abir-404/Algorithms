#include<stdio.h>
int a[10][10],n=0;


void build_graph()
{
    int i,j;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("Input a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void mountain_bike()
{
    int c=0,d=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0)
        {
            c++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                d++;
            }
        }
    }
    if(c==n&&d==n*(n-1))
    {
        printf("Yes, there a cycle exist");
    }
    else
    {
        printf("Here no cycle exists");
    }
}

void display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("How many nodes are in there:");
    scanf("%d",&n);
    build_graph();
    printf("\n");
    display();
    printf("\nDoes any cycle exist in the graph:\n");
    mountain_bike();
}


