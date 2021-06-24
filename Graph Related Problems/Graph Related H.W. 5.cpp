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

void find_outdegree()
{
    for(int i=1; i<=v; i++)
    {
        int c=0;
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                c++;
            }
        }
        b[i]=c;
    }
    printf("\nThe vertices having odd out degree:\n");
    for(int i=1; i<=v; i++)
    {
        if(b[i]%2!=0)
        {
            printf("%d ",i);
        }
    }
}


int main()
{
    printf("Input Number of Vertex:");
    scanf("%d",&v);
    build_graph();
    display();
    find_outdegree();
    return 0;
}


