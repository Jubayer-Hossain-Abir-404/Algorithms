#include<iostream>
#include<vector>
using namespace std;
int adj[100][100]= {0},v=0,p,q,color[100],pre[10],d[100],f[100],time,m=0;


void build_graph()
{
    int k=1;
    do
    {
        cout<<"Edge "<<k<<":";
        cin>>p>>q;
        if(p==0&&q==0)
        {
            break;
        }
        else if(p<=0||q<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(p>v||q>v)
        {
            cout<<"\nInvalid Input\n";
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
    cout<<"\nDisplay graph data in matrix form:\n";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void DFS_acycle(int u)
{
    color[u]=1;
    time++;
    d[u]=time;
    for(int i=1;i<=v;i++)
    {
        if(adj[u][i]==1)
        {
            if(color[i]==0)
            {
                pre[i]=u;
                DFS_acycle(i);
            }
            else
            {
                m=1;
                cout<< "\nCycle Exists\n";
            }
        }
    }
    color[u]=2;
    time++;
    f[u]=time;
}

void DFS()
{
    for(int i=1;i<=v;i++)
    {
        color[i]=0;
        pre[i]=-1;
        f[i]=112000;
        d[i]=112000;
    }
    time=0;
    for(int i=1;i<=v;i++)
    {
        if(color[i]==0)
        {
           DFS_acycle(i);
        }
    }
}



int main()
{
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    display();
    DFS();
    if(m==0)
    {
        cout<< "\nAcyclic\n";
    }
    return 0;
}


