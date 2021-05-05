#include<iostream>
#include<limits>
#include<list>
using namespace std;
list <int> adj[100];
list <int>::iterator it;

int color[100],prev[100],d[100],f[100],v,a,b,u,time;

void build_graph()
{
    cout<< "\nInput\n\n";
    int k=1;
    do
    {
        cout<<"Edge "<<k<<":";
        cin>>a>>b;
        if(a==0&&b==0)
        {
            break;
        }
        else if(a<=0||b<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(a>v||b>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            adj[a].push_back(b);
            k++;
        }
    }
    while(1);
}

void DFS_Visit(int u)
{
    color[u]=1;
    d[u]=++time;
    for(list <int>::iterator it=adj[u].begin();it!=adj[u].end();++it)
    {
        if(color[*it]==0)
        {
            prev[*it]=u;
            DFS_Visit(*it);
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
        d[i]=numeric_limits<int>::max();
        f[i]=numeric_limits<int>::max();
    }
    time=0;
    for(int i=1;i<=v;i++)
    {
        if(color[i]==0)
        {
            DFS_Visit(i);
        }
    }
}

void display2()
{
    cout<<"\nDisplay graph data in list form:\n";
    for(int i=1; i<=v; i++)
    {
        cout<< "Adj["<<i<< "]";
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout<< "->"<<*it;
        }
        cout<<"\n";
    }
}

void display()
{
    cout<< "\n\nSample Output:\n";
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
    cout<< "\n\nPrevious : ";
    for(int i=1; i<=v; i++)
    {
        cout<<prev[i]<< " ";
    }
    cout<< "\n\nDiscovering Time : ";
    for(int i=1; i<=v; i++)
    {
        cout<<d[i]<< " ";
    }
    cout<< "\n\nFinishing Time : ";
    for(int i=1;i<=v;i++)
    {
        cout<<f[i]<< " ";
    }
    cout<<"\n";
}

int main()
{
    cout<< "Input number of vertex:";
    cin>>v;
    build_graph();
    DFS();
    display2();
    display();
}

