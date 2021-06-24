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
void delete_vertex(int m)
{
    for(int i=1;i<=n;i++)
    {
        a[m][i]=0;
        a[i][m]=0;
    }
    for(int i=1;i<=n;i++)
    {
        a[m][i]=a[m+1][i];
        a[i][m]=a[i][m+1];
    }
    n--;
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
    int m;
    printf("How many nodes are in there:");
    scanf("%d",&n);
    build_graph();
    display();
    printf("Input the vertex you want to delete:");
    scanf("%d",&m);
    printf("\n");
    delete_vertex(m);
    display();
}

