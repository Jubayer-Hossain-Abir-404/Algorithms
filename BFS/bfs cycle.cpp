#include<stdio.h>
#include<stdlib.h>
int a[100][100]= {0},color[100],prev[100],d[100],n=0,s,v,u,i;
struct node
{
    int data;
    struct node *next;
};

int  build_graph()
{
    int p,q,c=0;
    while(1)
    {
        c++;
        printf("Enter the vertices you want to make it a part of the graph(if p=0 and q=0 then out of loop):");
        scanf("%d%d",&p,&q);
        if(p==0||q==0)
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
void ENQUEUE(node *s,int data)
{
    node *temp=s->next;
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data;
    s->next->next=temp;
}

int DEQUEUE(node *s)
{
    node *temp,*temp1;
    while(s->next!=NULL)
    {
        temp=s->next->next;
        if(temp==NULL)
        {
            break;
        }
        s=s->next;
    }
    temp1=s->next;
    s->next=NULL;
    return temp1->data;
}

void BFS(node *Q,int s)
{
    for(i=1; i<=n; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=112000;
    }
    color[s]=1;
    d[s]=0;
    prev[s]=-1;
    ENQUEUE(Q,s);
    while(Q->next!=NULL)
    {
        u=DEQUEUE(Q);
        for(i=1; i<=n; i++)
        {
            if(a[u][i]==1)
            {
                if(color[i]==0)
                {
                    color[i]=1;
                    d[i]=d[u]+1;
                    prev[i]=u;
                    ENQUEUE(Q,i);
                }
            }
        }
        color[u]=2;
    }
}

void BFS_display()
{
    printf("\nThe reachable vertices are:\n");
    for(i=1; i<=n; i++)
    {
        if(color[i]==2&&i==1)
        {
            printf("%d",i);
        }
        else if(color[i]==2)
        {
            printf(" -> %d  ",i);
        }
        else
        {
            printf("\nBFS not possible. Not all nodes are reachable\n");
            break;
        }
    }
    printf("\n");
}
int  bfs_cycle()
{
    int m=0;
    for(i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j!=i)
            {
                if(a[i][j]==1)
                {
                    if(color[j]==2&&prev[j]!=i)
                    {
                        m=i;
                        for(int k=1;k<=n;k++)
                        {
                            if(prev[j]==prev[m]&&j!=m)
                            {
                                //printf("\n%d,prev[j]=%d\n",j,prev[j]);
                                //printf("\n%d,prev[m]=%d\n",m,prev[m]);
                                return 1;
                            }
                            else if(prev[m]==-1)
                            {
                                break;
                            }
                            else
                            {
                                m=prev[m];
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    node *first;
    first=(node*)malloc(sizeof(node));
    first->next=NULL;
    printf("How many vertices do you want to create:");
    scanf("%d",&n);
    int c=build_graph();
    if(c==1)
    {
        printf("\nThere is no connection to work with\n");
    }
    else
    {
        int e=0;
        while(1)
        {
            printf("Enter the starting vertex:");
            scanf("%d",&s);
            for(int j=1; j<=n; j++)
            {
                if(a[s][j]==0)
                {
                    e++;
                }
            }
            if(e==n)
            {
                printf("\nInvalid Input\n");
            }
            else if(s==0||s<0)
            {
                printf("\nInvalid Input\n");
            }
            else if(s<=n)
            {
                break;
            }
            else
            {
                printf("\nInvalid Input\n");
            }
        }
        BFS(first,s);
        display();
        BFS_display();
        int m=bfs_cycle();
        if(m==1)
        {
            printf("\nThere is a cycle\n");
        }
        else
        {
            printf("\nThere is no cycle\n");
        }
    }
    return 0;
}

