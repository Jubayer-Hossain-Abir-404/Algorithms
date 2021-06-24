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
void delete_edge(int m,int p)
{
    a[m][p]=0;
    a[p][m]=0;
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
    int m,p;
    printf("How many nodes are in there:");
    scanf("%d",&n);
    build_graph();
    display();
    printf("Input the edge you want to delete from which node to which node:");
    scanf("%d%d",&m,&p);
    printf("\n");
    delete_edge(m,p);
    display();
}


