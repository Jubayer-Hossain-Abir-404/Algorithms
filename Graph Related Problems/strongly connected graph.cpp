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
void strongly_connected()
{
    int c=0,d=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                c++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0)
        {
            d++;
        }
    }
    if(c==n*(n-1)&&d>0||c==n*(n-1)&&d==0)
    {
        printf("\nYes, the graph is strongly connected\n");
    }
    else
    {
        printf("\nThe graph is not strongly connected\n");
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
    int m,p;
    printf("\nIs the graph strongly connected:");
    strongly_connected();
}



