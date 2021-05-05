#include<iostream>
#include<limits>
using namespace std;

int adj[100][100]= {0},color[100],prev[100],d[100],f[100],v,p,q,u,time;

void build_graph()
{
    cout<< "\nInput\n\n";
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
            k++;
        }
    }
    while(1);
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time;
    for(int i=1; i<=v; i++)
    {
        if(adj[u][i]==1&&color[i]==0)
        {
            prev[i]=u;
            DFS_Visit(i);
        }
    }
    color[u]=2;
    f[u]=++time;
}
void DFS()
{
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=1112211;
        f[i]=1112211;
    }
    time=0;
    for(int i=1; i<=v; i++)
    {
        if(color[i]==0)
        {
            DFS_Visit(i);
        }
    }
}

void display()
{
    cout<< "\n\nOutput:\n";
    cout<< "\n\nVertex   : ";
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" ";
    }
    cout<< "\n\nColor    : ";
    for(int i=1; i<=v; i++)
    {
        cout<<color[i]<< " ";
    }
    cout<< "\n\ndsTime  : ";
    for(int i=1; i<=v; i++)
    {
        cout<<d[i]<< " ";
    }
    cout<< "\n\nFin Time : ";
    for(int i=1; i<=v; i++)
    {
        cout<<f[i]<< " ";
    }
    cout<< "\n\nPrevious : ";
    for(int i=1; i<=v; i++)
    {
        cout<<prev[i]<< " ";
    }
    cout<<"\n";
}

int main()
{
    cout<< "Vertex:";
    cin>>v;
    build_graph();
    DFS();
    display();
}


