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

void find_self_loop()
{
    int c=0;
    for(int i=1;i<=v;i++)
    {
        if(adj[i][i]==1)
        {
            c=1;
            printf("\nThere is a self loop\n");
            break;
        }
    }
    if(c==0)
    {
        printf("\nThere is no self loop\n");
    }
}


int main()
{
    printf("Input Number of Vertex:");
    scanf("%d",&v);
    build_graph();
    display();
    find_self_loop();
    return 0;
}



