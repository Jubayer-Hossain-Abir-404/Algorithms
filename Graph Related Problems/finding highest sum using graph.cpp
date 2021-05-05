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
            a[q][p]=1;
        }
    }
}
void find_highest_sum()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            b[i]=b[i]+a[i][j];
        }
    }
    int maximum=b[1];
    for(int i=1; i<=n; i++)
    {
        if(b[i]>maximum)
        {
            maximum=b[i];
            p=i;
        }
    }
    printf("\nThe highest sum is for no. %d node :%d\n",p,b[p]);
}
void display()
{
    printf("\nDisplay:\n");
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
    printf("How many nodes do you want to create:");
    scanf("%d",&n);
    //insert_graph();
    // display();
    int c=build_graph();
    if(c==1)
    {
        printf("There is nothing to display");
    }
    else
    {
        display();
        find_highest_sum();
    }
}

