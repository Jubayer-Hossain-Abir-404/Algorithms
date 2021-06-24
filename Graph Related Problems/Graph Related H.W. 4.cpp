#include<stdio.h>
int adj[100][100]= {0},v=0,p,q,b[100],k=0;

void build_graph()
{
    k=1;
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
        else
        {
            adj[p][q]++;
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

bool multi_graph()
{
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]>1||adj[j][i]>1)
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{
    printf("Input Number of Vertex:");
    scanf("%d",&v);
    build_graph();
    display();
    bool m=multi_graph();
    if(m==true)
    {
        printf("\nThere is a multi graph\n");
    }
    else
    {
        printf("\nThere is no multi graph\n");
    }
    return 0;
}
