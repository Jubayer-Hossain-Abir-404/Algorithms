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
void find_vertex(int m)
{
    int i=1,c=0;
    while(i<=n)
    {
        if(m==i)
        {
            printf("\n%d vertex is found",m);
            c=1;
            break;
        }
        i++;
    }
    if(c==0)
    {
        printf("\n%d vertex is not found\n",m);
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
    int m;
    printf("How many nodes are in there:");
    scanf("%d",&n);
    build_graph();
    display();
    printf("Input the vertex you want to find:");
    scanf("%d",&m);
    printf("\n");
    find_vertex(m);
    return 0;
}
