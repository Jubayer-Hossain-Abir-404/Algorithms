#include<stdio.h>
int adj[100][100]= {0},v=0,p,q,b[100];

void build_graph()
{
    int k=1;
    do
    {
        printf("Edge %d:",k);
        scanf("%d%d",&p,&q);
        if(p==0&&q==0)
        {
            break;
        }
        else if(p<=0||q<=0)
        {
            printf("\nInvalid Input\n");
        }
        else if(p>v||q>v)
        {
            printf("\nInvalid Input\n");
        }
        else if(adj[p][q]==1)
        {
            printf("\nInvalid Input\n");
        }
        else
        {
            adj[p][q]=1;
            //adj[q][p]=1;
            k++;
        }
    }
    while(1);
}

void display()
{
    printf("The graph you entered is as Follows\n");
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}

void adjacent_node()
{
    int m,n;
    printf("Enter two vertices you want to find if they are adjacent or not:");
    scanf("%d%d",&m,&n);
    do
    {
        if(m<=0||n<=0)
        {
            printf("\nInvalid Input\n");
        }
        else if(p>v||q>v)
        {
            printf("\nInvalid Input\n");
        }
        else
        {
            break;
        }
    }
    while(1);
    if(adj[m][n]==1||adj[n][m]==1)
    {
        printf("\nThe nodes are adjacent\n");
    }
    else
    {
        printf("\nThe nodes are not adjacent\n");
    }
}

int main()
{
    printf("Input Number of Vertex:");
    scanf("%d",&v);
    build_graph();
    display();
    adjacent_node();
    return 0;
}
