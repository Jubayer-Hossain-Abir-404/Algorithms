#include<stdio.h>
#include<stdlib.h>
int a[100][100]= {0},color[100],prev[100],d[100],n=0,s,v,u,i,visited[100];
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

void print_path(int s,int v)
{
    if(v==s)
    {
        printf("%d  ",s);
    }
    else if(prev[v]==-1)
    {
        printf("\nNo path\n");
        return;
    }
    else
    {
        print_path(s,prev[v]);
        printf("%d ",v);
    }
}

void max_dis()
{
    int maximum=d[1],v;
    for(int i=2;i<=n;i++)
    {
        if(d[i]>maximum)
        {
            maximum=d[i];
            v=i;
        }
    }
    printf("\nThe largest path's distance is:%d\n",maximum);
    printf("\nThe path to the largest distance\n");
    print_path(1,v);
}


int main()
{
    node *first,*first1;
    first=(node*)malloc(sizeof(node));
    first->next=NULL;
    first1=(node*)malloc(sizeof(node));
    first1->next=NULL;
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
        max_dis();
    }
    return 0;
}
