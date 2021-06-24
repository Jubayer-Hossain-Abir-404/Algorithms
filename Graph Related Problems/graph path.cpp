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
void path_less(int m,int p)
{
    int c=0;
    if(a[m][p]==1)
    {
        c=1;
        printf("\nThere is a direct path from %d to %d",m,p);
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            if(a[m][j]==1)
            {
                if(a[j][n]==1)
                {
                    c=1;
                }
                else
                {
                    for(int k=j;k<n;k++)
                    {
                        if(a[k+1][n])
                        {
                            c=1;
                        }
                    }
                }
            }
        }
    }
    if(c==1)
    {
        printf("\nA path exists here\n");
    }
    else if(c==0)
    {
        printf("\nGuess no path exists here");
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
    printf("How many nodes are in there:");
    scanf("%d",&n);
    build_graph();
    printf("\n");
    display();
    int m,p;
    printf("\nInput the nodes you want to find the path:");
    scanf("%d%d",&m,&p);
    path_less(m,p);
}


