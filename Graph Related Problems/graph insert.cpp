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
void add_vertex()
{
    for(int i=1; i<=n+1; i++)
    {
        a[n+1][i]=0;
        a[i][n+1]=0;
    }
    n++;
}

void add_edge()
{
    for(int i=1; i<=n; i++)
    {
        printf("Input a[%d][%d]=",i,n);
        scanf("%d",&a[i][n]);
        a[n][i]=a[i][n];
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
    display();
    add_vertex();
    printf("\n");
    display();
    add_edge();
    printf("\n");
    display();
}
