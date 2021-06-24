#include<stdio.h>
int a[100][100]= {0},n=0,b[100],p;

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

void find_minimum_outdegree()
{
    int c;
    printf("\n");
    for(int i=1; i<=n; i++)
    {
        c=0;
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==1&&a[j][i]==0)
            {
                c++;
            }
        }
        b[i]=c;
    }
    int minimum=b[1],p;
    for(int i=2; i<=n; i++)
    {
        if(b[i]<minimum)
        {
            minimum=b[i];
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(b[i]==minimum)
        {
            printf("\n%d has the minimum out degree by having %d degree\n",i,minimum);
        }
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
        find_minimum_outdegree();
    }
}



