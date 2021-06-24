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
bool connected()
{
    int c=0,d=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0&&a[j][i]==0)
            {
                c++;
            }
        }
        if(c==n)
        {
            return false;
        }
        c=0;
    }
    return true;
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
    printf("\nIs the graph connected or disjoint:");
    bool m;
    m=connected();
    if(m==true)
    {
        printf("\nThe graph is connected\n");
    }
    else
    {
        printf("\nThe graph is not connected\n");
    }
}
