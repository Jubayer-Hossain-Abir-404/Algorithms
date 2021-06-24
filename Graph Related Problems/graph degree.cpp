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

void number_of_degree(int i)
{
    int c=0;
    for(int j=1; j<=n; j++)
    {
        if(a[i][j]==1)
        {
            c++;
        }
    }
    printf("The degree of node %d are: %d",i,c);
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
    printf("\nInput the node of which you want to find out the degree:");
    scanf("%d",&m);
    number_of_degree(m);
}

