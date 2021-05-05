#include<iostream>
#include<vector>
using namespace std;


vector <int>adj[100];
int color[100],prev[100],d[100],f[100],v,u,e,n,time;

void build_graph()
{
    for(int i=0; i<e; i++)
    {
        cout<< "Vertices "<<i+1<< ":";
        cin>>u>>v;
        cout<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS_Visit(int p)
{
    color[p]=1;
    d[p]=++time;
    for(int i=0; i<adj[p].size(); i++)
    {
        v=adj[p][i];
        if(color[v]==0)
        {
            prev[v]=p;
            DFS_Visit(v);
        }
    }
    color[p]=2;
    f[p]=++time;
}
void DFS()
{
    for(int i=0; i<n; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=11122;
        f[i]=11122;
    }
    time=0;
    for(int i=0; i<n; i++)
    {
        if(color[i]==0)
        {
            DFS_Visit(i);
        }
    }
}

void display()
{
    cout<< "Nodes:\n";
    for(int i=0; i<n; i++)
    {
        cout<<i<< " ";
    }
    cout<< "\nColor:\n";
    for(int i=0; i<n; i++)
    {
        cout<<color[i]<< " ";
    }
    cout<< "\nStarting:\n";
    for(int i=0; i<n; i++)
    {
        cout<< d[i]<< " ";
    }
    cout<< "\nFinishing Time:\n";
    for(int i=0;i<n;i++)
    {
        cout<< f[i]<< " ";
    }
    cout<< "\nPrevious:\n";
    for(int i=0; i<n; i++)
    {
        cout<<prev[i]<< " ";
    }

}

int main()
{
    cout<<"Enter the number of node:";
    cin>>n;
    cout<< "Enter the number of edges:";
    cin>>e;
    build_graph();
    DFS();
    display();
}


