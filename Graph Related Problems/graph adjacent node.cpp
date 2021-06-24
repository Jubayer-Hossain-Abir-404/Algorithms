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

void adjacent_node(int i)
{
    printf("The adjacent nodes of %d are: ",i);
    for(int j=1;j<=n;j++)
    {
        if(a[i][j]==1)
        {
            printf("%d ",j);
        }
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
    int m;
    printf("\nInput the node of which you want to find out the adjacent nodes:");
    scanf("%d",&m);
    adjacent_node(m);
}
