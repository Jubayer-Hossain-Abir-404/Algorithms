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
void fruity_nutty()
{
    int c=0,d=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==1)
        {
            printf("There is a loop in node %d\n",i);
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
    printf("\nDoes any loop exist in the graph:\n");
    fruity_nutty();
}


