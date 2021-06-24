#include<stdio.h>
int a[100][100]= {0},n=0,p;

int  build_graph()
{
    int p=100,q=100,c=0;
    while(1)
    {
        c++;
        printf("Enter the nodes you want to open(if p=0 and q=0 then out of loop):");
        scanf("%d%d",&p,&q);
        if(p==0&&q==0)
        {
            return c;
        }
        else if((p>n&&q>n)||(p>n||q>n))
        {
            printf("\nInvalid Input\n");
        }
        else if((p<0&&q<0)||(p<0||q<0))
        {
            printf("\nInvalid Input\n");
        }
        else if(a[p][q]==1)
        {
            printf("\nInvalid Input\n");
        }
        else
        {
            a[p][q]=1;
        }
    }
}

void display()
{
    printf("\nDisplay graph data in matrix form:\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void find_di_undi()
{
    int c=0;
    printf("\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==0&&a[j][i]==1)
            {
                c++;
            }
            else if(a[i][j]==1&&a[j][i]==0)
            {
                c++;
            }
        }
    }
    if(c==0)
    {
        printf("\nThe graph is undirected\n");
    }
    else
    {
        printf("\nThe graph is directed\n");
    }
}

int main()
{
    printf("How many nodes do you want to create:");
    scanf("%d",&n);
    int c=build_graph();
    if(c==1)
    {
        printf("There is nothing to display");
    }
    else
    {
        display();
        find_di_undi();
    }
}


